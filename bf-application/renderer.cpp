#include "renderer.hpp"

namespace bf {
Renderer::Renderer() : has_initialized_rendering(false) {
}

Renderer::~Renderer() {
}

bool Renderer::IsExiting() {
	return true;
}

bool Renderer::InitRendering() {
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
			has_initialized_rendering = InitRendering();
			needs_reshape = true;
		}
		else if (executor->HasWindowResized()) {
			HaltRenderingThread();

			needs_reshape = true;
		}

		/*
		if (needs_reshape && !IsExiting()) {
			Reshape(binder->Width(), binder->Height());
		}

		if (!ConditionalLaunchRenderingThread()) {
			RenderLoopRenderFrame();
		}
		*/
	}
}

void Renderer::ShutdownRendering() {

}
}