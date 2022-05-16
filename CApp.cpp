
#include "CApp.hpp"
#include "./qbLinAlg/qbVector.h"

// The constructor (default)
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
	
	pWindow = SDL_CreateWindow("Rays do be tracing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
	
	if (pWindow != NULL)
	{
		pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
		
		// Intialize the qbImage instance.
		m_image.Initialize(1280, 720, pRenderer);
		
		// Set the background color to white.
		SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
		SDL_RenderClear(pRenderer);
		
		// Render the scene.
		m_scene.Render(m_image);
		
		// Display the image.
		m_image.Display();
		
		// Show the result.
		SDL_RenderPresent(pRenderer);
		
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
	
	if (OnInit() == false)
	{
		return -1;
	}
	
	while (isRunning)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			OnEvent(&event);
		}
		
		OnLoop();
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

}

void CApp::OnRender()
{
	// Set the background color to white.
	//SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
	//SDL_RenderClear(pRenderer);
	
	// Render the scene.
	//m_scene.Render(m_image);
	
	// Display the image.
	//m_image.Display();
	
	// Show the result.
	//SDL_RenderPresent(pRenderer);
}

void CApp::OnExit()
{
	// Tidy up SDL2 stuff.
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	pWindow = NULL;
	SDL_Quit();
}

// PRIVATE FUNCTIONS.
void CApp::PrintVector(const qbVector<double> &inputVector)
{
	int nRows = inputVector.GetNumDims();
	for (int row=0; row<nRows; ++row)
	{
		std::cout << std::fixed << std::setprecision(3) << inputVector.GetElement(row) << std::endl;
	}
}












// #include "CApp.hpp"
// #include <iostream>
// #include <cmath>
// #include "./qbLinAlg/qbVector.h"

// CApp::CApp()
// {
//     isRunning = true;
//     pWindow = NULL;
//     pRenderer = NULL;
// }

// bool CApp::OnInit()
// {
//     if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
//     {
//         return false;
//     }
//     else
//     {
//         pWindow = SDL_CreateWindow("Epic DS2 Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
//     }
//     if (pWindow != NULL)
//     {

//         pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
		
// 		// Intialize the qbImage instance.
// 		m_image.Initialize(1280, 720, pRenderer);
		
// 		// Set the background color to white.
// 		SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
// 		SDL_RenderClear(pRenderer);
		
// 		// Render the scene.
// 		m_scene.Render(m_image);
		
// 		// Display the image.
// 		m_image.Display();
		
// 		// Show the result.
// 		SDL_RenderPresent(pRenderer);

//         // pRenderer = SDL_CreateRenderer(pWindow, -1, 0);

//         // // Intialize the dsImage Instance
//         // m_image.Initializer(400, 400, pRenderer);


//         // // Test the camera class.
// 		// dsRT::Camera testCamera;
// 		// testCamera.SetPosition(qbVector<double>(std::vector<double>{0.0, 0.0, 0.0}));
// 		// testCamera.set_look_at(qbVector<double>(std::vector<double>{0.0, 2.0, 0.0}));
// 		// testCamera.Setup(qbVector<double>(std::vector<double>{0.0, 0.0, 1.0}));
// 		// testCamera.SetLength(1.0);
// 		// testCamera.SetHorizontalSize(1.0);
// 		// testCamera.set_aspect_ratio(1.0);
// 		// testCamera.UpdateCameraGeometry();
		
// 		// // Get the screen centre and U,V vectors and display.
// 		// auto screenCentre = testCamera.GetScreenCenter();
// 		// auto screenU = testCamera.GetU();
// 		// auto screenV = testCamera.GetV();
		
// 		// // And display to the terminal.
// 		// std::cout << "Camera screen centre:" << std::endl;
// 		// PrintVector(screenCentre);
// 		// std::cout << "\nCamera U vector:" << std::endl;
// 		// PrintVector(screenU);
// 		// std::cout << "\nCamera V vector:" << std::endl;
// 		// PrintVector(screenV);

//         // //!!!---Some fun colour testing---!!!
//         // for (int x=0; x < 400 ; ++x)
//         // {
//         //     for (int y=0; y < 400 ; ++y)
//         //     {
//         //         double red = (static_cast<double>(x)/400.0) * 255.0;
//         //         double green = (static_cast<double>(y)/400.0) * 255.0;
//         //         double blue = (static_cast<double>(10*sin(x+y))/400.0) * 255.0;
//         //         m_image.SetPixel(x,y,red,green,blue);
//         //     }
//         // }
//     }
//     else
//     {
//         return false;
//     }
//     return true;
// }

// int CApp::OnExecute()
// {
//     SDL_Event event;

//     if (OnInit() == false)
//     {
//         return -1;
//     }

//     while (isRunning)
//     {
//         while (SDL_PollEvent(&event) != 0)
//         {
//             OnEvent(&event);
//         }
//         // OnLoop();
//         OnRender();
//     }
// }

// void CApp::OnEvent(SDL_Event *event)
// {
//     if (event->type == SDL_QUIT)
//     {
//         isRunning = false;
//     }
// }

// void CApp::OnLoop()
// {
//     // code
// }

// void CApp::OnRender()
// {
//     // // Set bkground colour to white
//     // SDL_SetRenderDrawColor(pRenderer, 255, 0, 255, 255);
//     // SDL_RenderClear(pRenderer);

//     // // Render the scene
//     // m_scene.Render(m_image);

//     // // Display the image
//     // m_image.Display();

//     // // Show the results
//     // SDL_RenderPresent(pRenderer);
// }

// void CApp::OnExit()
// {
//     // exit code
//     SDL_DestroyRenderer(pRenderer);
//     SDL_DestroyWindow(pWindow);
//     pWindow = NULL;
//     SDL_Quit();
// }

// void CApp::PrintVector(const qbVector<double> &inputVector)
// {
//     int nRows = inputVector.GetNumDims();
//     for (int row = 0; row < nRows; ++row)
//     {
//         std::cout << std::fixed << std::setprecision(3) << inputVector.GetElement(row) << std::endl;
//     }
// }