#pragma once

#include "Osiris/Core.h"
#include "Osiris/System/Base/ISubsystem.h"

#include "Osiris/Common/Utils/Ctti.h"

namespace osiris::system
{
	class OSIRIS_API SystemLocator
	{
	public:
		template <typename tSubsystem>
		std::shared_ptr<tSubsystem> Load(std::shared_ptr<tSubsystem> ptr)
		{
			std::static_pointer_cast<T>(LoadSubsystem(utils::ctti::GetClassUID<tSubsystem>()));
		}

		template <typename tSubsystem>
		bool Store(int uid, std::shared_ptr<tSubsystem> ptr)
		{
			return StoreSubsystem(utils::ctti::GetClassUID<tSubsystem>(), std::static_pointer_cast<ISubsystem>(ptr));
		}

		template <typename tSubsystem, typename tDependency>
		bool StoreAfter(int uid, std::shared_ptr<tSubsystem> ptr)
		{
			return StoreSubsystemAfter(utils::ctti::GetClassUID<tSubsystem>(), utils::ctti::GetClassUID<tDependency>(), std::static_pointer_cast<ISubsystem>(ptr));
		}

		template <typename tSubsystem, typename tDependency>
		bool StoreBefore(int uid, std::shared_ptr<tSubsystem> ptr)
		{
			return StoreSubsystemBefore(utils::ctti::GetClassUID<tSubsystem>(), utils::ctti::GetClassUID<tDependency>(), std::static_pointer_cast<ISubsystem>(ptr));
		}

		virtual ~SystemLocator() = default;

	protected:
		virtual std::shared_ptr<ISubsystem> LoadSubsystem(int uid) = 0;

		virtual bool StoreSubsystem(int uid, std::shared_ptr<ISubsystem> ptr) = 0;
		virtual bool StoreSubsystemAfter(int uid, int dependency_uid, std::shared_ptr<ISubsystem> ptr) = 0;
		virtual bool StoreSubsystemBefore(int uid, int dependency_uid, std::shared_ptr<ISubsystem> ptr) = 0;
	};
}