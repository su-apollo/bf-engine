#pragma once
#include "types.hpp"
#include "structures.hpp"
#include "platform.hpp"
#include "Renderer.hpp"
#include "app-context.hpp"

#include <thread>

namespace bf {
class Applicable {
public:
	virtual void AppendCommand(const string& command) = 0;
	virtual bool Initialize(const shared_ptr<OnAppContextable>& context, const size_t width, const size_t height) = 0;
	virtual void MainLoop() = 0;
};

class Application : public Applicable {
public:
	Application();
	~Application();

	void AppendCommand(const string& command);
	bool Initialize(const shared_ptr<OnAppContextable>& context, const size_t width, const size_t height);
	void MainLoop();
	
	void Update();
	void SetTitle(const string& t);
	void RequestExit();
	bool IsExiting();

protected:
	Renderer renderer;

	shared_ptr<OnAppContextable> context;
	shared_ptr<OnAppBindable> binder;
	shared_ptr<OnAppExecutable> executor;

	vector<string> command_line;
	string title;

	bool request_exit;

	size_t window_width;
	size_t window_height;
};

extern Applicable* MakeApplication();
}