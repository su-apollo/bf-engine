#pragma once
#include <allocator.hpp>
//#include <memory-pool.h>

namespace bf {
struct PointerActionType {
	enum Enum {
		UP = 0,
		DOWN = 1,
		MOTION = 2,
		EXTRA_DOWN = 4,
		EXTRA_UP = 8
	};
};

struct KeyActionType {
	enum Enum {
		UP = 0,
		DOWN = 1,
		REPEAT = 2
	};
};

struct InputDeviceType {
	enum Enum {
		MOUSE,
		TOUCH,
	};
};

struct PointerModifierType {
	enum Enum {
		SHIFT = 0x00000001,
		CTRL = 0x00000002,
		ALT = 0x00000004,
	};
};

struct MouseButton {
	const static unsigned int LEFT = 0x00000001;
	const static unsigned int RIGHT = 0x00000002;
	const static unsigned int MIDDLE = 0x00000004;
};

class PointerEvent {
public:
    float x;
    float y;
	unsigned int id;
    InputDeviceType::Enum device;
};

class InputCallbacks {
public:
	/// todo :
	virtual bool PointerInput(InputDeviceType::Enum device, PointerActionType::Enum action, unsigned int modifiers, int count, PointerEvent* points, long long timestamp = 0) = 0;
	virtual bool KeyInput(unsigned int code, KeyActionType::Enum action) = 0;
	virtual bool CharacterInput(unsigned char c) = 0;
};

class PlatformContext /*: public PooledAllocatable*/ {
public:
	virtual bool IsAppRunning() = 0;
	virtual void RequestExit() = 0;
	virtual void PollEvents(InputCallbacks* callbacks) = 0;
	virtual bool IsContextLost() = 0;

	virtual bool ShouldRender() = 0;
	virtual bool HasWindowResized() = 0;

	virtual void SetTitle(const string& title) = 0;
};
}