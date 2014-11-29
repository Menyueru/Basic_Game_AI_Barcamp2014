#include "EntityManager.h"
#include "BaseGameEntity.h"

EntityManager* EntityManager::Instance()
{
	static EntityManager instance;

	return &instance;
}


BaseGameEntity* EntityManager::GetEntityFromID(int id)const
{
	EntityMap::const_iterator ent = Entities.find(id);

	return ent->second;
}


void EntityManager::RemoveEntity(BaseGameEntity* pEntity)
{
	Entities.erase(Entities.find(pEntity->ID()));
}


void EntityManager::RegisterEntity(BaseGameEntity* NewEntity)
{
	Entities.insert(std::make_pair(NewEntity->ID(), NewEntity));
}
