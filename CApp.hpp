#include <SDL.h>
#include "./dsImage.hpp"

class CApp
{
    private:
        // SDL2 state operations
        bool isRunning;
        SDL_Window *pWindow;
        SDL_Renderer *pRenderer;

        //Making an instance of a class dsImage to store image
        dsImage m_image;


    public:
        CApp();

        bool OnInit();
        int OnExecute();
        void OnEvent(SDL_Event *event);
        void OnLoop();
        void OnRender();
        void OnExit();
        
    



};