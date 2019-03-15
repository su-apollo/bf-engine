#include "app-base.hpp"

namespace bf {
application::application() : request_exit_(false), window_width_(0), window_height_(0) {
}

application::~application() = default;

void application::append_command(const string& command) {
	command_line_.push_back(command);
}

bool application::initialize(const shared_ptr<on_app_contextable>& context, const size_t width, const size_t height) {
	executor_ = context->make_executor();
	binder_ = context->make_binder();

	if (!executor_->initialize(width, height))
		return false;

	binder_->bind();


	return true; 
}
	
void application::main_loop() {
	renderer_.main_thread_initialize_step();

	while (executor_->is_running() && !is_exiting()) {
		executor_->poll_events(nullptr);
		update();

		renderer_.main_thread_render_step(executor_, binder_);
	}

	renderer_.main_thread_shutdown_step();
}

// todo :
void application::update() {
}

void application::set_title(const string& t) { 
	title_ = t; 
}

void application::request_exit() { 
	executor_->request_exit();
	request_exit_ = true; 
}

bool application::is_exiting() const {
	return request_exit_; 
}
}