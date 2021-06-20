#include "SystemManager.h"

using namespace osiris::system;

void SystemManager::PreUpdate()
{
	for (auto& item : m_subsystems)
		item.subsystem->PreUpdate();
}

void SystemManager::Update()
{
	for (auto& item : m_subsystems)
		item.subsystem->Update();
}

void SystemManager::PostUpdate()
{
	for (auto& item : m_subsystems)
		item.subsystem->PostUpdate();
}

std::shared_ptr<ISubsystem> SystemManager::LoadSubsystem(int uid)
{
	auto it = std::find_if(m_subsystems.begin(), m_subsystems.end(), [uid](const auto& item) {
		return item.uid == uid;
	});

	if (it != m_subsystems.end())
		return (*it).subsystem;

	return nullptr;
}

bool SystemManager::StoreSubsystem(int uid, std::shared_ptr<ISubsystem> ptr)
{
	if (auto subsystem = LoadSubsystem(uid))
		return false;

	m_subsystems.emplace_back(uid, ptr);

	return true;
}

bool SystemManager::StoreSubsystemAfter(int uid, int dependency_uid, std::shared_ptr<ISubsystem> ptr)
{
	if (auto subsystem = LoadSubsystem(uid))
		return false;

	auto it = std::find_if(m_subsystems.begin(), m_subsystems.end(), [dependency_uid](const auto& item) {
		return item.uid == dependency_uid;
	});

	if (it != m_subsystems.end())
	{
		m_subsystems.insert(++it, { uid, ptr });
	}
	else
	{
		//TODO: static_assert or throw an exception
		m_subsystems.emplace_back(uid, ptr);
	}

	return true;
}

bool SystemManager::StoreSubsystemBefore(int uid, int dependency_uid, std::shared_ptr<ISubsystem> ptr)
{
	if (auto subsystem = LoadSubsystem(uid))
		return false;

	auto it = std::find_if(m_subsystems.begin(), m_subsystems.end(), [dependency_uid](const auto& item) {
		return item.uid == dependency_uid;
	});

	if (it != m_subsystems.end())
	{
		m_subsystems.insert(it, { uid, ptr });
	}
	else
	{
		//TODO: static_assert or throw an exception
		m_subsystems.emplace_back(uid, ptr);
	}

	return true;
}
