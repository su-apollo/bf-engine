#pragma once
#include "types.hpp"

namespace bf {
// todo :
class Observable {
public:
	virtual bool PointerInput() = 0;
	virtual bool KeyInput() = 0;
	virtual bool CharacterInput() = 0;
};
	
class OnAppBindable {
public:
	virtual bool Bind() = 0;
	virtual bool Unbind() = 0;

	virtual size_t Width() = 0;
	virtual size_t Height() = 0;

	virtual bool Swap() = 0;
	virtual void BeginFrame() = 0;
	virtual void BeginScene() = 0;
	virtual void EndScene() = 0;
	virtual void EndFrame() = 0;
};

class OnAppExecutable {
public:
	virtual bool IsRunning() = 0;
	virtual bool RequestExit() = 0;

	virtual bool PollEvents(Observable* observer) = 0;

	virtual bool IsContextLost() = 0;
	virtual bool IsContextBound() = 0;
	virtual bool ShouldRender() = 0;
	virtual bool HasWindowResized() = 0;

	virtual bool SetTitle() = 0;
};
}