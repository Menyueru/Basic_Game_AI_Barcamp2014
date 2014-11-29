#ifndef PROGRAMADOR_H
#define PROGRAMADOR_H

#include <iostream>
#include "BaseGameEntity.h"
#include "StateMachine.h"
#include "ProgramadorStates.h"

const int tiredTreshold=2;

class Programador : public BaseGameEntity
{
private:
	StateMachine<Programador>* stateMachine;
	int location;
	int tiredness;

public:

	Programador(int id) :location(0), tiredness(0), BaseGameEntity(id)
	{
		stateMachine = new StateMachine<Programador>(this);
		stateMachine->SetCurrentState(Sleeping::Instance());
	}

	~Programador(){ delete stateMachine; }

	void Update();
	StateMachine<Programador>* GetFSM()const{ return stateMachine; }

	void SleepHour(){ tiredness -= 1; }
	void WorkHour(){ tiredness += 1; }

	bool Sleepy()const;
	bool SleepEnough()const;

	void ChangeLocation(int val){ location = val; }
	int Location()const{ return location; }
	int Tiredness()const{ return tiredness; }
};

#endif
