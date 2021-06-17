#include <memory>

#include <Osiris.h>

class Sandbox : public Osiris::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

std::unique_ptr<Osiris::Application> Osiris::CreateApplication()
{
	return std::make_unique<Sandbox>();
}