#ifndef PROGRAMADOR_STATES
#define PROGRAMADOR_STATES

#include "State.h"


class Programador;

class Program : public State < Programador >
{
private:
	Program(){}
	Program(const Program&);
	Program& operator=(Program&);
public:
	static Program* Instance();
	virtual void Enter(Programador* programador);
	virtual void Execute(Programador* programador);
	virtual void Exit(Programador* programador);
};


class Sleeping: public State < Programador >
{
private:
	Sleeping(){}
	Sleeping(const Sleeping&);
	Sleeping& operator=(Sleeping&);
public:
	static Sleeping* Instance();
	virtual void Enter(Programador* programador);
	virtual void Execute(Programador* programador);
	virtual void Exit(Programador* programador);
};


#endif
