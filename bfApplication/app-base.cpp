#include "app-base.h"

namespace bf {
AppBase::AppBase()
: window_width(0), window_height(0), request_exit(false) {
}

AppBase::~AppBase() {
}

void AppBase::InitRendering() {
}

void AppBase::ShutdownRendering() {
}

void AppBase::Update() {
}

void AppBase::Draw() {
}

void AppBase::Reshape(int32_t width, int32_t height) {
}

void AppBase::SetTitle(const string& t) {
	title = t;
}

const string& AppBase::GetTitle() {
	return title;
}

void AppBase::AppRequestExit() {
	request_exit = true;
}

bool AppBase::IsExiting() {
	return request_exit;
}
}