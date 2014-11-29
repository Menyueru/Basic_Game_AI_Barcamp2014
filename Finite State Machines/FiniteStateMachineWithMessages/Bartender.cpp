#include "Bartender.h"

void Bartender::Update()
{
	stateMachine->Update();
}

bool Bartender::HandleMessage(const Telegram& msg)
{
	return stateMachine->HandleMessage(msg);
}
