#pragma once
#include "types.hpp"
#include "structures.hpp"
#include "renderer.hpp"
#include "app-context.hpp"

#include <thread>

namespace bf {
class applicable {
public:
	virtual ~applicable() = default;
	virtual void append_command(const string& command) = 0;
	virtual bool initialize(const shared_ptr<on_app_contextable>& context, const size_t width, const size_t height) = 0;
	virtual void main_loop() = 0;
};

class application : public applicable {
public:
	application();
	~application();

	void append_command(const string& command) override;
	bool initialize(const shared_ptr<on_app_contextable>& context, const size_t width, const size_t height) override;
	void main_loop() override;
	
	void update();
	void set_title(const string& t);
	void request_exit();
	bool is_exiting() const;

protected:
	renderer renderer_;

	shared_ptr<on_app_contextable> context_;
	shared_ptr<on_app_bindable> binder_;
	shared_ptr<on_app_executable> executor_;

	vector<string> command_line_;
	string title_;

	bool request_exit_;

	size_t window_width_;
	size_t window_height_;
};

extern applicable* make_application();
}