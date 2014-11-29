#include "Bartender.h"
#include "BartenderStates.h"
#include "State.h"
#include "StateMachine.h"
#include "Locations.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include <Windows.h>
#include <iostream>
using std::cout;

Attend* Attend::Instance()
{
	static Attend instance;

	return &instance;
}

void Attend::Enter(Bartender* bartender)
{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "\n" << "Maria" << ": " << "Seguir Trabajando!!";
}

void Attend::Execute(Bartender* bartender)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "\n" << "Maria" << ": " << "Esta Tranquilo el dia hoy";
}


void Attend::Exit(Bartender* bartender)
{}

bool Attend::OnMessage(Bartender* bartender, const Telegram& msg)
{
	switch(msg.Msg)
	{
	case Msg_GiveMeBeer:
	{
		bartender->GetFSM()->ChangeState(PrepareBeer::Instance());
		return true;
	}
	}
	return false;
}

PrepareBeer * PrepareBeer ::Instance()
{
	static PrepareBeer  instance;

	return &instance;
}


void PrepareBeer ::Enter(Bartender* bartender)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "\n" << "Maria" << ": " << "Viniendo cerveza!!!";
	bartender->StartLooking();
}


void PrepareBeer ::Execute(Bartender* bartender)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "\n" << "Maria" << ": " << "Buscando Cerveza!!!";
	bartender->LookForBeer();
	if (bartender->GotBeer())
	{
		bartender->GetFSM()->RevertToPreviousState();
	}
}


void PrepareBeer ::Exit(Bartender* bartender)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "\n" << "Maria" << ": " << "Aqui esta su cerveza!!";
	Dispatch->DispatchMessage1(0, bartender->ID(), 0, Msg_BeerReady, NO_ADDITIONAL_INFO);
}

bool PrepareBeer ::OnMessage(Bartender* bartender, const Telegram& msg)
{
	return false;
}