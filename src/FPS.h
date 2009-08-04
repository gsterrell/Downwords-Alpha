//==============================================================================
// FPS Class
//==============================================================================
#ifndef _FPS_H_
    #define _FPS_H_

#include <SDL.h>

//==============================================================================
class FPS {
	private:
		int oldTime;
		int lastTime;

		float speedFactor;

		int	numFrames;
		int frames;

	public:
		FPS();

		void OnLoop();

		int GetFPS();

		float GetSpeedFactor();
		
		static FPS FPSControl;

};

//==============================================================================
#endif
