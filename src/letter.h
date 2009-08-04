#ifndef LETTER_H
#define LETTER_H

#include "entity.h"

class Letter: public Entity
{
    public:
        Letter();

        bool Load(char* file, int width, int height, int maxFrames);

        void Loop();

        void Render(SDL_Surface* surf_display);

        void Cleanup();

        void Animate();

        void Collision(Entity* Entity);        
        
        void SetLetters();
        
        void OnClick();
        
        void SetXY( int setX, int setY);
        
        void SetSpeed( float setSpeedX, float setSpeedY);
    
    private:
        //Checks whether the letter has been clicked
        bool clicked;
        
        unsigned randomLetter;
        
        enum ALPHABET 
        {
            A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z
        };
    
};

#endif
