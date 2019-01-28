#pragma once
#include "gl-api.hpp"
#include "gfx-config.hpp"
#include "app-context.hpp"
#include "allocator.hpp"

namespace bf {
struct GLConfig : public GfxConfig {
	GLConfig(const GfxConfig& gfx
	, const GLAPIVersion& api = GLAPIVersionES2())
	: GfxConfig(gfx)
	, version(api) {}

	GLConfig(const GLAPIVersion& api = GLAPIVersionES2()
	, uint32_t r = 8, uint32_t g = 8
	, uint32_t b = 8, uint32_t a = 8
	, uint32_t d = 24, uint32_t s = 0, uint32_t msaa = 0)
	: GfxConfig(r, g, b, a, d, s, msaa)
	, version(api) {}

	GLAPIVersion version;
};

class AppContextGL : public AppContext {
public:
	virtual ~AppContextGL();

	virtual void PlatformReshape(const int32_t w, const int32_t h);

protected:
	AppContextGL(const PlatformInfo& info);

	GLConfig config;

	int32_t window_width;
	int32_t window_height;
};
}