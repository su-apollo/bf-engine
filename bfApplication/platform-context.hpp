#pragma once
#include "allocator.hpp"

namespace bf {
enum class PointerActionType {
	UP = 0,
	DOWN = 1,
	MOTION = 2,
	EXTRA_DOWN = 4,
	EXTRA_UP = 8
};

enum class KeyActionType {
	UP = 0,
	DOWN = 1,
	REPEAT = 2
};

enum class InputDeviceType {
	MOUSE,
	TOUCH
};

enum class PointerModifierType {
	SHIFT = 0x00000001,
	CTRL = 0x00000002,
	ALT = 0x00000004
};

class MouseButton {
public:
	const static unsigned int LEFT = 0x00000001;
	const static unsigned int RIGHT = 0x00000002;
	const static unsigned int MIDDLE = 0x00000004;
};

class PointerEvent {
public:
    float x;
    float y;
	unsigned int id;
    InputDeviceType device;
};

class InputBase {
public:
	virtual bool PointerInput(InputDeviceType device, PointerActionType action, unsigned int modifiers, int count, PointerEvent* points, long long timestamp = 0) = 0;
	virtual bool KeyInput(unsigned int code, KeyActionType action) = 0;
	virtual bool CharacterInput(unsigned char c) = 0;
};

class PlatformContextBase {
public:
	virtual bool IsAppRunning() = 0;
	virtual void RequestExit() = 0;
	virtual void PollEvents(InputBase* callbacks) = 0;
	virtual bool IsContextLost() = 0;

	virtual bool ShouldRender() = 0;
	virtual bool HasWindowResized() = 0;

	virtual void SetTitle(const string& title) = 0;
};
}