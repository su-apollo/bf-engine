#pragma once
#include "types.hpp"
#include "structures.hpp"
#include "app-context.hpp"

namespace bf {
class renderer 
{
public:
	renderer();
	~renderer();

	bool initialize(const shared_ptr<app_executable>& executor, const shared_ptr<app_bindable>& binder, const shared_ptr<graphic_library>& gl);

	void request_exit();
	bool is_exiting() const;

	void main_thread_initialize_step();
	void main_thread_render_step();
	void main_thread_shutdown_step();

protected:
	bool halt_rendering_thread();
	bool conditional_launch_rendering_thread();
	void init_render_loop_objects();
	void render_loop_render_frame();
	void shutdown_render_loop_objects();

	// todo :
	bool init_rendering();
	void reshape(size_t w, size_t h);
	void shutdown_rendering();

	shared_ptr<app_executable> executor_;
	shared_ptr<app_bindable> binder_;
	shared_ptr<graphic_library> gl_;

	bool request_exit_;

	bool has_initialized_rendering_;
	bool use_render_thread_;
	bool render_thread_running_;
};
}