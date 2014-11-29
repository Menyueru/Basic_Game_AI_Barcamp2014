#include "BaseGameEntity.h"

int BaseGameEntity::next_Valid_Id = 0;

void BaseGameEntity::setId(int val)
{
	id = val;
	next_Valid_Id = id + 1;
}