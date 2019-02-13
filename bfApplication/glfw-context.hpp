#pragma once
#include "app-context-gl.hpp"

#include <GL/glew.h>
#ifdef _WIN32
#include <GL/wglew.h>
/// todo : #else
#endif
#include <GLFW/glfw3.h>

namespace bf {
/*
class GLFWContextGL : public AppContextGL {
public:
	GLFWContextGL(const GLConfig& conf, const PlatformInfo& info);

	void SetGLFWWindow(const shared_ptr<GLFWwindow>& w);

	bool BindContext();
	bool UnbindContext();

	bool Swap();
	bool SetSwapInterval(const int32_t interval);

	int32_t Width();
	int32_t Height();

	void SetConfiguration(const GLConfig& conf);

private:
	shared_ptr<GLFWwindow> window;
};
*/
}