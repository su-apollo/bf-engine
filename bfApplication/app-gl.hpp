#pragma once
#include "app.hpp"

namespace bf {
class AppGL : public App {
public:
	AppGL();
	virtual ~AppGL();

	virtual bool Initialize(const PlatformInfo& info, int32_t width, int32_t height);

protected:
	virtual bool PlatformInitRendering();
	virtual void PlatformInitUI();
};
}