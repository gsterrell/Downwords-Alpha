//==============================================================================
#include "entity.h"

//==============================================================================
std::vector<Entity*> Entity::EntityList;

std::vector<EntityCollision> EntityCollision::EntityCollisionList;

//==============================================================================
EntityCollision::EntityCollision() {
	EntityA = NULL;
	EntityB = NULL;
}

//==============================================================================
//Constructor.  Sets coordinates & attributes to zero
Entity::Entity() {
    //Necessary NULL declaration
    surf_entity = NULL;

    //X/Y coordinates set to zero, just to be generic
    x = y =0;

    //Default height & width of zero
    width = height = 0;

    //Default entity type
    type = ENTITY_TYPE_GENERIC;
    
    //Default entity, can't die until it has lived
    dead = false;

    //Gravity by default.  
    flags = ENTITY_FLAG_NONE;
    
    //Speed of entity
    speedX = 0;
    speedY = 0;
    
    //Acceleration per loop
    accelX = 0;
    accelY = 0;
    
    //Maximum speed entity can reach
    maxSpeedX = 2;
    maxSpeedY = 2;
    
    //Default animation frame column & row
    currentFrameCol = 0;
    currentFrameRow = 0;
    
    collisionX = 0;
    collisionY = 0;
    
    collisionW = 0;
    collisionH = 0;
    
    //Current animation state
    animState = 0;
}

//------------------------------------------------------------------------------
Entity::~Entity() {
}

//==============================================================================
bool Entity::Load(char* File, int width, int height, int MaxFrames) {
	if((surf_entity = Graphics::Load(File)) == NULL) {
		return false;
	}

	Graphics::Transparent(surf_entity, 255, 0, 255);

	this->width = width;
	this->height = height;

	Anim_Control.maxFrames = MaxFrames;

    return true;
}

//------------------------------------------------------------------------------
void Entity::Loop() 
{
    //If gravity applies, set gravity acceleration
    if( flags & ENTITY_FLAG_GRAVITY)
    {
        accelY = 0.75f;
    }
    
    //Increase the speed appropriately for the machine we are using
    speedX += accelX * FPS::FPSControl.GetSpeedFactor();
    speedY += accelY * FPS::FPSControl.GetSpeedFactor();
    
    //If speed is greater than max (moving right),
    if( speedX > maxSpeedX)
        //Set speed to max
        speedX = maxSpeedX;
    //If speed is less than max (moving left),
    if( speedX < -maxSpeedX)
        //Set speed to max
        speedX = -maxSpeedX;
    
    //If speed greater than max (going down),
    if( speedY > maxSpeedY)
        //Set speed to max
        speedY = maxSpeedY;
    //If speed is greater than max (going up),
    if( speedY < -maxSpeedY)
        //Set speed to max
        speedY = -maxSpeedY;
        
    Animate();
    OnMove(speedX, speedY);
}

//------------------------------------------------------------------------------
void Entity::Render(SDL_Surface* surf_display) {
    if(surf_entity == NULL || surf_display == NULL) return;

    //Graphics::Draw(surf_display, surf_entity, x, y, animState * width, Anim_Control.GetCurrentFrame() * height, width, height);
    Graphics::Draw(surf_display, surf_entity, ((int)x), ((int)y), currentFrameCol * width, (currentFrameRow + Anim_Control.GetCurrentFrame()) * height, width, height);
}

//------------------------------------------------------------------------------
void Entity::Cleanup() {
    if(surf_entity) {
        SDL_FreeSurface(surf_entity);
    }

    surf_entity = NULL;
}

//==============================================================================

void Entity::Animate()
{
    Anim_Control.Animate();    
}
//-----------------------------------------------------------------------------

//==============================================================================
void Entity::Collision(Entity* Entity)
{}

//------------------------------------------------------------------------------

