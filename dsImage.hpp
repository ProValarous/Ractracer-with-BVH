


#ifndef QBIMAGE_H
#define QBIMAGE_H

#include <string>
#include <vector>
#include <SDL2/SDL.h>

class dsImage
{
	public:
		// The constructor.
		dsImage();
	
		// The destructor.
		~dsImage();
	
		// Function to initialise.
		void Initialize(const int xSize, const int ySize, SDL_Renderer *pRenderer);
		
		// Function to set the colour of a pixel.
		void SetPixel(const int x, const int y, const double red, const double green, const double blue);
		
		// Function to return the image for display.
		void Display();
		
		// Functions to return the dimensions of the image.
		int GetXSize();
		int GetYSize();
	
	private:
		Uint32 ConvertColor(const double red, const double green, const double blue);
		void InitTexture();
		
	private:
		// Arrays to store image data.
		std::vector<std::vector<double>> m_rChannel;
		std::vector<std::vector<double>> m_gChannel;
		std::vector<std::vector<double>> m_bChannel;
		
		// Store the dimensions of the image.
		int m_xSize, m_ySize;
		
		// SDL2 stuff.
		SDL_Renderer *m_pRenderer;
		SDL_Texture *m_pTexture;

};

#endif



// #pragma once
// #include<string>
// #include<vector>
// #include<SDL.h>

// class dsImage
// {
//     private:
//         Uint32 ConvertColor(const double red,const double green,const double blue);
        
//         void InitTexture();

//         //Vectors to store image
//         std::vector<std::vector<double>> m_rChannel;
//         std::vector<std::vector<double>> m_gChannel;
//         std::vector<std::vector<double>> m_bChannel;

        
//         int m_xSize, m_ySize; //store the dim of image

//         SDL_Renderer *m_pRenderer;  //SDL Render pointer
//         SDL_Texture *m_pTexture;    //SDL texture pointer

//     public:
//         dsImage(); //constructor
//         ~dsImage(); //destructor

//         //Initialiser
//         void Initializer(const int xSize, const int ySize, SDL_Renderer *pRenderer);

//         //function to set colour of a pixel
//         void SetPixel(const int x,const int y,const double red,const double green,const double blue);

//         //function to display Image.
//         void Display();

//         // Function to retutn dimension
//         int GetxSize();
//         int GetySize();


// };