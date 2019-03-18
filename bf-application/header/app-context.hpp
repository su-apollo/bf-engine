#pragma once
#include "types.hpp"
#include "structures.hpp"

namespace bf {
// todo :
class input_observable {
public:
	virtual bool pointer_input() = 0;
	virtual bool key_input() = 0;
	virtual bool character_input() = 0;
};
	
class app_bindable {
public:
	virtual bool bind() = 0;
	virtual bool unbind() = 0;

	virtual size_t width() = 0;
	virtual size_t height() = 0;

	virtual void init_rendering() = 0;

	virtual bool swap() = 0;
	virtual void begin_frame() = 0;
	virtual void begin_scene() = 0;
	virtual void end_scene() = 0;
	virtual void end_frame() = 0;
};

class app_executable {
public:
	virtual bool initialize(size_t width, size_t height, bool fullscreen = false) = 0;

	virtual bool is_running() = 0;
	virtual void request_exit() = 0;

	virtual bool poll_events(shared_ptr<input_observable> observer) = 0;

	virtual bool is_context_lost() = 0;
	virtual bool is_context_bound() = 0;
	virtual bool should_render() = 0;
	virtual bool has_window_resized() = 0;

	virtual void set_title(const string& t) = 0;
};

class graphic_library {
public:
	virtual bool initialize() = 0;
	virtual void test_draw() = 0;
	virtual void reshape(const float w, const float h) = 0;
};

class app_contextable {
public:
	virtual shared_ptr<app_bindable> make_binder() = 0;
	virtual shared_ptr<app_executable> make_executor() = 0;
	virtual shared_ptr<graphic_library> make_gl() = 0;
};
}