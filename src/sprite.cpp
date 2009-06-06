#include "sprite.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "functions.h"
#include "C:\Documents and Settings\Watari\downwords alpha\src\globals.h"
#include "constants.h"
//#include "letterspace.h"

//SDL_Surface *spriteSheet = NULL;
SDL_Rect *spriteRect = NULL;
SDL_Rect spriteBox;

Sprite::Sprite( int sprX, int sprY, int sprZ, int sprW, int sprH)
{
    x = sprX;
    y = sprY;
    z = sprZ;
    w = sprW;
    h = sprH;
    
    xVel = 0;
    yVel = 3;
}

//Initializes all aspects of "Sprite"
void Sprite::load_sprite(char *filename)
{
    //spriteSheet = load_image(filename);
}

//Takes key presses and adjusts the sprites velocity
void Sprite::input()
{
    //The mouse offsets 
    int x = 0, y = 0; 
    
    //If the mouse is being moved 
    if( event.type == SDL_MOUSEMOTION )
    {
        x = event.motion.x;
        y = event.motion.y;
        
        if (clicked == true)
        { 
            spriteBox.x = x;
            spriteBox.y = y;
            yVel = 0;
            
            if (event.motion.x > (SCREEN_WIDTH - LETTER_WIDTH))
            {
                //move back
                spriteBox.x = SCREEN_WIDTH - LETTER_WIDTH;        
            }
            if (event.motion.y > (SCREEN_HEIGHT - LETTER_HEIGHT))
            {
                //move back
                spriteBox.y = SCREEN_HEIGHT - LETTER_HEIGHT;  
            }
        }
    }
    
     //If a mouse button was pressed 
    if( event.type == SDL_MOUSEBUTTONDOWN ) 
    { 
        //If the left mouse button was pressed 
        if( event.button.button == SDL_BUTTON_LEFT ) 
        { 
            //Get the mouse offsets 
            x = event.button.x; 
            y = event.button.y; 
            
            //If the mouse is over the button 
            if( ( x > spriteBox.x ) && ( x < spriteBox.x + spriteBox.w ) && ( y > spriteBox.y ) && ( y < spriteBox.y + spriteBox.h ) ) 
            {   
                clicked = true;
            } 
        } 
    } 
    
    //If a mouse button was released 
    if( event.type == SDL_MOUSEBUTTONUP ) 
    { 
        //If the left mouse button was released 
        if( event.button.button == SDL_BUTTON_LEFT ) 
        { 
            //Get the mouse offsets 
            x = event.button.x; 
            y = event.button.y;
            
            clicked = false;
            yVel = 2;
        }
/*        
        //If the mouse is over the button 
        if( ( spriteBox.x > letterspaceBox.x ) && ( spriteBox.x < letterspaceBox.x + letterspaceBox.w ) && ( spriteBox.y > letterspaceBox.y ) && ( spriteBox.y < letterspaceBox.y + letterspaceBox.h ) ) 
        {   
            spriteBox.x = (letterspaceBox.x - 10);
            spriteBox.y = (letterspaceBox.y - 10);
            yVel = 0;
        }
        //If the letter is over a letterspace, cover the letterspace.
        //This will handled by the "Sprite" class in the near future.
        if( ( spriteBox.x < letterspaceBox.x ) && ( spriteBox.x + spriteBox.w > letterspaceBox.x ) && ( spriteBox.y < letterspaceBox.y ) && ( spriteBox.y + spriteBox.h > letterspaceBox.y ))
        {   
            //Cover the letterspace with the letter
            spriteBox.x = (letterspaceBox.x - 10);
            spriteBox.y = (letterspaceBox.y - 10);
            yVel = 0;
        }
*/
    }
}

//Moves the sprite
void Sprite::move()
{
    //Move the letter left or right
    spriteBox.x += xVel;
    
    //If the letter went too far to the left or right
    if( ( spriteBox.x < 0 ) || ( spriteBox.x + LETTER_WIDTH > SCREEN_WIDTH ) )
    {
        //move back
        spriteBox.x -= xVel;    
    }
    
    //Move the letter up or down
    spriteBox.y += yVel;
    
    //If the letter went too far up or down
    if( ( spriteBox.y < 0 ) || ( spriteBox.y + LETTER_HEIGHT > SCREEN_HEIGHT ) )
    {
        //move back
        spriteBox.y -= yVel;  
    }
}    

//Shows the sprite on the screen
void Sprite::show()
{
    //Show the letter
    apply_surface( spriteBox.x, spriteBox.y, spriteSheet, screen, NULL);
}

//Returns the x value, mostly to be used by other classes for collision 
//detection.
int Sprite::getSpriteX()
{
    return x;
}

int Sprite::getSpriteY()
{
    return y;
}

int Sprite::getSpriteZ()
{
    return z;
}

int Sprite::getSpriteW()
{
    return w;
}

int Sprite::getSpriteH()
{
    return h;
}

//Sets the x, y, z coordinates for collision & placement,
//as well as the width and height of the object.
void Sprite::setSpriteX( int setX)
{
    x = setX;    
}

void Sprite::setSpriteY( int setY)
{
    y = setY;
}

void Sprite::setSpriteZ( int setZ)
{
    z = setZ;
}

void Sprite::setSpriteW( int setW)
{
    w = setW;
}

void Sprite::setSpriteH( int setH)
{
    h = setH;
}
    
//Destructor
Sprite::~Sprite()
{    
    SDL_FreeSurface( spriteSheet );
}
