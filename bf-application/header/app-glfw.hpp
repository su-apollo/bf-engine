#pragma once
#include "structures.hpp"
#include "app-context.hpp"

#include <GLFW/glfw3.h>

namespace bf {
class glfw final : public on_app_bindable, public on_app_executable {
public:
	glfw();
	~glfw();

	//executable methods
	bool initialize(size_t width, size_t height, bool fullscreen = false) override;

	bool is_running() override;
	void request_exit() override;

	bool poll_events(shared_ptr<input_observable> observer) override;

	bool is_context_lost() override;
	bool is_context_bound() override;
	bool should_render() override;
	bool has_window_resized() override;

	void set_title(const string& t) override;

	// bindable methods
	bool bind() override;
	bool unbind() override;

	size_t width() override;
	size_t height() override;

	void init_rendering() override;

	bool swap() override;
	void begin_frame() override;
	void begin_scene() override;
	void end_scene() override;
	void end_frame() override;

private:
	shared_ptr<GLFWwindow> window_;

	bool has_resized_;
	int forced_render_count_;

	static void reshape(GLFWwindow* window, int width, int height);
	static void focus(GLFWwindow* window, int focused);
};
}