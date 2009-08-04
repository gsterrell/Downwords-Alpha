//==============================================================================
#include "game.h"    
#include "FPS.h"

//==============================================================================
Game::Game() {
    //Set static, non-interactive images
    surf_display = NULL;
    background1 = NULL;
    surf_clock = NULL;
    surf_number = NULL;

    Running = true;
}

//------------------------------------------------------------------------------
int Game::Execute() {
    if(Init() == false) {
        return -1;
    }

    SDL_Event Event;

    while(Running) {
        while(SDL_PollEvent(&Event)) {
            WhenEvent(&Event);
        }

        Loop();
        Render();
    }

    Cleanup();

    return 0;
}
//==============================================================================
bool Game::Init() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if((surf_display = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }
    
    //Entity 1
    if(letter1.Load("../media/a.png", 40, 40, 1) == false) 
    {
        return false;
    }
    
    //Entity 2
    if(letter2.Load("../media/ab.png", 80, 40, 1) == false) 
    {
        return false;
    }
    for( int i = 0; i < 20; i++)
    {
        if(letterspace[i].Load("../media/letter_place.png", 40, 40, 1) == false)
        {
            return false;
        }
    }
    //Move the entity so that they don't overlap
    letter1.x = 200;
    
    letter2.SetXY(200, 200);
    
    for( int i= 0; i < 20; i++)
    {
        if( i < 4)
            letterspace[i].x = ((50 * i) + 660);
        else if( i >= 4 && i < 8)
            letterspace[i].x = ((50 * (i - 4)) + 660);
        else if( i >= 8 && i < 12)
            letterspace[i].x = ((50 * (i - 8)) + 660);
        else if( i >= 12 && i < 16)
            letterspace[i].x = ((50 * (i - 12)) + 660);
        else if( i >= 16 && i < 20)
            letterspace[i].x = ((50 * (i - 16)) + 660);
    }    
    
    for( int i = 0; i < 20; i++)
    {
        if( i < 4)
            letterspace[i].y = 60;
        else if( i >= 4 && i < 8)
            letterspace[i].y = 140;
        else if( i >= 8 && i < 12)
            letterspace[i].y = 220;
        else if( i >= 12 && i < 16)
            letterspace[i].y = 300;
        else if( i >= 16 && i < 20)
            letterspace[i].y = 380;
    }
    
    //push the entities into the queue
    Entity::EntityList.push_back(&letter1);
    Entity::EntityList.push_back(&letter2);
    for( int k = 0; k < 20; k++)
    {
        Entity::EntityList.push_back(&letterspace[k]);
    }
    //if(letter1.Load("../media/a.png", 40, 40, 1) == false)
    //{
      //  return false;
    //}
    
    //Load the first background image
    background1 = Graphics::Load("../media/Backgroundsmall2.jpg");
    
    //Load the clock
    surf_clock = Graphics::Load("../media/Clock4.png");
    
    //Load some numbers
    surf_number = Graphics::Load("../media/01.png");
    
    //Check to make sure that the background & clock loaded correctly
    if( background1 == NULL || surf_clock == NULL )
    {
        return false;    
    }

    //If everything is good, return true
    return true;
}


//==============================================================================
//Handles events.  Not much going on with it right now.
void Game::WhenEvent(SDL_Event* Event) {
    Event::WhenEvent(Event);
}

//==============================================================================
void Game::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) {
		//case SDLK_LEFT: {
		//	Player.MoveLeft = true;
			//break;
		//}

		//case SDLK_RIGHT: {
		//	Player.MoveRight = true;
			//break;
		//}

		default: {
		}
	}
}

void Game::LButtonDown(int mX, int mY)
{
  //  SDL_Event event;
    
    //int x = event.button.x;
    //int y = event.button.y;
    
  //  for(int i = 0;i < EntityList.size();i++) 
    //{
	//	if(PositionValidEntity(EntityList[i], x, y) == false) 
        //{
			//Return = false;
		//}
	//}
}

void Game::LButtonUp(int mX, int mY)
{}

//------------------------------------------------------------------------------
void Game::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) {
		//case SDLK_LEFT: {
		//	Player.MoveLeft = false;
			//break;
		//}

		//case SDLK_RIGHT: {
		//	Player.MoveRight = false;
			//break;
		//}

		default: {
		}
	}
}

//------------------------------------------------------------------------------
void Game::Exit() {
	Running = false;
}

//==============================================================================
void Game::Loop() {
    //--------------------------------------------------------------------------
    // Entities
    //--------------------------------------------------------------------------
    for(int i = 0;i < Entity::EntityList.size();i++) {
        if(!Entity::EntityList[i]) 
            continue;
        Entity::EntityList[i]->Loop();
    }

    FPS::FPSControl.OnLoop();

    SDL_WM_SetCaption("Downwards", "Downwards");
}

//==============================================================================
void Game::Render() {
	//SDL_Rect Rect;
	//Rect.x = 0;
	//Rect.y = 0;
	//Rect.w = WWIDTH;
	//Rect.h = WHEIGHT;

	//SDL_FillRect(surf_display, &Rect, 0);
	
	Graphics::Draw(surf_display, background1, 0, 0, NULL);
    Graphics::Draw(surf_display, surf_clock, 380, 0, NULL);
    Graphics::Draw(surf_display, surf_number, 415, 55, NULL);

    //--------------------------------------------------------------------------
    // Entities
    //--------------------------------------------------------------------------
    for(int i = 0;i < Entity::EntityList.size();i++) {
        if(!Entity::EntityList[i]) continue;

        Entity::EntityList[i]->Render(surf_display);
    }

	SDL_Flip(surf_display);
}

//==============================================================================
void Game::Cleanup() {
	
    //--------------------------------------------------------------------------
    // Entities
    //--------------------------------------------------------------------------
    for(int i = 0;i < Entity::EntityList.size();i++) {
        if(!Entity::EntityList[i]) continue;

        Entity::EntityList[i]->Cleanup();
    }

    Entity::EntityList.clear();

    //Free the surface
    SDL_FreeSurface( background1 );
    SDL_FreeSurface( surf_clock );
    SDL_FreeSurface( surf_display );
    SDL_FreeSurface( surf_number );
    SDL_Quit();
}

//==============================================================================
