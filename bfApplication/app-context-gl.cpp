#include "app-context-gl.h"

namespace bf {
AppContextGL::AppContextGL(const PlatformInfo& info) 
: AppContext(info), window_width(0), window_height(0) {
}

AppContextGL::~AppContextGL() {
}

void AppContextGL::PlatformReshape(const int32_t w, const int32_t h) {
	window_width = w;
	window_height = h;

	// todo : frame buffer
}
}