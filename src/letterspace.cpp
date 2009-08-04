#include "letterspace.h"

Letterspace::Letterspace() 
{
    type = ENTITY_TYPE_LETTERSPACE;
    
    flags = ENTITY_FLAG_NONE;    
}

//=============================================================================
bool Letterspace::Load(char* file, int width, int height, int maxFrames) 
{
    if(Entity::Load(file, width, height, maxFrames) == false) 
    {
        return false;
    }

    return true;
}

//-----------------------------------------------------------------------------
void Letterspace::Loop() 
{   
	Entity::Loop();
}

//-----------------------------------------------------------------------------
void Letterspace::Render(SDL_Surface* surf_display) 
{
	Entity::Render(surf_display);
}

//------------------------------------------------------------------------------
void Letterspace::Cleanup() 
{
	Entity::Cleanup();
}

//------------------------------------------------------------------------------
void Letterspace::Animate() 
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
void Letterspace::Collision(Entity* Entity) 
{}

//=============================================================================
