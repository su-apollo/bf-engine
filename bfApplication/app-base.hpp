#pragma once
#include "types.hpp"
#include "platform.hpp"
#include "app-context.hpp"
#include "platform-context.hpp"
#include "allocator.hpp"

#include <thread>

namespace bf {
class AppBase : public InputBase {
public:
	virtual ~AppBase() = 0;
	virtual void MainLoop() = 0;
	virtual bool Initialize(const size_t width, const size_t height) = 0;
};

class BasicApp : public AppBase {
public:
	virtual void OnInitRendering() {};
	virtual void OnShutdownRendering() {};
	virtual void OnUpdate() {};
	virtual void OnDraw() {};
	virtual void OnReshape(const size_t width, const size_t height) {};

	void SetTitle(const string& t) { title = t; }
	void AppRequestExit() { request_exit = true; }
	bool IsExiting() { return request_exit; }

protected:
	unique_ptr<PlatformContextBase> platform;
	unique_ptr<AppContextBase> context;
	string title;

	bool request_exit;

	size_t window_width;
	size_t window_height;

	BasicApp() : window_width(0), window_height(0), request_exit(false) {}
};

extern BasicApp* MakeApp();
}