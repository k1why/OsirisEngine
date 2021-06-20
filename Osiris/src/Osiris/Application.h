#pragma once

#include <memory>

#include "Osiris/Core.h"

namespace Osiris
{
	class OSIRIS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	std::unique_ptr<Application> CreateApplication();
}


