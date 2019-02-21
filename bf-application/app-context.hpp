#pragma once
#include "types.hpp"

namespace bf {
// todo :
class InputObservable {
public:
	virtual bool PointerInput() = 0;
	virtual bool KeyInput() = 0;
	virtual bool CharacterInput() = 0;
};
	
class OnAppBindable {
public:
	virtual bool Bind() = 0;
	virtual bool Unbind() = 0;

	virtual const size_t Width() = 0;
	virtual const size_t Height() = 0;

	virtual void InitRendering() = 0;

	virtual bool Swap() = 0;
	virtual void BeginFrame() = 0;
	virtual void BeginScene() = 0;
	virtual void EndScene() = 0;
	virtual void EndFrame() = 0;
};

class OnAppExecutable {
public:
	virtual bool Initialize(size_t width, size_t height, bool fullscreen = false) = 0;

	virtual bool IsRunning() = 0;
	virtual void RequestExit() = 0;

	virtual bool PollEvents(shared_ptr<InputObservable> observer) = 0;

	virtual bool IsContextLost() = 0;
	virtual bool IsContextBound() = 0;
	virtual bool ShouldRender() = 0;
	virtual bool HasWindowResized() = 0;

	virtual void SetTitle(const string& t) = 0;
};

class OnAppContextable {
public:
	virtual shared_ptr<OnAppBindable> MakeBinder() = 0;
	virtual shared_ptr<OnAppExecutable> MakeExecutor() = 0;
};
}