//==============================================================================
// Animation Class
//==============================================================================
#ifndef _ANIMATION_H_
    #define _ANIMATION_H_

#include <SDL.h>

//==============================================================================
class Animation {
	public:
        //Functions
		Animation();

		void Animate();
        
        //Functions
        void SetFrameRate(int Rate);

		void SetCurrentFrame(int Frame);

		int GetCurrentFrame();
		
		//Variables
        int	maxFrames;

		bool oscillate;
    
    private:
        //Variables       
		int currentFrame;

		int frameInc;
		
		//Variables
        int frameRate; //Milliseconds

		long oldTime;
};

//==============================================================================

#endif
