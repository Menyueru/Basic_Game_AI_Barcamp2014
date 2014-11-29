#ifndef BARTENDER_H
#define BARTENDER_H

#include <iostream>
#include "BaseGameEntity.h"
#include "StateMachine.h"
#include "Locations.h"
#include "BartenderStates.h"


class Bartender : public BaseGameEntity
{
private:
	StateMachine<Bartender>* stateMachine;
	int location;
	int gettingBeer;
public:

	Bartender(int id) :location(bar),gettingBeer(0), BaseGameEntity(id)
	{
		stateMachine = new StateMachine<Bartender>(this);
		stateMachine->SetCurrentState(Attend::Instance());
	}

	~Bartender(){ delete stateMachine; }

	void Update();
	bool  HandleMessage(const Telegram& msg);
	void StartLooking(){ gettingBeer = 0; }
	void LookForBeer(){ gettingBeer += 1; }
	StateMachine<Bartender>* GetFSM()const{ return stateMachine; }

	void ChangeLocation(int val){ location = val; }
	int Location()const{ return location; }
	bool GotBeer()const{ return gettingBeer > 1; }
};

#endif
