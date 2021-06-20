#pragma once

#include <memory>

#include "Osiris/Core.h"

namespace osiris
{
	class OSIRIS_API Application
	{
	public:
		static std::shared_ptr<Application> CreateApplication();

		Application();
		virtual ~Application();

		void Run();
	};
}


