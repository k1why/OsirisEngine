#pragma once

#include <list>

#include "Osiris/System/Base/SystemLocator.h"

namespace osiris::system
{
	class OSIRIS_API SystemManager : public SystemLocator
	{
		struct SubsystemItem
		{
			SubsystemItem(int class_uid, std::shared_ptr<ISubsystem> ptr)
				: uid(class_uid), subsystem(ptr)
			{}

			int uid;
			std::shared_ptr<ISubsystem> subsystem;
		};

	public:
		virtual ~SystemManager() = default;

		void PreUpdate();
		void Update();
		void PostUpdate();

	private:
		virtual std::shared_ptr<ISubsystem> LoadSubsystem(int uid) override;

		virtual bool StoreSubsystem(int uid, std::shared_ptr<ISubsystem> ptr) override;
		virtual bool StoreSubsystemAfter(int uid, int dependency_uid, std::shared_ptr<ISubsystem> ptr) override;
		virtual bool StoreSubsystemBefore(int uid, int dependency_uid, std::shared_ptr<ISubsystem> ptr) override;

	private:
		std::list<SubsystemItem> m_subsystems;
	};
}