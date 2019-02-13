#pragma once
#include "app-base.hpp"

namespace bf {
class AppPlatformBase {
protected:
	virtual bool PlatformInitRendering() = 0;
	virtual void PlatformInitUI() = 0;
	virtual void PlatformShutdownRendering() = 0;
};

class AppUIBase {
};

class App : public BasicApp, public AppPlatformBase {
public:
	virtual void MainLoop();

protected:
	bool PointerInput(InputDeviceType device, PointerActionType action, unsigned int modifiers, int count, PointerEvent* points, long long timestamp = 0);
	bool KeyInput(unsigned int code, KeyActionType action);
	bool CharacterInput(unsigned char c);

	void MainThreadRenderStep();
	void HaltRenderingThread();
	void ShutdownRenderLoopObjects();
	bool ConditionalLaunchRenderingThread();

	void RequestThreadedRendering(bool threaded);
	bool IsRenderThreadRunning();

	void RenderLoopRenderFrame();

	void ShutdownRendering();
	void Update();
	void Draw();
	bool InitRendering();
	void Reshape(const size_t w, const size_t h);

protected:
	// todo : thread pool
	unique_ptr<std::thread> thread;

	bool has_initialized_rendering;
	bool use_render_thread;
	bool render_thread_running;
};


/*
class App : public AppBase {
public:


protected:




};
*/
}