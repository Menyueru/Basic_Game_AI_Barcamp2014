#include "Programador.h"
#include "ProgramadorStates.h"
#include "State.h"
#include "StateMachine.h"
#include "Locations.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include <Windows.h>
#include <iostream>
using std::cout;

Program* Program::Instance()
{
	static Program instance;

	return &instance;
}


void Program::Enter(Programador* programador)
{
	if (programador->Location() != work)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << "\n" << "Juan" << ": " << "Es Hora de ponerse a Trabajar";

		programador->ChangeLocation(work);
	}
}


void Program::Execute(Programador* programador)
{
	programador->WorkHour();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << "\n" << "Juan" << ": " << "Codear es lo maximo";

	if (programador->Sleepy())
	{
		programador->GetFSM()->ChangeState(Sleeping::Instance());
	}
}


void Program::Exit(Programador* programador)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << "\n" << "Juan" << ": " << "Suficiente codeo por hoy";
}

bool Program::OnMessage(Programador* pProgramador, const Telegram& msg)
{
	return false;
}


Sleeping* Sleeping::Instance()
{
	static Sleeping instance;

	return &instance;
}


void Sleeping::Enter(Programador* programador)
{
	if (programador->Location() != house)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << "\n" << "Juan" << ": " << "A dormir un ratico";

		programador->ChangeLocation(house);
	}
}


void Sleeping::Execute(Programador* programador)
{	
	programador->SleepHour();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << "\n" << "Juan" << ": " << "ZZZZZZZZZZZZZZZZZZ";
	if (programador->SleepEnough())
	{
		programador->GetFSM()->ChangeState(Program::Instance());
	}
}


void Sleeping::Exit(Programador* programador)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << "\n" << "Juan" << ": " << "Otra buena siesta!!!!";
}

bool Sleeping::OnMessage(Programador* pProgramador, const Telegram& msg)
{
	return false;
}

Global* Global::Instance()
{
	static Global instance;

	return &instance;
}

void Global::Enter(Programador* programador)
{}


void Global::Execute(Programador* programador)
{
	if (programador->IsBored()){
		programador->GetFSM()->ChangeState(DrinkBeer::Instance());
	}
}


void Global::Exit(Programador* programador)
{}

bool Global::OnMessage(Programador* pProgramador, const Telegram& msg)
{
	return false;
}

DrinkBeer* DrinkBeer::Instance()
{
	static DrinkBeer instance;

	return &instance;
}

void DrinkBeer::Enter(Programador* programador)
{
	if (programador->Location() != bar)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << "\n" << "Juan" << ": " << "Que aburrido estoy, vamos a beber un chin!!";

		programador->ChangeLocation(bar);
		programador->Drink();
		Dispatch->DispatchMessage1(1, programador->ID(), 1, Msg_GiveMeBeer, NO_ADDITIONAL_INFO);
	}
}

void DrinkBeer::Execute(Programador* programador)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	programador->HourInBar();
	if (programador->Has_Drink())
	{
		cout << "\n" << "Juan" << ": " << "Esta buena la cerveza";
		programador->Drink();
	}
	else
	{
		cout << "\n" << "Juan" << ": " << "Esperando mi bebida!!";
	}
	if (programador->NotBored())
	{
		programador->GetFSM()->RevertToPreviousState();
	}
}


void DrinkBeer::Exit(Programador* programador)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << "\n" << "Juan" << ": " << "Suficiente alcohol por ahora";
	programador->FinishDrink();
}

bool DrinkBeer::OnMessage(Programador* programador, const Telegram& msg)
{
	switch (msg.Msg)
	{
	case Msg_BeerReady:
	{
		programador->GetDrink();
		return true;
	}
	}
	return false;
}