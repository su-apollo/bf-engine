#include "renderer.hpp"

namespace bf {
Renderer::Renderer() 
	: has_initialized_rendering(false)
	, use_render_thread(false) 
	, render_thread_running(false) {
}

Renderer::~Renderer() {
}

void Renderer::RequestExit() {
	request_exit = true;
}

bool Renderer::IsExiting() {
	return request_exit;
}

bool Renderer::InitRendering(const shared_ptr<OnAppBindable>& binder) {

	binder->InitRendering();

	return true;
}

bool Renderer::HaltRenderingThread() {
	return true;
}

void Renderer::MainThreadRenderStep(const shared_ptr<OnAppExecutable>& executor, const shared_ptr<OnAppBindable>& binder) {
	bool needs_reshape = false;
	
	if (executor->IsContextLost()) {
		if (has_initialized_rendering) {
			HaltRenderingThread();

			ShutdownRendering();
			has_initialized_rendering = false;
		}
	}

	if (executor->ShouldRender()) {
		if (!has_initialized_rendering && !IsExiting()) {
			has_initialized_rendering = InitRendering(binder);
			needs_reshape = true;
		}
		else if (executor->HasWindowResized()) {
			HaltRenderingThread();

			needs_reshape = true;
		}

		if (needs_reshape && !IsExiting()) {
			Reshape(binder->Width(), binder->Height());
		}

		if (!ConditionalLaunchRenderingThread()) {
			RenderLoopRenderFrame(binder);
		}
	}
}

bool Renderer::ConditionalLaunchRenderingThread() {
	if (use_render_thread) {
		if (!render_thread_running) {
			// todo :
			// multi thread rendering
		}

		return true;
	}
	else {
		HaltRenderingThread();
		return false;
	}
}

void Renderer::RenderLoopRenderFrame(const shared_ptr<OnAppBindable>& binder) {
	binder->BeginFrame();
	binder->BeginScene();

	binder->EndScene();
	binder->EndFrame();
	binder->Swap();
}

void Renderer::Reshape(size_t w, size_t h) {

}

void Renderer::ShutdownRendering() {

}
}