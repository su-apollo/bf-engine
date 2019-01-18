#pragma once
//#include <memory-pool.h>

namespace bf {
struct PlatformCategory {
	enum Enum {
		PLAT_MOBILE, ///< Mobile/handheld platform
		PLAT_DESKTOP ///< Desktop/laptop-class platform
	};
};

struct PlatformOS {
	enum Enum {
		OS_ANDROID, ///< Android
		OS_IOS,		///< iPhone
		OS_WINDOWS, ///< Windows
		OS_LINUX,	///< "Desktop" Linux
		OS_MACOSX	///< MacOS
	};
};

struct PlatformInfo {
	PlatformInfo(PlatformCategory::Enum c, PlatformOS::Enum o)
	: category(c) 
	, os(o) {}

	PlatformCategory::Enum category; ///< Platform GPU category
	PlatformOS::Enum os; ///< Platform OS
};

class AppContext /*: public PooledAllocatable*/ {
public:
	virtual ~AppContext() {}

	virtual bool BindContext() = 0;
	virtual bool UnbindContext() = 0;

	virtual int Width() = 0;
	virtual int Height() = 0;

	virtual bool Swap() = 0;

	virtual void ContextInitRendering();
	virtual void PlatformReshape(const int w, const int h);

	virtual void BeginFrame();
	virtual void BeginScene();
	virtual void EndScene();
	virtual void EndFrame();

	virtual void InitUI();

protected:
	AppContext(const PlatformInfo& info) : platform_info(info) {}
	PlatformInfo platform_info;
};
}
