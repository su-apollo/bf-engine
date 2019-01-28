#include "app-context.hpp"

namespace bf {
void AppContext::ContextInitRendering() {
}

void AppContext::PlatformReshape(const int w, const int h) {
}

void AppContext::BeginFrame() {
}

void AppContext::BeginScene() {
}

void AppContext::EndScene() {
}

void AppContext::EndFrame() {
	Swap();
}

void AppContext::InitUI() {
}
}