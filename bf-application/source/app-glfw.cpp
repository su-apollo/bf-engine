#include "app-glfw.hpp"

namespace bf {
glfw::glfw() = default;

glfw::~glfw() {
	glfwTerminate();
}

bool glfw::initialize(size_t width, size_t height, const bool fullscreen) {
	if (!glfwInit())
		return false;

	GLFWmonitor* monitor = nullptr;
	if (fullscreen) {
		monitor = glfwGetPrimaryMonitor();
		const auto mode = glfwGetVideoMode(monitor);

		glfwWindowHint(GLFW_RED_BITS, mode->redBits);
		glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
		glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
		glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

		width = mode->width;
		height = mode->height;
	}

	window_ = shared_ptr<GLFWwindow>(
		glfwCreateWindow(width, height, "Hello World!", monitor, nullptr)
		, [](GLFWwindow* p){ glfwDestroyWindow(p); });

	if (!window_) {
		glfwTerminate();
		return false;
	}

	//setInputCallbacksGLFW(window.get());
	//glfwSetWindowUserPointer(window.get(), this);

	//glfwSetFramebufferSizeCallback(window.get(), reshape);
	//glfwSetWindowFocusCallback(window.get(), focus);
	return false;
}

bool glfw::is_running() {
	return !glfwWindowShouldClose(window_.get());
}

void glfw::request_exit() {
	glfwSetWindowShouldClose(window_.get(), 1);
}

bool glfw::poll_events(shared_ptr<input_observable> observer) {
	glfwPollEvents();
	return true;
}

bool glfw::is_context_lost() {
	return false;
}

bool glfw::is_context_bound() {
	return glfwGetCurrentContext() != nullptr;
}

bool glfw::should_render() {
	return false;
}

bool glfw::has_window_resized() {
	return false;
}

void glfw::set_title(const string& t) {
	if (window_)
		glfwSetWindowTitle(window_.get(), t.c_str());
}

bool glfw::bind() {
	glfwMakeContextCurrent(window_.get());
	return true;
}

bool glfw::unbind() {
	glfwMakeContextCurrent(nullptr);
	return true;
}

size_t glfw::width() {
	int w, h;
	glfwGetFramebufferSize(window_.get(), &w, &h);
	return w;
}

size_t glfw::height() {
	int w, h;
	glfwGetFramebufferSize(window_.get(), &w, &h);
	return h;
}

void glfw::init_rendering() {

}

bool glfw::swap() {
	glfwSwapBuffers(window_.get());
	return true;
}

void glfw::begin_frame() {

}

void glfw::begin_scene() {

}

void glfw::end_scene() {

}

void glfw::end_frame() {

}
}