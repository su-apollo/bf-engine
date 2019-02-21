#include "app-glfw.hpp"

namespace bf {
GLFW::GLFW() {
}

GLFW::~GLFW() {
	glfwTerminate();
}

bool GLFW::Initialize(size_t width, size_t height, bool fullscreen) {
	if (!glfwInit())
		return false;

	GLFWmonitor* monitor = nullptr;
	if (fullscreen) {
		const GLFWvidmode* mode;

		monitor = glfwGetPrimaryMonitor();
		mode = glfwGetVideoMode(monitor);

		glfwWindowHint(GLFW_RED_BITS, mode->redBits);
		glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
		glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
		glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

		width = mode->width;
		height = mode->height;
	}

	window = shared_ptr<GLFWwindow>(
		glfwCreateWindow(width, height, "Hello World!", monitor, nullptr)
		, [](GLFWwindow* p){ glfwDestroyWindow(p); });

	if (!window) {
		glfwTerminate();
		return false;
	}

	//setInputCallbacksGLFW(window.get());
	//glfwSetWindowUserPointer(window.get(), this);

	//glfwSetFramebufferSizeCallback(window.get(), reshape);
	//glfwSetWindowFocusCallback(window.get(), focus);
}

bool GLFW::IsRunning() {
	return !glfwWindowShouldClose(window.get());
}

void GLFW::RequestExit() {
	glfwSetWindowShouldClose(window.get(), 1);
}

bool GLFW::PollEvents(shared_ptr<InputObservable> observer) {
	glfwPollEvents();
	return true;
}

bool GLFW::IsContextLost() {
	return false;
}

bool GLFW::IsContextBound() {
	return glfwGetCurrentContext() != NULL;
}

bool GLFW::ShouldRender() {
	return false;
}

bool GLFW::HasWindowResized() {
	return false;
}

void GLFW::SetTitle(const string& t) {
	if (window)
		glfwSetWindowTitle(window.get(), t.c_str());
}

bool GLFW::Bind() {
	glfwMakeContextCurrent(window.get());
	return true;
}

bool GLFW::Unbind() {
	glfwMakeContextCurrent(NULL);
	return true;
}

const size_t GLFW::Width() {
	int w, h;
	glfwGetFramebufferSize(window.get(), &w, &h);
	return w;
}

const size_t GLFW::Height() {
	int w, h;
	glfwGetFramebufferSize(window.get(), &w, &h);
	return h;
}

void GLFW::InitRendering() {

}

bool GLFW::Swap() {
	glfwSwapBuffers(window.get());
	return true;
}

void GLFW::BeginFrame() {

}

void GLFW::BeginScene() {

}

void GLFW::EndScene() {

}

void GLFW::EndFrame() {

}
}