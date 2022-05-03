#include "dsImage.hpp"
#include <fstream>


//Default constructor
dsImage::dsImage()
{
    m_xSize = 0;
    m_ySize = 0;
    m_pTexture = NULL;
    
}

//The Destructor
dsImage::~dsImage()
{
    if(m_pTexture != NULL)
    {
        SDL_DestroyTexture(m_pTexture);
    }
}

void dsImage::InitTexture()
{
    //Initialize the texture
    Uint32 rmask, gmask, bmask, amask; // <--what does mask do for RGB and alpha?

    //code for compiler... (need to lookup the purpose of these...)
    #if SDL_BYTEORDER == SDL_BIG_ENDIAN
        rmask = 0xff000000;
        gmask = 0x00ff0000;
        bmask = 0x0000ff00;
        amask = 0x000000ff;
	#else
        rmask = 0x000000ff;
        gmask = 0x0000ff00;
        bmask = 0x00ff0000;
        amask = 0xff000000;
	#endif

    //Delete any previously created texture
    if (m_pTexture != NULL)
    {
        SDL_DestroyTexture(m_pTexture);
    }

    //Creat the texture that will store the created image
    SDL_Surface *tempSurface = SDL_CreateRGBSurface(0,m_xSize,m_ySize,32,rmask,gmask,bmask,amask);
    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,tempSurface);
    SDL_FreeSurface(tempSurface);

}

//Function to initialize
void dsImage::Initializer(const int xSize, const int ySize, SDL_Renderer *pRenderer)
{
    //Resizing the image vectors
    m_rChannel.resize(xSize,std::vector<double>(ySize,0.0));
    m_gChannel.resize(xSize,std::vector<double>(ySize,0.0));
    m_bChannel.resize(xSize,std::vector<double>(ySize,0.0));

    //store Dimensions
    m_xSize = xSize;
    m_ySize = ySize;

    //store the pointer to renderer
    m_pRenderer = pRenderer;

    //Initialize the Texture;
    InitTexture();
}

void dsImage::SetPixel(const int x,const int y,const double red,const double green,const double blue)
{
    m_rChannel.at(x).at(y) = red;
    m_gChannel.at(x).at(y) = green;
    m_bChannel.at(x).at(y) = blue;
}

Uint32 dsImage::ConvertColor(const double red,const double green,const double blue)
{
    //Convert the colours to unsigned integers
    unsigned char r = static_cast<unsigned char>(red); // <-- What does this statement doing???
    unsigned char g = static_cast<unsigned char>(green); // <-- What does this statement doing???
    unsigned char b = static_cast<unsigned char>(blue); // <-- What does this statement doing???

    

    //code for compiler...(need to lookup the purpose of these...)
    #if SDL_BYTEORDER == SDL_BIG_ENDIAN
        Uint32 pixelColor = (r << 24) + (g << 16) + (b << 8) + 255; // <- what does this do? (why shifting values)
    #else
        Uint32 pixelColor = (255 << 24) + (r << 16) + (g << 8) + b; // <- what does this do? (why shifting values)
    #endif

    return pixelColor;
}

void dsImage::Display()
{
    //Allocate memory for pixel buffer
    Uint32 *tempPixels  = new Uint32[m_xSize*m_ySize]; // <-- why are we dynamically creating Uint32 object pointer???

    //Reset the pixel buffer(from previous one i suppose)
    memset(tempPixels,0,m_xSize * m_ySize * sizeof(Uint32));

    for(int x=0; x<m_xSize ; ++x)
    {
        for(int y=0; y<m_ySize ; ++y)
        {
            tempPixels[(y * m_ySize) + x] = ConvertColor(m_rChannel.at(x).at(y),m_gChannel.at(x).at(y),m_bChannel.at(x).at(y));
        }
    }

    //Update the texture with pixel Buffer
    SDL_UpdateTexture(m_pTexture,NULL, tempPixels, m_xSize * sizeof(Uint32));

    //Delete the dynamically created pixel buffer (above)
    delete[] tempPixels;

    //Copy the texture to the Renderer
    // [This code segment gonna be useful in defining BVH]
    SDL_Rect srcRect, bounds;
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.h = m_ySize;
    srcRect.w = m_xSize;
    bounds = srcRect;
    SDL_RenderCopy(m_pRenderer,m_pTexture, &srcRect ,&bounds);
}





