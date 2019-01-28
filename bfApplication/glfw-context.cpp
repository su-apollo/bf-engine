#include "glfw-context.hpp"

namespace bf {
GLFWContextGL::GLFWContextGL(const GLConfig& conf, const PlatformInfo& info)
: AppContextGL(info) {
	config = conf;
	glfwWindowHint(GLFW_RED_BITS, config.red_bits);
	glfwWindowHint(GLFW_GREEN_BITS, config.green_bits);
	glfwWindowHint(GLFW_BLUE_BITS, config.blue_bits);
	glfwWindowHint(GLFW_ALPHA_BITS, config.alpha_bits);
	glfwWindowHint(GLFW_DEPTH_BITS, config.depth_bits);
	glfwWindowHint(GLFW_STENCIL_BITS, config.stencil_bits);
	glfwWindowHint(GLFW_SAMPLES, config.msaa_samples);
}

void GLFWContextGL::SetGLFWWindow(const shared_ptr<GLFWwindow>& w) {
	window = w;
}

bool GLFWContextGL::BindContext() {
	glfwMakeContextCurrent(window.get());
	return true;
}

bool GLFWContextGL::UnbindContext() {
	glfwMakeContextCurrent(nullptr);
	return true;
}

bool GLFWContextGL::Swap() {
	glfwSwapBuffers(window.get());
	return true;
}

bool GLFWContextGL::SetSwapInterval(const int32_t interval) {
	glfwSwapInterval(interval);
	return false;
}

int32_t GLFWContextGL::Width() {
	int32_t w, h;
	glfwGetFramebufferSize(window.get(), &w, &h);
	return w;
}

int32_t GLFWContextGL::Height() {
	int32_t w, h;
	glfwGetFramebufferSize(window.get(), &w, &h);
	return h;
}

void GLFWContextGL::SetConfiguration(const GLConfig& conf) {
	config = conf;

	int32_t major = glfwGetWindowAttrib(window.get(), GLFW_CONTEXT_VERSION_MAJOR);
	int32_t minor = glfwGetWindowAttrib(window.get(), GLFW_CONTEXT_VERSION_MINOR);
	config.version = GLAPIVersion(GLAPI::GL, major, minor);

	glGetIntegerv(GL_RED_BITS, (GLint*)&config.red_bits);
	glGetIntegerv(GL_GREEN_BITS, (GLint*)&config.green_bits);
	glGetIntegerv(GL_BLUE_BITS, (GLint*)&config.blue_bits);
	glGetIntegerv(GL_ALPHA_BITS, (GLint*)&config.alpha_bits);
	glGetIntegerv(GL_DEPTH_BITS, (GLint*)&config.depth_bits);
	glGetIntegerv(GL_STENCIL_BITS, (GLint*)&config.stencil_bits);

	BindContext();
}
}