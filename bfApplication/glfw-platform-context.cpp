#include "glfw-platform-context.hpp"

#include <cstdlib>

namespace bf{
/*
const char* DefaultTitle = "Hello World!";

GLFWPlatformContext::GLFWPlatformContext() 
: has_resized(false)
, window_is_focused(false)
, forced_render_count(0) {
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
}

GLFWPlatformContext::~GLFWPlatformContext() {
	glfwTerminate();
}

void GLFWPlatformContext::CreateGLFWWindow(unsigned int width, unsigned int height, bool fullscreen) {
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
		glfwCreateWindow(width, height, DefaultTitle, monitor, nullptr)
		, [](GLFWwindow* p){ glfwDestroyWindow(p); });

	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//setInputCallbacksGLFW(mWindow);
	glfwSetWindowUserPointer(window.get(), this);

	// Set callback functions
	glfwSetFramebufferSizeCallback(window.get(), Reshape);
	glfwSetWindowFocusCallback(window.get(), Focus);
}

void GLFWPlatformContext::DestroyGLFWWindow() {
	window.reset();
}

shared_ptr<GLFWwindow> GLFWPlatformContext::GetGLFWWindow() {
	return window;
}

void GLFWPlatformContext::SetTitle(const string& title) {
	if (window) {
		glfwSetWindowTitle(window.get(), title.c_str());
	}
}

void GLFWPlatformContext::UpdateWindowSize() {
	int32_t width = 0;
	int32_t height = 0;
	glfwGetFramebufferSize(window.get(), &width, &height);
	Reshape(window.get(), width, height);
}

bool GLFWPlatformContext::IsAppRunning() {
	return !glfwWindowShouldClose(window.get());
}

void GLFWPlatformContext::RequestExit() {
	glfwSetWindowShouldClose(window.get(), 1);
}

void GLFWPlatformContext::PollEvents(InputCallbacks* callbacks) {
	// todo : callbacks
	glfwPollEvents();
}

bool GLFWPlatformContext::IsContextLost() {
	return false;
}

bool GLFWPlatformContext::ShouldRender() {
	if (forced_render_count > 0) {
		--forced_render_count;
	}
	return true;
}

bool GLFWPlatformContext::HasWindowResized() {
	if (has_resized) {
		has_resized = false;
		return true;
	}
	return false;
}

void GLFWPlatformContext::Reshape(GLFWwindow* window, int32_t width, int32_t height) {
	GLFWPlatformContext* self = (GLFWPlatformContext*)glfwGetWindowUserPointer(window);
	self->has_resized = true;
	self->forced_render_count += 2;
}

void GLFWPlatformContext::Focus(GLFWwindow* window, int32_t focused) {
	GLFWPlatformContext* self = (GLFWPlatformContext*)glfwGetWindowUserPointer(window);
	self->window_is_focused = focused != 0;
	// HACK - takes advantage of the fact that focus is only handled on Android...
	//	sApp->focusChanged(pThis->mWindowIsFocused);
	self->forced_render_count += 2;
}
*/
}