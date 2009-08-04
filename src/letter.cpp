#include "letter.h"

Letter::Letter() 
{
    //X/Y coordinates set to zero, just to be generic
    x = y = 0;

    //Default height & width of zero
    width = height = 0;

    //Default entity type
    type = ENTITY_TYPE_LETTER;
    
    //Default entity, can't die until it has lived
    dead = false;

    //Gravity by default.  
    flags = ENTITY_FLAG_NONE;
    
    //Speed of entity
    speedX = 0;
    speedY = 2;
    
    //Acceleration per loop
    accelX = 0;
    accelY = 0;
    
    //Maximum speed entity can reach
    maxSpeedX = 2;
    maxSpeedY = 2;
    
    //Default animation frame column & row
    currentFrameCol = 0;
    currentFrameRow = 0;
}

//=============================================================================
bool Letter::Load(char* file, int width, int height, int maxFrames) 
{
    if(Entity::Load(file, width, height, maxFrames) == false) 
    {
        return false;
    }

    return true;
}

//-----------------------------------------------------------------------------
void Letter::Loop() 
{   
	Entity::Loop();
}

//-----------------------------------------------------------------------------
void Letter::Render(SDL_Surface* surf_display) 
{
	Entity::Render(surf_display);
}

//------------------------------------------------------------------------------
void Letter::Cleanup() 
{
	Entity::Cleanup();
}

//------------------------------------------------------------------------------
void Letter::Animate() 
{
	if(speedX != 0) 
    {
		Anim_Control.maxFrames = 1;
	}
    else
    {
		Anim_Control.maxFrames = 0;
	}

	Entity::Animate();
}

//------------------------------------------------------------------------------
void Letter::Collision(Entity* Entity) 
{}

//=============================================================================

void Letter::SetLetters()
{}
//=============================================================================
void Letter::OnClick()
{
    
}

//=============================================================================
void Letter::SetXY( int setX, int setY)
{
    x = setX;
    y = setY;    
}
//==============================================================================

void Letter::SetSpeed( float setSpeedX, float setSpeedY)
{
    speedX = setSpeedX;
    speedY = setSpeedY;    
}
    
