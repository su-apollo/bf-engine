#pragma once
#include "structures.hpp"
#include "app-context.hpp"
#include "platform.hpp"
#include "app-glfw.hpp"
#include "renderer-opengl.hpp"

namespace bf {
template <class Platform>
class app_context : public app_contextable 
{
};

template <>
class app_context<windows> : public app_contextable 
{
public:
	app_context() 
	{
		glfw_ = make_shared<glfw>();
		opengl_ = make_shared<opengl>();
	}

	~app_context() = default;

	shared_ptr<app_bindable> make_binder() override 
	{
		return glfw_;
	}

	shared_ptr<app_executable> make_executor() override 
	{
		return glfw_;
	}

	shared_ptr<graphic_library> make_gl() override 
	{
		return opengl_;
	}

private:
	shared_ptr<glfw> glfw_;
	shared_ptr<opengl> opengl_;
};

template <>
class app_context<android> : public app_contextable {
public:
	app_context() = default;
	~app_context() = default;

	// todo :
	shared_ptr<app_bindable> make_binder() override {
		return nullptr;
	}

	// todo :
	shared_ptr<app_executable> make_executor() override {
		return nullptr;
	}

	// todo :
	shared_ptr<graphic_library> make_gl() override {
		return nullptr;
	}
};

template <>
class app_context<ios> : public app_contextable {	
public:
	app_context() = default;
	~app_context() = default;

	// todo :
	shared_ptr<app_bindable> make_binder() override {
		return nullptr;
	}

	// todo :
	shared_ptr<app_executable> make_executor() override {
		return nullptr;
	}

	// todo :
	shared_ptr<graphic_library> make_gl() override {
		return nullptr;
	}
};

}