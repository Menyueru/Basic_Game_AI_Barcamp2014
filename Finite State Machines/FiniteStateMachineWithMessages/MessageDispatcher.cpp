#include "MessageDispatcher.h"
#include "BaseGameEntity.h"
#include "EntityManager.h"
#include "Locations.h"
#include "MessageTypes.h"

#include <time.h>
#include <iostream>
using std::cout;

using std::set;

MessageDispatcher* MessageDispatcher::Instance()
{
	static MessageDispatcher instance;

	return &instance;
}

void MessageDispatcher::Discharge(BaseGameEntity* pReceiver,
	const Telegram& telegram)
{
	if (!pReceiver->HandleMessage(telegram))
	{
		
		cout << "Message not handled";
	}
}

void MessageDispatcher::DispatchMessage1(double  delay,int sender,int receiver,int msg,void* ExtraInfo)
{
	BaseGameEntity* pSender = EntityMgr->GetEntityFromID(sender);
	BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(receiver);

	if (pReceiver == NULL)
	{
		cout << "\nWarning! No Receiver with ID of " << receiver << " found";

		return;
	}

	Telegram telegram(0, sender, receiver, msg, ExtraInfo);

	if (delay <= 0.0f)
	{
		Discharge(pReceiver, telegram);
	}

	
	else
	{
		double CurrentTime = clock();

		telegram.DispatchTime = CurrentTime + delay;
		
		PriorityQ.insert(telegram);
	}
}


void MessageDispatcher::DispatchDelayedMessages()
{

	double CurrentTime = clock();

	while (!PriorityQ.empty() &&
		(PriorityQ.begin()->DispatchTime < CurrentTime) &&
		(PriorityQ.begin()->DispatchTime > 0))
	{
		
		const Telegram& telegram = *PriorityQ.begin();
				
		BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(telegram.Receiver);

		Discharge(pReceiver, telegram);
		
		PriorityQ.erase(PriorityQ.begin());
	}
}



