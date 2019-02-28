#include "app-base.hpp"
#include "tokenizer.hpp"
#include "platform.hpp"
#include "platform-context.hpp"

#include <Windows.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>

void create_console() {
	if (::AllocConsole())
	{
		auto h_crt = ::_open_osfhandle(reinterpret_cast<intptr_t>(::GetStdHandle(STD_OUTPUT_HANDLE)), _O_TEXT);
		auto hf = ::_fdopen(h_crt, "w");
		const auto so = stdout;
		const auto se = stderr;
		*so = *hf;
		::setvbuf(stdout, nullptr, _IONBF, 0);

		h_crt = ::_open_osfhandle(reinterpret_cast<intptr_t>(::GetStdHandle(STD_ERROR_HANDLE)), _O_TEXT);
		hf = ::_fdopen(h_crt, "w");
		*se = *hf;
		::setvbuf(stderr, nullptr, _IONBF, 0);
	}
}

// program entry
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	create_console();

	std::cout << "Hello World!" << std::endl;

	auto app = bf::make_application();

	const bf::string command_line(lpCmdLine);
	bf::tokenizer t(command_line);

	while (t.next_token()) {
		app->append_command(t.get_token());
	}

	const auto width = 1280;
	const auto height = 720;

	const auto context = bf::make_shared<bf::app_context<bf::windows>>();

	if (!app->initialize(context, width, height))
		exit(EXIT_FAILURE);

	app->main_loop();

	delete app;

	// Exit program
	exit(EXIT_SUCCESS);
}