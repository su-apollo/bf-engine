#pragma once
#include "platform-context.hpp"
#include "allocator.hpp"

#include <GL/glew.h>
#ifdef _WIN32
#include <GL/wglew.h>
/// todo : #else
#endif
#include <GLFW/glfw3.h>

namespace bf {
class GLFWPlatformContext : public PlatformContext {
public:
	GLFWPlatformContext();
	~GLFWPlatformContext();

	void CreateGLFWWindow(unsigned int width, unsigned int height, bool fullscreen = false);
	void DestroyGLFWWindow();
	shared_ptr<GLFWwindow> GetGLFWWindow();

	void SetTitle(const string& title);

	void UpdateWindowSize();

	bool IsAppRunning();
	void RequestExit();
	void PollEvents(InputCallbacks* callbacks);
	bool IsContextLost();

	bool ShouldRender();
	bool HasWindowResized();

private:
	static void Reshape(GLFWwindow* window, int32_t width, int32_t height);
	static void Focus(GLFWwindow* window, int32_t focused);

	shared_ptr<GLFWwindow> window;
	bool has_resized;
	bool window_is_focused;
	int32_t forced_render_count;
};
}