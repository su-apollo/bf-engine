#pragma once

namespace bf {
enum class Category {
	MOBILE,
	DESKTOP
};

enum class OS {
	ANDROID,
	IOS,
	WINDOWS,
	LINUX,
	OSX
};

class Platform {};

class Android : public Platform {
public:
	static const auto CATEGORY = Category::MOBILE;
	static const auto OS = OS::ANDROID;
};

class IOS : public Platform {
public:
	static const auto CATEGORY = Category::MOBILE;
	static const auto OS = OS::IOS;
};

class Windows : public Platform {
public:
	static const auto CATEGORY = Category::DESKTOP;
	static const auto OS = OS::WINDOWS;
};

class LINUX : public Platform {
public:
	static const auto CATEGORY = Category::DESKTOP;
	static const auto OS = OS::LINUX;
};

class OSX : public Platform {
public:
	static const auto CATEGORY = Category::DESKTOP;
	static const auto OS = OS::OSX;
};
}