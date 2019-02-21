#pragma once
#include "types.hpp"
#include "structures.hpp"
#include "app-context.hpp"

namespace bf {
class Renderer {
public:
	Renderer();
	~Renderer();

	void RequestExit();
	bool IsExiting();

	void MainThreadRenderStep(const shared_ptr<OnAppExecutable>& executor, const shared_ptr<OnAppBindable>& binder);

protected:
	bool HaltRenderingThread();
	bool ConditionalLaunchRenderingThread();
	void RenderLoopRenderFrame(const shared_ptr<OnAppBindable>& binder);

	// todo :
	bool InitRendering(const shared_ptr<OnAppBindable>& binder);
	void Reshape(size_t w, size_t h);
	void ShutdownRendering();

	bool request_exit;

	bool has_initialized_rendering;
	bool use_render_thread;
	bool render_thread_running;
};
}