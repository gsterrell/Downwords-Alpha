//=============================================================================
#include "FPS.h"

//=============================================================================
FPS FPS::FPSControl;

//=============================================================================
FPS::FPS() {
	oldTime     = 0;
	lastTime    = 0;

	speedFactor	= 0;

	frames      = 0;
	numFrames   = 0;
}

//=============================================================================
void FPS::OnLoop() 
{
    //If a second has passed since last time,
	if(oldTime + 1000 < SDL_GetTicks()) 
    {
        //oldTime is now the current time
		oldTime = SDL_GetTicks();

        //Set the number of frames to whater frames was
		numFrames = frames;

        //reset frames
		frames = 0;
	}

    //speedFactor: the speed appropriate for whatever system it is on
	speedFactor = ((SDL_GetTicks() - lastTime) / 1000.0f) * 32.0f;

	lastTime = SDL_GetTicks();

	frames++;
}

//=============================================================================
int FPS::GetFPS() 
{
    return numFrames;
}

//------------------------------------------------------------------------------
float FPS::GetSpeedFactor() 
{
    return speedFactor;
}

//==============================================================================
