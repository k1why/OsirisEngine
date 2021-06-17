#pragma once

#ifdef OSIRIS_PLATFORM_WINDOWS

#include <memory>
extern std::unique_ptr<Osiris::Application> Osiris::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Osiris::CreateApplication();
	app->Run();
}

#endif