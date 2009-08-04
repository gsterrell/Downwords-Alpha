//==============================================================================
#include "event.h"

//==============================================================================
Event::Event() {
}

//------------------------------------------------------------------------------
Event::~Event() {
	//Do nothing
}

//==============================================================================
void Event::WhenEvent(SDL_Event* Event) {
	switch(Event->type) {
		case SDL_ACTIVEEVENT: {
			switch(Event->active.state) {
				case SDL_APPMOUSEFOCUS: {
					if ( Event->active.gain )	MouseFocus();
					else				MouseBlur();

					break;
				}
				case SDL_APPINPUTFOCUS: {
					if ( Event->active.gain )	InputFocus();
					else				InputBlur();

					break;
				}
				case SDL_APPACTIVE:	{
					if ( Event->active.gain )	Restore();
					else				Minimize();

					break;
				}
			}
			break;
		}

		case SDL_KEYDOWN: {
			KeyDown(Event->key.keysym.sym,Event->key.keysym.mod,Event->key.keysym.unicode);
			break;
		}

		case SDL_KEYUP: {
			KeyUp(Event->key.keysym.sym,Event->key.keysym.mod,Event->key.keysym.unicode);
			break;
		}

		case SDL_MOUSEMOTION: {
			MouseMove(Event->motion.x,Event->motion.y,Event->motion.xrel,Event->motion.yrel,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0);
			break;
		}

		case SDL_MOUSEBUTTONDOWN: {
			switch(Event->button.button) {
				case SDL_BUTTON_LEFT: {
					LButtonDown(Event->button.x,Event->button.y);
					break;
				}
				case SDL_BUTTON_RIGHT: {
					RButtonDown(Event->button.x,Event->button.y);
					break;
				}
				case SDL_BUTTON_MIDDLE: {
					MButtonDown(Event->button.x,Event->button.y);
					break;
				}
			}
			break;
		}

		case SDL_MOUSEBUTTONUP:	{
			switch(Event->button.button) {
				case SDL_BUTTON_LEFT: {
					LButtonUp(Event->button.x,Event->button.y);
					break;
				}
				case SDL_BUTTON_RIGHT: {
					RButtonUp(Event->button.x,Event->button.y);
					break;
				}
				case SDL_BUTTON_MIDDLE: {
					MButtonUp(Event->button.x,Event->button.y);
					break;
				}
			}
			break;
		}

		case SDL_JOYAXISMOTION: {
			JoyAxis(Event->jaxis.which,Event->jaxis.axis,Event->jaxis.value);
			break;
		}

		case SDL_JOYBALLMOTION: {
			JoyBall(Event->jball.which,Event->jball.ball,Event->jball.xrel,Event->jball.yrel);
			break;
		}

		case SDL_JOYHATMOTION: {
			JoyHat(Event->jhat.which,Event->jhat.hat,Event->jhat.value);
			break;
		}
		case SDL_JOYBUTTONDOWN: {
			JoyButtonDown(Event->jbutton.which,Event->jbutton.button);
			break;
		}

		case SDL_JOYBUTTONUP: {
			JoyButtonUp(Event->jbutton.which,Event->jbutton.button);
			break;
		}

		case SDL_QUIT: {
			Exit();
			break;
		}

		case SDL_SYSWMEVENT: {
			//Ignore
			break;
		}

		case SDL_VIDEORESIZE: {
			Resize(Event->resize.w,Event->resize.h);
			break;
		}

		case SDL_VIDEOEXPOSE: {
			Expose();
			break;
		}

		default: {
			User(Event->user.type,Event->user.code,Event->user.data1,Event->user.data2);
			break;
		}
	}
}

//------------------------------------------------------------------------------
void Event::InputFocus() {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::InputBlur() {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::KeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::KeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::MouseFocus() {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::MouseBlur() {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::MouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::MouseWheel(bool Up, bool Down) {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::LButtonDown(int mX, int mY) {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::LButtonUp(int mX, int mY) {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::RButtonDown(int mX, int mY) {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::RButtonUp(int mX, int mY) {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::MButtonDown(int mX, int mY) {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::MButtonUp(int mX, int mY) {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::JoyAxis(Uint8 which,Uint8 axis,Sint16 value) {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::JoyButtonDown(Uint8 which,Uint8 button) {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::JoyButtonUp(Uint8 which,Uint8 button) {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::JoyHat(Uint8 which,Uint8 hat,Uint8 value) {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::JoyBall(Uint8 which,Uint8 ball,Sint16 xrel,Sint16 yrel) {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::Minimize() {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::Restore() {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::Resize(int w,int h) {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::Expose() {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::Exit() {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void Event::User(Uint8 type, int code, void* data1, void* data2) {
	//Pure virtual, do nothing
}

//==============================================================================
