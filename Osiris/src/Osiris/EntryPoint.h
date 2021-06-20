#pragma once

#ifdef OSIRIS_PLATFORM_WINDOWS

int main(int argc, char** argv)
{
	auto app = osiris::Application::CreateApplication();
	app->Run();
}

#endif