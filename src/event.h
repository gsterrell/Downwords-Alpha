//==============================================================================
#ifndef _EVENT_H_
	#define _EVENT_H_

#include <SDL.h>

//==============================================================================
class Event {
	public:
		Event();

		virtual ~Event();

		virtual void WhenEvent(SDL_Event* Event);

		virtual void InputFocus();

		virtual void InputBlur();

		virtual void KeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

		virtual void KeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

		virtual void MouseFocus();

		virtual void MouseBlur();

		virtual void MouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);

		virtual void MouseWheel(bool Up, bool Down);	//Not implemented

		virtual void LButtonDown(int mX, int mY);

		virtual void LButtonUp(int mX, int mY);

		virtual void RButtonDown(int mX, int mY);

		virtual void RButtonUp(int mX, int mY);

		virtual void MButtonDown(int mX, int mY);

		virtual void MButtonUp(int mX, int mY);

		virtual void JoyAxis(Uint8 which,Uint8 axis,Sint16 value);

		virtual void JoyButtonDown(Uint8 which,Uint8 button);

		virtual void JoyButtonUp(Uint8 which,Uint8 button);

		virtual void JoyHat(Uint8 which,Uint8 hat,Uint8 value);

		virtual void JoyBall(Uint8 which,Uint8 ball,Sint16 xrel,Sint16 yrel);

		virtual void Minimize();

		virtual void Restore();

		virtual void Resize(int w,int h);

		virtual void Expose();

		virtual void Exit();

		virtual void User(Uint8 type, int code, void* data1, void* data2);
};

//==============================================================================

#endif
