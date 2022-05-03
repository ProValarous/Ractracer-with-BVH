#include<string>
#include<vector>
#include<SDL.h>

class dsImage
{
    private:
        Uint32 ConvertColor(const double red,const double green,const double blue);
        
        void InitTexture();

        //Vectors to store image
        std::vector<std::vector<double>> m_rChannel;
        std::vector<std::vector<double>> m_gChannel;
        std::vector<std::vector<double>> m_bChannel;

        
        int m_xSize, m_ySize; //store the dim of image

        SDL_Renderer *m_pRenderer;  //SDL Render pointer
        SDL_Texture *m_pTexture;    //SDL texture pointer

    public:
        dsImage(); //constructor
        ~dsImage(); //destructor

        //Initialiser
        void Initializer(const int xSize, const int ySize, SDL_Renderer *pRenderer);

        //function to set colour of a pixel
        void SetPixel(const int x,const int y,const double red,const double green,const double blue);

        //function to display Image.
        void Display();


};