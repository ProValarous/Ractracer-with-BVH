#include <SDL.h>

class CApp
{
    private:
    // SDL2 state operations
        bool isRunning;
        SDL_Window *pWindow;
        SDL_Renderer *pRenderer;

    public:
        CApp();

        bool OnInit();
        int OnExecute();
        void OnEvent(SDL_Event *event);
        void OnLoop();
        void OnRender();
        void OnExit();
        
    



};