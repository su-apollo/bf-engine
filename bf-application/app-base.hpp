#pragma once
#include "types.hpp"
#include "structures.hpp"
#include "platform.hpp"

#include <thread>

namespace bf {
class AppBase {
public:
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

	void AppendCommand(string command) { command_line.push_back(command); }
	void SetTitle(const string& t) { title = t; }
	void AppRequestExit() { request_exit = true; }
	bool IsExiting() { return request_exit; }

protected:
	vector<string> command_line;
	string title;

	bool request_exit;

	size_t window_width;
	size_t window_height;

	BasicApp() : window_width(0), window_height(0), request_exit(false) {}
};

extern BasicApp* MakeApp();
}