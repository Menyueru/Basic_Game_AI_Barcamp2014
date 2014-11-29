#include "Programador.h"

void Programador::Update()
{
	stateMachine->Update();
}

bool Programador::Sleepy()const
{
	return tiredness >= tiredTreshold;
}

bool Programador::SleepEnough()const
{
	return tiredness <= 0;
}

bool Programador::HandleMessage(const Telegram& msg)
{
	return stateMachine->HandleMessage(msg);
}