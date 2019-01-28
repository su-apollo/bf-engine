#include "app-gl.hpp"
#include "glfw-context.hpp"
#include "glfw-platform-context.hpp"

namespace bf {
static GLConfig DefaultConfig(GLAPIVersionGL4_4(), 8, 8, 8, 8, 16, 0, 0);

AppGL::AppGL() : App() {
}

AppGL::~AppGL() {
}

bool AppGL::Initialize(const PlatformInfo& info, int32_t width, int32_t height) {
	if (info.os == PlatformOS::OS_ANDROID) {
		/// todo : for android
	}
	else {
		auto p = bf::make_unique<GLFWPlatformContext>();
		auto c = bf::make_unique<GLFWContextGL>(DefaultConfig, info);

		p->CreateGLFWWindow(width, height);
		c->SetGLFWWindow(p->GetGLFWWindow());

		c->SetConfiguration(DefaultConfig);

		c->BindContext();
		p->UpdateWindowSize();

		platform = std::move(p);
		context = std::move(c);
	}
	return true;
}

bool AppGL::PlatformInitRendering() {
	return true;
}

void AppGL::PlatformInitUI() {
	context->InitUI();
}
}