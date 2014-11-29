#ifndef BARTENDER_STATES
#define BARTENDER_STATES

#include "State.h"
#include "Telegram.h"


class Bartender;

class Attend : public State<Bartender>
{
private:
	Attend(){}
	Attend(const Attend&);
	Attend& operator=(Attend&);
public:
	static Attend* Instance();
	virtual void Enter(Bartender* bartender);
	virtual void Execute(Bartender* bartender);
	virtual void Exit(Bartender* bartender);
	virtual bool OnMessage(Bartender* agent, const Telegram& msg);
};


class PrepareBeer : public State<Bartender>
{
private:
	PrepareBeer(){}
	PrepareBeer(const PrepareBeer&);
	PrepareBeer& operator=(PrepareBeer&);
public:
	static PrepareBeer* Instance();
	virtual void Enter(Bartender* bartender);
	virtual void Execute(Bartender* bartender);
	virtual void Exit(Bartender* bartender);
	virtual bool OnMessage(Bartender* agent, const Telegram& msg);
};

#endif
