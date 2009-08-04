#include "graphics.h"

Graphics::Graphics()
{}

SDL_Surface* Graphics::Load(char* file)
{
    SDL_Surface* temp = NULL;
    SDL_Surface* return_image = NULL;
    
    if(( temp = IMG_Load(file)) == NULL)
    {
        return NULL;
    }
    
    return_image = SDL_DisplayFormatAlpha(temp);
    SDL_FreeSurface(temp);
    
    //Color key surface
    //SDL_SetColorKey( return_image, SDL_SRCCOLORKEY, SDL_MapRGB( return_image->format, 255, 255, 255 ) );
        
    
    return return_image;
}

bool Graphics::Draw(SDL_Surface* destination, SDL_Surface* source, int x, int y, SDL_Rect *clip = NULL)
{
    if(destination == NULL || source == NULL)
    {
        return false;
    }
    
    SDL_Rect destRect;
    
    destRect.x = x;
    destRect.y = y;
    
    SDL_BlitSurface(source, clip, destination, &destRect);

    return true;
}

bool Graphics::Draw(SDL_Surface* destination, SDL_Surface* source, int x, int y, int x2, int y2, int w, int h) 
{
    if(destination == NULL || source == NULL) 
    {
        return false;
    }

    SDL_Rect destRect;

    destRect.x = x;
    destRect.y = y;
    
    SDL_Rect sourceRect;

    sourceRect.x = x2;
    sourceRect.y = y2;
    sourceRect.w = w;
    sourceRect.h = h;

    SDL_BlitSurface(source, &sourceRect, destination, &destRect);

    return true;
}

bool Graphics::Transparent(SDL_Surface* Surf_Dest, int R, int G, int B) {
    if(Surf_Dest == NULL) {
        return false;
    }

    SDL_SetColorKey(Surf_Dest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Surf_Dest->format, R, G, B));

    return true;
}
