#include "app.hpp"

namespace bf {
void App::MainLoop() {
	has_initialized_rendering = false;

	while (platform->IsAppRunning()) {
		platform->PollEvents(this);
		Update();
		MainThreadRenderStep();
	}

	HaltRenderingThread();
	ShutdownRenderLoopObjects();
}

bool App::PointerInput(InputDeviceType device, PointerActionType action, unsigned int modifiers, int count, PointerEvent* points, long long timestamp) {
	// todo :
	return false;
}

bool App::KeyInput(unsigned int code, KeyActionType action) {
	// todo :
	return false;
}

bool App::CharacterInput(unsigned char c) {
	// todo :
	return false;
}


void App::MainThreadRenderStep() {
	bool needs_reshape = false;

	if (platform->IsContextLost()) {
		if (has_initialized_rendering) {
			HaltRenderingThread();
			ShutdownRendering();
			has_initialized_rendering = true;
		}
	}

	if (platform->ShouldRender()) {
		if (!has_initialized_rendering && !IsExiting()) {
			has_initialized_rendering = InitRendering();
			needs_reshape = true;
		}
		else if (platform->HasWindowResized()) {
			HaltRenderingThread();
			needs_reshape = true;
		}
	}

	if (needs_reshape && !IsExiting()) {
		Reshape(context->Width(), context->Height());
	}

	if (!ConditionalLaunchRenderingThread()) {
		RenderLoopRenderFrame();
	}
}

void App::HaltRenderingThread() {
	if (thread) {
		thread->join();
		context->BindContext();
		thread.reset();
	}
}

void App::ShutdownRenderLoopObjects() {
	if (has_initialized_rendering) {
		ShutdownRendering();
		has_initialized_rendering = false;
	}
}

bool App::ConditionalLaunchRenderingThread() {
	if (use_render_thread) {
		if (!render_thread_running) {
			render_thread_running = true;
			// todo : multi thread rendering
		}
		return true;
	}
	else {
		HaltRenderingThread();
		return false;
	}
}

void App::RequestThreadedRendering(bool threaded) {
	use_render_thread = threaded;
}

bool App::IsRenderThreadRunning() {
	return render_thread_running;
}

void App::RenderLoopRenderFrame() {
	// todo : frame timer

	if (!IsExiting()) {
		context->BeginFrame();
		context->BeginScene();

		Draw();

		context->EndScene();

		BaseDrawUI();

		context->EndFrame();
	}
}
	
void App::ShutdownRendering() {
	PlatformShutdownRendering();

	OnShutdownRendering();
}

void App::Update() {
	OnUpdate();
}

void App::Draw() {
	OnDraw();
}

bool App::InitRendering() {
	context->ContextInitRendering();

	if (!PlatformInitRendering()) {
		return false;
	}
	OnInitRendering();
	BaseInitUI();

	return true;
}

void App::Reshape(const size_t w, const size_t h) {
	context->PlatformReshape(w, h);

	if ((w == window_width) && (h == window_height)) {
		return;
	}

	window_width = w;
	window_height = h;

	// todo : input handler

	OnReshape(w, h);
}


/*



void App::BaseInitUI() {
	if (!title.empty())
		platform->SetTitle(title);

	PlatformInitUI();
}

void App::PlatformShutdownRendering() {
}






void App::BaseDrawUI() {
	// todo : draw fps
	DrawUI();
}


*/
}