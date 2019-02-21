#pragma once
#include "structures.hpp"
#include "app-context.hpp"

namespace bf {
class GLFW : public OnAppBindable, public OnAppExecutable {
public:
	GLFW() = default;
	~GLFW() = default;

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

	//executable methods
	virtual bool IsRunning();
	virtual bool RequestExit();

	virtual bool PollEvents(shared_ptr<InputObservable> observer);

	virtual bool IsContextLost();
	virtual bool IsContextBound();
	virtual bool ShouldRender();
	virtual bool HasWindowResized();

	virtual bool SetTitle(const string& t);

private:

};
}