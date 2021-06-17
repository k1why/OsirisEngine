#pragma once

#include <memory>

#ifdef OSIRIS_PLATFORM_WINDOWS

extern std::unique_ptr<Osiris::Application> Osiris::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Osiris::CreateApplication();
	app->Run();
}

#endif