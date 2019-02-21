#pragma once
#include "structures.hpp"
#include "app-context.hpp"

#include <GLFW/glfw3.h>

namespace bf {
class GLFW : public OnAppBindable, public OnAppExecutable {
public:
	GLFW();
	~GLFW();

	//executable methods
	virtual bool Initialize(size_t width, size_t height, bool fullscreen = false);

	virtual bool IsRunning();
	virtual void RequestExit();

	virtual bool PollEvents(shared_ptr<InputObservable> observer);

	virtual bool IsContextLost();
	virtual bool IsContextBound();
	virtual bool ShouldRender();
	virtual bool HasWindowResized();

	virtual void SetTitle(const string& t);

	// bindable methods
	virtual bool Bind();
	virtual bool Unbind();

	virtual const size_t Width();
	virtual const size_t Height();

	virtual void InitRendering();

	virtual bool Swap();
	virtual void BeginFrame();
	virtual void BeginScene();
	virtual void EndScene();
	virtual void EndFrame();

private:
	shared_ptr<GLFWwindow> window;
};
}