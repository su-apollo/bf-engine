#pragma once
#include "structures.hpp"
#include "app-context.hpp"
#include "platform.hpp"
#include "app-glfw.hpp"

namespace bf {
template <class Platform>
class app_context : public on_app_contextable {
public:
};

template <>
class app_context<windows> : public on_app_contextable{
public:
	app_context() {
		glfw_ = make_shared<glfw>();
	}

	~app_context() = default;

	shared_ptr<on_app_bindable> make_binder() override
	{
		return glfw_;
	}

	shared_ptr<on_app_executable> make_executor() override
	{
		return glfw_;
	}

private:
	shared_ptr<glfw> glfw_;
};
}