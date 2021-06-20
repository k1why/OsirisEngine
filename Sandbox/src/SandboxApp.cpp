#include <iostream>

#include <memory>

#include <Osiris.h>

class Sandbox : public osiris::Application
{
public:
	Sandbox()
	{

	}

	virtual ~Sandbox()
	{

	}
};

std::shared_ptr<osiris::Application> osiris::Application::CreateApplication()
{
	return std::make_shared<Sandbox>();
}

