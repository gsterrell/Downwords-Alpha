#ifndef LETTERSPACE_H
#define LETTERSPACE_H

#include "entity.h"
class Letterspace: public Entity
{
    public:
        Letterspace();

        bool Load(char* file, int width, int height, int maxFrames);

        void Loop();

        void Render(SDL_Surface* surf_display);

        void Cleanup();

        void Animate();

        void Collision(Entity* Entity);        
};

#endif
