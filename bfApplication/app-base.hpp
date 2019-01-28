#pragma once
#include "app-context.hpp"
#include "platform-context.hpp"
#include "allocator.hpp"

#include <thread>

namespace bf {
class AppBase : public InputCallbacks {
public:
	AppBase();
	virtual ~AppBase();

	virtual bool Initialize(const PlatformInfo& info, int width, int height) = 0;
	virtual void MainLoop() = 0;

	virtual void InitRendering();
	virtual void ShutdownRendering();
	virtual void Update();
	virtual void Draw();
	virtual void Reshape(int width, int height);

	void SetTitle(const string& title);
	const string& GetTitle();

protected:
	void AppRequestExit();
	bool IsExiting();

	int window_width;
	int window_height;

	unique_ptr<PlatformContext> platform;
	unique_ptr<AppContext> context;
	string title;

	bool request_exit;
};

extern AppBase* MakeApp();
}