#ifndef PROGRAMADOR_STATES
#define PROGRAMADOR_STATES

#include "State.h"


class Programador;

class Program : public State<Programador>
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
	virtual bool OnMessage(Programador* agent, const Telegram& msg);
};


class Sleeping: public State<Programador>
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
	virtual bool OnMessage(Programador* agent, const Telegram& msg);
};


class Global : public State<Programador>
{
private:
	Global(){}
	Global(const Global&);
	Global& operator=(Global&);
public:
	static Global* Instance();
	virtual void Enter(Programador* programador);
	virtual void Execute(Programador* programador);
	virtual void Exit(Programador* programador);
	virtual bool OnMessage(Programador* agent, const Telegram& msg);
};

class DrinkBeer : public State<Programador>
{
private:
	DrinkBeer(){}
	DrinkBeer(const DrinkBeer&);
	DrinkBeer& operator=(DrinkBeer&);
public:
	static DrinkBeer* Instance();
	virtual void Enter(Programador* programador);
	virtual void Execute(Programador* programador);
	virtual void Exit(Programador* programador);
	virtual bool OnMessage(Programador* agent, const Telegram& msg);
};

#endif
