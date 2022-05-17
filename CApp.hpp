
#ifndef CAPP_H
#define CAPP_H

#include <SDL2/SDL.h>
#include "./dsImage.hpp"
#include "./scene.hpp"
#include "./camera.hpp"

class CApp
{
	public:
		CApp();
		
		int OnExecute();
		bool OnInit();
		void OnEvent(SDL_Event *event);
		void OnLoop();
		void OnRender();
		void OnExit();
		
	private:
		void PrintVector(const qbVector<double> &inputVector);
		
	private:
		// An instance of the qbImage class to store the image.
		dsImage m_image;
		
		// An instance of the scene class.
		dsRT::Scene m_scene;
		
		// SDL2 stuff.
		bool isRunning;
		SDL_Window *pWindow;
		SDL_Renderer *pRenderer;
		
};

#endif






// #pragma once
// #include <SDL.h>
// #include "./dsImage.hpp"
// #include "./scene.hpp"
// #include "ray.hpp"
// #include "./camera.hpp"

// class CApp
// {
//     private:
//         // SDL2 state operations
//         bool isRunning;
//         SDL_Window *pWindow;
//         SDL_Renderer *pRenderer;

//         //Making an instance of a class dsImage to store image
//         dsImage m_image;

//         //Create an instance of the scene
//         dsRT::Scene m_scene;

//         void PrintVector(const qbVector<double> &inputVector);


//     public:
//         CApp();

//         bool OnInit();
//         int OnExecute();
//         void OnEvent(SDL_Event *event);
//         void OnLoop();
//         void OnRender();
//         void OnExit();

// };