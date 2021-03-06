#include "constants.h"
//#include "letter.h"
#include "functions.h"
#include "globals.h"
#include "timer.h"
#include "level.h"
#include "sprite.h"

bool level_init()
{
    //Load the letter image
    letterSheet = load_image("../media/a.png");
    
    letterspaceSheet = load_image("../media/letter_place.png");
    
    spriteSheet = load_image("../media/a.png");
    
    //Load the first background image
    background1 = load_image("../media/background.png");
    
    if( background1 == NULL )
    {
        return false;    
    }
    
    //If everything loaded fine
    return true;    
}

//loads level files
bool level_files()
{
    apply_surface(0, 0, background1, screen, NULL );
}

//Ends the level by freeing the surfaces
void level_end()
{
    //Free the surface
    SDL_FreeSurface( letterSheet ); 
    SDL_FreeSurface( background1 );
    SDL_FreeSurface( letterspaceSheet );
    SDL_FreeSurface( spriteSheet );
}
