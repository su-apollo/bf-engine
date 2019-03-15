#include "renderer.hpp"

namespace bf {
renderer::renderer() 
	: request_exit_(false)
	, has_initialized_rendering_(false)
	, use_render_thread_(false) 
	, render_thread_running_(false) {
}

renderer::~renderer() = default;

void renderer::request_exit() {
	request_exit_ = true;
}

bool renderer::is_exiting() const {
	return request_exit_;
}

// todo : 
bool renderer::init_rendering(const shared_ptr<on_app_bindable>& binder) {
	binder->init_rendering();

	return true;
}

// todo : multi rendering
bool renderer::halt_rendering_thread() {
	return true;
}

void renderer::main_thread_initialize_step() {
	has_initialized_rendering_ = false;

	init_render_loop_objects();
}

void renderer::main_thread_render_step(const shared_ptr<on_app_executable>& executor, const shared_ptr<on_app_bindable>& binder) {
	auto needs_reshape = false;
	
	if (executor->is_context_lost()) {
		if (has_initialized_rendering_) {
			halt_rendering_thread();

			shutdown_rendering();
			has_initialized_rendering_ = false;
		}
	}

	if (executor->should_render()) {
		if (!has_initialized_rendering_ && !is_exiting()) {
			has_initialized_rendering_ = init_rendering(binder);
			needs_reshape = true;
		}
		else if (executor->has_window_resized()) {
			halt_rendering_thread();

			needs_reshape = true;
		}

		if (needs_reshape && !is_exiting()) {
			reshape(binder->width(), binder->height());
		}

		if (!conditional_launch_rendering_thread()) {
			render_loop_render_frame(binder);
		}
	}
}

void renderer::main_thread_shutdown_step() {
	halt_rendering_thread();
	shutdown_render_loop_objects();
}

bool renderer::conditional_launch_rendering_thread() {
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
void renderer::init_render_loop_objects() {

}

// todo :
void renderer::render_loop_render_frame(const shared_ptr<on_app_bindable>& binder) {
	binder->begin_frame();
	binder->begin_scene();

	// todo : draw methods

	binder->end_scene();
	binder->end_frame();
	binder->swap();
}

// todo :
void renderer::shutdown_render_loop_objects() {

}

// todo :
void renderer::reshape(size_t w, size_t h) {

}

// todo :
void renderer::shutdown_rendering() {

}
}