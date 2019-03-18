#include "renderer.hpp"
#include <utility>

namespace bf {
renderer::renderer() 
	: request_exit_(false)
	, has_initialized_rendering_(false)
	, use_render_thread_(false) 
	, render_thread_running_(false) 
{
}

renderer::~renderer() = default;

bool renderer::initialize(const shared_ptr<app_executable>& executor, const shared_ptr<app_bindable>& binder, const shared_ptr<graphic_library>& gl)
{
	executor_ = executor;
	binder_ = binder;
	gl_ = gl;

	return gl_->initialize();
}

void renderer::request_exit() 
{
	request_exit_ = true;
}

bool renderer::is_exiting() const 
{
	return request_exit_;
}

// todo : 
bool renderer::init_rendering() 
{
	binder_->init_rendering();

	return true;
}

// todo : multi rendering
bool renderer::halt_rendering_thread() 
{
	return true;
}

void renderer::main_thread_initialize_step() 
{
	has_initialized_rendering_ = false;

	init_render_loop_objects();
}

void renderer::main_thread_render_step() 
{
	auto needs_reshape = false;
	
	if (executor_->is_context_lost()) {
		if (has_initialized_rendering_) {
			halt_rendering_thread();

			shutdown_rendering();
			has_initialized_rendering_ = false;
		}
	}

	if (executor_->should_render()) {
		if (!has_initialized_rendering_ && !is_exiting()) {
			has_initialized_rendering_ = init_rendering();
			needs_reshape = true;
		}
		else if (executor_->has_window_resized()) {
			halt_rendering_thread();

			needs_reshape = true;
		}

		if (needs_reshape && !is_exiting()) {
			reshape(binder_->width(), binder_->height());
		}

		if (!conditional_launch_rendering_thread()) {
			render_loop_render_frame();
		}
	}
}

void renderer::main_thread_shutdown_step() 
{
	halt_rendering_thread();
	shutdown_render_loop_objects();
}

bool renderer::conditional_launch_rendering_thread() 
{
	if (use_render_thread_) {
		if (!render_thread_running_) {
			// todo :
			// multi thread rendering
		}

		return true;
	}
	else {
		halt_rendering_thread();
		return false;
	}
}

// todo:
void renderer::init_render_loop_objects() 
{
}

// todo :
void renderer::render_loop_render_frame() 
{
	binder_->begin_frame();
	binder_->begin_scene();

	// todo : draw methods
	gl_->test_draw();

	binder_->end_scene();
	binder_->end_frame();
	binder_->swap();
}

// todo :
void renderer::shutdown_render_loop_objects() 
{

}

// todo :
void renderer::reshape(size_t w, size_t h) 
{
	gl_->reshape(w, h);
}

// todo :
void renderer::shutdown_rendering() 
{

}
}