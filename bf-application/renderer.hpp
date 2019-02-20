#pragma once
#include "structures.hpp"
#include "app-context.hpp"

namespace bf {
class Renderer {
public:
	Renderer();
	~Renderer();

	bool IsExiting();
	bool InitRendering();

	bool HaltRenderingThread();

	void MainThreadRenderStep(const shared_ptr<OnAppExecutable>& executor, const shared_ptr<OnAppBindable>& binder);

	void ShutdownRendering();

protected:
	bool has_initialized_rendering;
};
}