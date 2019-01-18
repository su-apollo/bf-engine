#pragma once
#include "app-base.h"

namespace bf {
class App : public AppBase {
public:
	virtual void InitUI();
	virtual void DrawUI();

	virtual void MainLoop();

protected:
	bool PointerInput(InputDeviceType::Enum device, PointerActionType::Enum action, unsigned int modifiers, int count, PointerEvent* points, long long timestamp = 0);
	bool KeyInput(unsigned int code, KeyActionType::Enum action);
	bool CharacterInput(unsigned char c);

	void MainThreadRenderStep();
	void HaltRenderingThread();
	void ShutdownRenderLoopObjects();
	bool ConditionalLaunchRenderingThread();

	virtual bool PlatformInitRendering() = 0;
	bool BaseInitRendering();

	virtual void PlatformInitUI() = 0;
	void BaseInitUI();
	
	virtual void PlatformShutdownRendering();
	void BaseShutdownRendering();

	void BaseReshape(int w, int h);
	void BaseUpdate();
	void BaseDraw();
	void BaseDrawUI();

	void RequestThreadedRendering(bool threaded);
	bool IsRenderThreadRunning();

	void RenderLoopRenderFrame();

	// todo : thread pool
	unique_ptr<std::thread> thread;

	bool has_initialized_rendering;
	bool use_render_thread;
	bool render_thread_running;
};
}