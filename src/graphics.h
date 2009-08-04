//The graphics class.  Currently undergoing testing.
//If testing goes well it will replace functions.h and functions.cpp
//Handles the loading and displaying of images
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <SDL_image.h>

class Graphics
{
    public:
        //Main constructor.  Takes no parameters
        Graphics();
        
        //Takes an image and loads it.
        //It also optimizes the image for faster screen processing.
        static SDL_Surface* Load(char* file);
        
        //Draws an image on the screen, but does not use sprite clipping.
        static bool Draw(SDL_Surface* destination, SDL_Surface* source, int x, int y, SDL_Rect *clip);
        
        //Draws an image on the screen, and does include sprite clipping.
        static bool Draw(SDL_Surface* destination, SDL_Surface* source, int x, int y, int x2, int y2, int w, int h);

        //Makes background transparent.  May merge with Load_Image
        static bool Transparent(SDL_Surface* Surf_Dest, int R, int G, int B);
};    

#endif
