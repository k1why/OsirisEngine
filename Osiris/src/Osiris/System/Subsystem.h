#pragma once

#include "Osiris/System/Base/SystemLocator.h"
#include "Osiris/System/Base/ISubsystem.h"

namespace osiris::system
{
	class Subsystem : public ISubsystem
	{
	public:
		Subsystem(std::weak_ptr<SystemLocator> locator)
			: m_locator(locator)
		{}

	protected:
		std::weak_ptr<SystemLocator> m_locator;
	};
}


