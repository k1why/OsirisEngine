#pragma once

#include <memory>
#include <string_view>

#include "Osiris/Core.h"

namespace osiris::system
{
	class SystemLocator;

	struct OSIRIS_API ISubsystem
	{
		virtual ~ISubsystem() = default;
		
		virtual void PreUpdate() = 0;
		virtual void Update() = 0;
		virtual void PostUpdate() = 0;
	};
}