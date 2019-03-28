#include "app-glfw.hpp"

namespace bf {
glfw::glfw() : has_resized_(false), forced_render_count_(0) {
};

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

	// todo :
	//setInputCallbacksGLFW(window_.get());
	glfwSetWindowUserPointer(window_.get(), this);

	glfwSetFramebufferSizeCallback(window_.get(), reshape);
	glfwSetWindowFocusCallback(window_.get(), focus);
	
	return true;
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
	// todo : check forced render count
	if (forced_render_count_ > 0)
		--forced_render_count_;

	return true;
}

bool glfw::has_window_resized() {
	if (has_resized_) {
		has_resized_ = false;
		return true;
	}
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

void glfw::reshape(GLFWwindow* window, int width, int height) {
	auto self = static_cast<glfw*>(glfwGetWindowUserPointer(window));
	self->has_resized_ = true;
	self->forced_render_count_ += 2;
}

void glfw::focus(GLFWwindow* window, int focused) {
	auto self = static_cast<glfw*>(glfwGetWindowUserPointer(window));
	self->has_resized_ = focused != 0;
	self->forced_render_count_ += 2;
}

}