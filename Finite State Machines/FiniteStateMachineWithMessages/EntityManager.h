#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <map>
#include <string>


class BaseGameEntity;

#define EntityMgr EntityManager::Instance()

class EntityManager
{
private:

	typedef std::map<int, BaseGameEntity*> EntityMap;

private:


	EntityMap Entities;

	EntityManager(){}


	EntityManager(const EntityManager&);
	EntityManager& operator=(const EntityManager&);

public:

	static EntityManager* Instance();

	void            RegisterEntity(BaseGameEntity* newEntity);


	BaseGameEntity* GetEntityFromID(int id)const;

	void            RemoveEntity(BaseGameEntity* entity);
};

#endif