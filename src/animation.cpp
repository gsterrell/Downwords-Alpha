//==============================================================================
#include "animation.h"

//==============================================================================
Animation::Animation() {
    currentFrame    = 0;        
    maxFrames       = 0;
    frameInc        = 1;    

    frameRate       = 100; //Milliseconds
    oldTime         = 0;

    oscillate       = false;
}

//------------------------------------------------------------------------------
void Animation::Animate() 
{
    //Sets framerate to one frame a seconde
    if(oldTime + frameRate > SDL_GetTicks()) 
    {
        return;
    }

    oldTime = SDL_GetTicks();

    currentFrame += frameInc;
    
    //If oscillating
    if(oscillate) 
    {
        //If the beginning of the animation,
        if(frameInc > 0) 
        {
            //if the end of the animation,
            if(currentFrame >= maxFrames - 1) 
            {  
                //start decrementing      
                frameInc = -frameInc;
            }
        }
        //If back to the beginnin gof the animation
        else
        {        
            if(currentFrame <= 0) 
            {
                //increment again
                frameInc = -frameInc;
            }
        }
    }
    //If not oscillating, 
    else
    {
        //If we reach the final frame,
        if(currentFrame >= maxFrames - 1) 
        {
            //Set back to the first frame
            currentFrame = 0;
        }
    }
}

//==============================================================================
void Animation::SetFrameRate(int rate) {
    frameRate = rate;
}

//------------------------------------------------------------------------------
void Animation::SetCurrentFrame(int frame) {
    if(frame < 0 || frame >= maxFrames) return;

    currentFrame = frame;
}

//------------------------------------------------------------------------------
int Animation::GetCurrentFrame() {
    return currentFrame;
}

//==============================================================================
