#include "Programador.h"
#include "ProgramadorStates.h"
#include "State.h"
#include "StateMachine.h"
#include <conio.h>
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
	if (programador->Location() != 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << "\n" << "Juan" << ": " << "Es Hora de ponerse a Trabajar";

		programador->ChangeLocation(1);
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


Sleeping* Sleeping::Instance()
{
	static Sleeping instance;

	return &instance;
}


void Sleeping::Enter(Programador* programador)
{
	if (programador->Location() != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << "\n" << "Juan" << ": " << "A dormir un ratico";

		programador->ChangeLocation(0);
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