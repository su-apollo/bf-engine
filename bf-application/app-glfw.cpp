#include "app-glfw.hpp"

namespace bf {
bool GLFW::Bind() {
	return false;
}

bool GLFW::Unbind() {
	return false;
}

const size_t GLFW::Width() {
	return 0;
}

const size_t GLFW::Height() {
	return 0;
}

void GLFW::InitRendering() {

}

bool GLFW::Swap() {
	return false;
}

void GLFW::BeginFrame() {

}

void GLFW::BeginScene() {

}

void GLFW::EndScene() {

}

void GLFW::EndFrame() {

}

bool GLFW::IsRunning() {
	return false;
}

bool GLFW::RequestExit() {
	return false;
}

bool GLFW::PollEvents(shared_ptr<InputObservable> observer) {
	return false;
}

bool GLFW::IsContextLost() {
	return false;
}

bool GLFW::IsContextBound() {
	return false;
}

bool GLFW::ShouldRender() {
	return false;
}

bool GLFW::HasWindowResized() {
	return false;
}

bool GLFW::SetTitle(const string& t) {
	return false;
}
}