void Entity::OnMove(float moveX, float moveY) {
	if(moveX == 0 && moveY == 0) return;

	double newX = 0;
	double newY = 0;

	moveX *= FPS::FPSControl.GetSpeedFactor();
	moveY *= FPS::FPSControl.GetSpeedFactor();

	if(moveX != 0) {
		if(moveX >= 0) 	newX =  FPS::FPSControl.GetSpeedFactor();
		else 			newX = -FPS::FPSControl.GetSpeedFactor();
	}

	if(moveY != 0) {
		if(moveY >= 0) 	newY =  FPS::FPSControl.GetSpeedFactor();
		else 			newY = -FPS::FPSControl.GetSpeedFactor();
	}

	while(true) 
    {
       	if(flags & ENTITY_FLAG_GHOST) 
        {
            PositionValid((int)(x + newX), (int)(y + newY)); //We don't care about collisions, but we need to send events to other entities

            x += newX;
		    y += newY;
		}
        else
        {
			if(PositionValid((int)(x + newX), (int)(y))) 
            {
			    x += newX;
			}
            else
            {
				speedX = 0;
			}

			if(PositionValid((int)(x), (int)(y + newY))) 
            {
				y += newY;
			}
            else
            {
				speedY = 0;
			}
		}

		moveX += -newX;
		moveY += -newY;

		if(newX > 0 && moveX <= 0) newX = 0;
		if(newX < 0 && moveX >= 0) newX = 0;

		if(newY > 0 && moveY <= 0) newY = 0;
		if(newY < 0 && moveY >= 0) newY = 0;

		if(moveX == 0) newX = 0;
		if(moveY == 0) newY = 0;

		if(moveX == 0 && moveY 	== 0) 	break;
		if(newX  == 0 && newY 	== 0) 	break;
	}
}
//------------------------------------------------------------------------------
void Entity::StopMove() {
	if(speedX > 0) {
		accelX = -1;
	}

	if(speedX < 0) {
		accelX =  1;
	}

	if(speedX < 2.0f && speedX > -2.0f) {
		accelX = 0;
		speedX = 0;
	}
}

//==============================================================================
bool Entity::Collides(int oX, int oY, int oW, int oH) {
    int left1, left2;
    int right1, right2;
    int top1, top2;
    int bottom1, bottom2;

	int tX = (int)x + collisionX;
	int tY = (int)y + collisionY;
	
    left1 = tX;
    left2 = oX;

    right1 = left1 + width - 1 - collisionW;
    right2 = oX + oW - 1;

    top1 = tY;
    top2 = oY;

    bottom1 = top1 + height - 1 - collisionH;
    bottom2 = oY + oH - 1;

    if (bottom1 < top2) return false;
    if (top1 > bottom2) return false;

    if (right1 < left2) return false;
    if (left1 > right2) return false;

    return true;
}

//==============================================================================
bool Entity::PositionValid(int newX, int newY) 
{
	bool Return = true;

	//int startX 	= (NewX + Col_X) / TILE_SIZE;
	//int startY 	= (NewY + Col_Y) / TILE_SIZE;

	//int endx	= ((NewX + Col_X) + Width - Col_Width - 1) 		/ TILE_SIZE;
	//int endY	= ((NewY + Col_Y) + Height - Col_Height - 1)	/ TILE_SIZE;

	//for(int iY = startY;iY <= endY;iY++) {
	//	for(int iX = startX;iX <= endx;iX++) {
		//	CTile* Tile = CArea::AreaControl.GetTile(iX * TILE_SIZE, iY * TILE_SIZE);

			//if(PosValidTile(Tile) == false) {
			//	Return = false;
			//}
		//}
	//}

	if(flags & ENTITY_FLAG_MAPONLY) 
    {}
    else
    {
		for(int i = 0;i < EntityList.size();i++) 
        {
			if(PositionValidEntity(EntityList[i], newX, newY) == false) {
				Return = false;
			}
		}
	}

	return Return;
}
/*
//------------------------------------------------------------------------------
bool CEntity::PositionValidTile(CTile* Tile) {
	if(Tile == NULL) {
		return true;
	}

	if(Tile->TypeID == TILE_TYPE_BLOCK) {
		return false;
	}

	return true;
}
*/
//------------------------------------------------------------------------------
bool Entity::PositionValidEntity(Entity* Entity, int newX, int newY) {
	if(this != Entity && Entity != NULL && Entity->dead == false &&
		Entity->flags ^ ENTITY_FLAG_MAPONLY &&
		Entity->Collides(newX + collisionX, newY + collisionY, width - collisionW, height - collisionH) == true) {

		EntityCollision EntCollision;

		EntCollision.EntityA = this;
		EntCollision.EntityB = Entity;

		EntityCollision::EntityCollisionList.push_back(EntCollision);

		return false;
	}

	return true;
}

//==============================================================================
