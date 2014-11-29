#ifndef ENTITY_H
#define ENTITY_H

class BaseGameEntity
{
private:
	int id;
	static int next_Valid_Id;
	void setId(int val);
public:
	BaseGameEntity(int _id)
	{
		setId(_id);
	}

	virtual ~BaseGameEntity(){}

	virtual void Update() = 0;

	int ID(){ return id; }
};

#endif