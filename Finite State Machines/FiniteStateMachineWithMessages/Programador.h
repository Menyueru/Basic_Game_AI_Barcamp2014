#ifndef PROGRAMADOR_H
#define PROGRAMADOR_H

#include <iostream>
#include "BaseGameEntity.h"
#include "StateMachine.h"
#include "Locations.h"
#include "ProgramadorStates.h"

const int tiredTreshold = 4;
const int boredTreshold = 2;

class Programador : public BaseGameEntity
{
private:
	StateMachine<Programador>* stateMachine;
	int location;
	int tiredness;
	int bored;
	bool has_drink;

public:

	Programador(int id) :location(house), tiredness(0), bored(0), BaseGameEntity(id)
	{
		stateMachine = new StateMachine<Programador>(this);
		stateMachine->SetCurrentState(Sleeping::Instance());
		stateMachine->SetGlobalState(Global::Instance());
	}

	~Programador(){ delete stateMachine; }

	void Update();
	bool  HandleMessage(const Telegram& msg);
	StateMachine<Programador>* GetFSM()const{ return stateMachine; }

	void SleepHour(){ tiredness -= 1; }
	void WorkHour(){ tiredness += 1; bored += 1; }
	void HourInBar(){tiredness += 1; }
	void Drink(){ bored -= 1; }
	void GetDrink(){ has_drink = true; }
	void FinishDrink(){ has_drink = false; }

	bool Sleepy()const;
	bool SleepEnough()const;

	void ChangeLocation(int val){ location = val; }
	int Location()const{ return location; }
	int Tiredness()const{ return tiredness; }
	int Bored()const{ return bored; }
	int IsBored()const{ return bored>=boredTreshold; }
	int NotBored()const{ return bored<=0; }
	bool Has_Drink()const{ return has_drink; }
};

#endif
