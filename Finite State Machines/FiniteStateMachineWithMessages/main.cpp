#include <iostream>
#include <Windows.h>
#include "Programador.h"
#include "Bartender.h"
#include "EntityManager.h"
#include "MessageDispatcher.h"

int main()
{
	int numCycle = 30;

	Programador* juan = new Programador(0);
	Bartender* maria = new Bartender(1);
	EntityMgr->RegisterEntity(juan);
	EntityMgr->RegisterEntity(maria);
	while (--numCycle)
	{
		juan->Update();
		maria->Update();
		Dispatch->DispatchDelayedMessages();
		Sleep(2000);
	}
	delete juan;
	delete maria;
	getchar();
	return 0;
}	