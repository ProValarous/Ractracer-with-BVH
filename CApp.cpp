#include "CApp.hpp"


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
        pWindow = SDL_CreateWindow("Epic DS2 Project",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1288,720,SDL_WINDOW_SHOWN);
    }
    if (pWindow != NULL)
    {
        pRenderer = SDL_CreateRenderer(pWindow,-1,0);
    }
    else
    {
        return false;
    }
    return true;
}

int CApp::OnExecute()
{
    //Some code
}

void CApp::OnEvent(SDL_Event *event)
{
    //code
}

void CApp::OnLoop()
{
    //code
}

void CApp::OnRender()
{
    //In-Render code
}

void CApp::OnExit()
{
    //exit code
}