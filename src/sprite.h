#ifndef SPRITE_H
#define SPRITE_H

//Sprite header file.
//Sprite class will handle collision detection and image loading.
//Handling what "letter" and some of what "functions" does now.  Yay!

#include "SDL/SDL.h"
//#include "functions.h"

class Sprite
{
    public:
        Sprite( int, int, int, int, int);
        
        //Initializes images
        void load_sprite(char *);
        
        //Takes key presses and adjusts the sprites velocity
        void input();
    
        //Moves the sprite
        void move();
    
        //Shows the sprite on the screen
        void show();
        
        //Returns the x, y, z coordinates for collision detection & placement,
        //and returns the width and height of the objects.
        int getSpriteX();
        int getSpriteY();
        int getSpriteZ();
        int getSpriteW();
        int getSpriteH();
        
        //Sets the x, y, z coordinates for collision & placement,
        //as well as the width and height of the object.
        void setSpriteX( int );
        void setSpriteY( int );
        void setSpriteZ( int );
        void setSpriteW( int );
        void setSpriteH( int );
        
        //Destructor
        ~Sprite();
       
    private:
        int x;
        int y;
        int z;
        int w;
        int h;
        //SDL_Surface *spriteSheet;
        SDL_Rect *spriteRect;
        SDL_Rect spriteBox;
        bool clicked;
        int xVel;
        int yVel;
};

#endif
