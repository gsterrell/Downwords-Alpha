//==============================================================================
// Game class.  Controls most game functions
//==============================================================================
#ifndef _GAME_H_
    #define _GAME_H_

#include <SDL.h>

#include "graphics.h"
#include "event.h"
#include "entity.h"
#include "constants.h"
#include "letter.h"
#include "letterspace.h"

//==============================================================================
class Game : public Event {
    private:
        //Checks to see if the game is still running
        bool Running;

        //All the surfaces that do not need to be interacted with
        SDL_Surface* surf_display;
        SDL_Surface* background1;
        SDL_Surface* surf_clock;
        SDL_Surface* surf_number;
        
        //Letters for testing
        Letter letter1;
        Letter letter2;
        
        //Array of letterspaces
        Letterspace letterspace[20];
    public:
        //Constructor sets surfaces to NULL and set Running to true
        Game();

        //Calls all of the other game function. 
        int Execute();

        //Initializes all surfaces and variables necessary for level
        bool Init();

        //Handles events.  Doesn't do much right now.
        void WhenEvent(SDL_Event* Event);

        //Not being used.  Keeping for reference.
       	void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
       	void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
       	
       	void LButtonDown(int mX, int mY);

		void LButtonUp(int mX, int mY);


        //Sets Running to false, but doesn't exit the game by itself
        void Exit();

        //Handles the main loop, where most events take place
        void Loop();

        //Displays everything on the screen
        void Render();

        //Calls SDL_Quit and cleans up surfaces
        void Cleanup();
};

//==============================================================================

#endif
