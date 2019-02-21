#include "app-base.hpp"

namespace bf {
Application::Application() : window_width(0), window_height(0), request_exit(false) {
}

Application::~Application() {
}

void Application::AppendCommand(const string& command) {
	command_line.push_back(command);
}

bool Application::Initialize(const shared_ptr<OnAppContextable>& context, const size_t width, const size_t height) {
	executor = context->MakeExecutor();
	binder = context->MakeBinder();

	if (!executor->Initialize(width, height))
		return false;

	return true; 
}
	
void Application::MainLoop() {
	renderer.MainThreadInitializeStep();

	while (executor->IsRunning() && !IsExiting()) {
		executor->PollEvents(nullptr);
		Update();

		renderer.MainThreadRenderStep(executor, binder);
	}

	renderer.MainThreadShutdownStep();
}

void Application::Update() {
}

void Application::SetTitle(const string& t) { 
	title = t; 
}

void Application::RequestExit() { 
	executor->RequestExit();
	request_exit = true; 
}

bool Application::IsExiting() {
	return request_exit; 
}
}