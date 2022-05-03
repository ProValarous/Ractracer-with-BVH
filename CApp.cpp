#include "CApp.hpp"
#include <iostream>
#include<cmath>

CApp::CApp()
{
    isRunning = true;
    pWindow = NULL;
    pRenderer = NULL;
}

bool CApp::OnInit()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }
    else
    {
        pWindow = SDL_CreateWindow("Epic DS2 Project",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,400,400,SDL_WINDOW_SHOWN);
    }
    if (pWindow != NULL)
    {
        pRenderer = SDL_CreateRenderer(pWindow,-1,0);

        //Intialize the dsImage Instance
        m_image.Initializer(400,400,pRenderer);

        
        //!!!---Some fun colour testing---!!!
        for (int x=0; x < 400 ; ++x)
        {
            for (int y=0; y < 400 ; ++y)
            {
                double red = (static_cast<double>(x)/400.0) * 255.0;
                double green = (static_cast<double>(y)/400.0) * 255.0;
                double blue = (static_cast<double>(10*sin(x+y))/400.0) * 255.0;
                m_image.SetPixel(x,y,red,green,blue);  
            }
        }



    }
    else
    {
        return false;
    }
    return true;
}

int CApp::OnExecute()
{
    SDL_Event event;

    if (OnInit()==false)
    {
        return -1;
    }

    while (isRunning)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            OnEvent(&event);
        }
        //OnLoop();
        OnRender();
    }    
}

void CApp::OnEvent(SDL_Event *event)
{
    if (event->type == SDL_QUIT)
    {
        isRunning = false;
    }
}

void CApp::OnLoop()
{
    //code
}

void CApp::OnRender()
{
    //Set bkground colour to white
    SDL_SetRenderDrawColor(pRenderer,255,0,255,255);
    SDL_RenderClear(pRenderer);

    
    //Display the image
    m_image.Display();

    //Show the results
    SDL_RenderPresent(pRenderer);

}

void CApp::OnExit()
{
    //exit code
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    pWindow = NULL;
    SDL_Quit();
}