#pragma once
#include "structures.hpp"
#include "app-context.hpp"
#include "platform.hpp"
#include "app-glfw.hpp"

namespace bf {
template <class Platform>
class AppContext : public OnAppContextable {
public:
};

template <>
class AppContext<Windows> : public OnAppContextable{
public:
	AppContext() {
		glfw = make_shared<GLFW>();
	}

	~AppContext() {
	}

	shared_ptr<OnAppBindable> MakeBinder() {
		return glfw;
	}

	shared_ptr<OnAppExecutable> MakeExecutor() {
		return glfw;
	}

private:
	shared_ptr<GLFW> glfw;
};
}