#include <iostream>
#include "Programador.h"

int main()
{
	int numCycle = 10;

	Programador* juan = new Programador(0);
	while (--numCycle)
	{
		juan->Update();
		getchar();		
	}
	delete juan;
	getchar();
	return 0;
}	