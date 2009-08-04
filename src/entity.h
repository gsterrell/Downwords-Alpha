//==============================================================================
#ifndef _ENTITY_H_
    #define _ENTITY_H_

//Header files
//Animation handles the animation and is also needed for rending,
//while graphics handles, well, the graphics.  FPS handles timing
#include <vector>
#include "animation.h"
#include "graphics.h"
#include "FPS.h"

//Sets what kind of entity type is to be used
enum {
	ENTITY_TYPE_GENERIC = 0,

	ENTITY_TYPE_PLAYER,
	
	ENTITY_TYPE_LETTER,
	
	ENTITY_TYPE_LETTERSPACE,
	
	ENTITY_TYPE_GROUND
};

//==============================================================================
//Flags handle what to do with collisions with other entities
enum {
	ENTITY_FLAG_NONE 	= 0,             //Do nothing

	ENTITY_FLAG_GRAVITY	= 0x00000001,    //Gravity applies to this entity
	ENTITY_FLAG_GHOST	= 0x00000002,    //Goes through walls
	ENTITY_FLAG_MAPONLY	= 0x00000004     //Only collides with map, not entities 
};	                                     

//==============================================================================
class Entity {
    public:
        //Vector list of entities
        static std::vector<Entity*>    EntityList;
        
        //********************Constructor & destructor  **********************
		Entity();
		virtual ~Entity();
        //********************************************************************
        
        //*******************  Functions   ***********************************
		virtual bool Load(char* File, int width, int height, int MaxFrames);
        virtual void Loop();    //Handles basic calculations
		virtual void Render(SDL_Surface* surf_display);   //Display graphics
		virtual void Cleanup();   //Basic file cleanup
		virtual void Animate(); //Handles what animation to use when    
		virtual void Collision(Entity* Entity);    //Handles collisions
		void OnMove(float moveX, float moveY);
		void StopMove();
		bool Collides(int oX, int oY, int oW, int oH);
		//********************************************************************
		
		//*********************** Variables  *********************************
        float x;      //Holds horizontal position
        float y;      //Holds vertical position

        int width;  //Sets the width of the image
        int height; //Sets the height of the image

        int animState;  //Current animation state
        
        //Holds max speed        
        float maxSpeedX;
		float maxSpeedY;

        int	type;   //What type of entity
		bool dead;  //Is entity/player dead?
		int	flags;
        //********************************************************************

    protected:
        Animation Anim_Control;

        //Entity image
        SDL_Surface* surf_entity;
        
        //*********************** Variables  *********************************
        //Coordinates
        int	collisionX;
		int	collisionY;
		int	collisionW;
		int	collisionH;
        //Speed of entity		
		float speedX;
		float speedY;

        //Accelation, if any
		float accelX;
		float accelY;
        
        //Current column to animate		
		int	currentFrameCol;
		int	currentFrameRow;

		//********************************************************************
		
	private:
        //When moving, checks if location is valid
        bool PositionValid(int newX, int newY);
        //If tile is valid, then 
        //bool positionValidTile(Tile* Tile);        
        //Checks if a valid entity
    	bool PositionValidEntity(Entity* Entity, int newX, int newY);
};

//==============================================================================
class EntityCollision {
	public:
        //Vectors
		static std::vector<EntityCollision>	EntityCollisionList;
        //Objects
		Entity* EntityA;
		Entity* EntityB;
        //Functioms
		EntityCollision();
};

#endif
