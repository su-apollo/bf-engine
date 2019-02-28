#pragma once
#include "types.hpp"
#include "structures.hpp"
#include "app-context.hpp"

namespace bf {
class renderer {
public:
	renderer();
	~renderer();

	void request_exit();
	bool is_exiting() const;

	void main_thread_initialize_step();
	void main_thread_render_step(const shared_ptr<on_app_executable>& executor, const shared_ptr<on_app_bindable>& binder);
	void main_thread_shutdown_step();

protected:
	bool halt_rendering_thread();
	bool conditional_launch_rendering_thread();
	void init_render_loop_objects();
	void render_loop_render_frame(const shared_ptr<on_app_bindable>& binder);
	void shutdown_render_loop_objects();

	// todo :
	bool init_rendering(const shared_ptr<on_app_bindable>& binder);
	void reshape(size_t w, size_t h);
	void shutdown_rendering();

	bool request_exit_;

	bool has_initialized_rendering_;
	bool use_render_thread_;
	bool render_thread_running_;
};
}