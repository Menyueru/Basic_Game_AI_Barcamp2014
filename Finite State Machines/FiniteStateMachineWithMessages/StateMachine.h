#ifndef STATE_MACHINE
#define STATE_MACHINE


#include "State.h"

 template <class entity_type>
 class StateMachine
 {
private:
	entity_type* owner;
	State<entity_type>* currentState;
	State<entity_type>* previousState;
	State<entity_type>* globalState;

 public:
	 StateMachine(entity_type* _owner) :owner(_owner), currentState(NULL), previousState(NULL), globalState(NULL)
	 {}
	 virtual ~StateMachine(){}
	 void SetCurrentState(State<entity_type>* s){ currentState = s; }
	 void SetGlobalState(State<entity_type>* s) { globalState = s; }
	 void SetPreviousState(State<entity_type>* s){ previousState = s; }

	 void  Update()const
	 {
		 if (globalState)   globalState->Execute(owner);

		 if (currentState) currentState->Execute(owner);
	 }

	 void  ChangeState(State<entity_type>* newState)
	 {
		 previousState = currentState;

		 currentState->Exit(owner);

		 currentState = newState;

		 currentState->Enter(owner);
	 }

	 bool  HandleMessage(const Telegram& msg)const
	 {
		 if (currentState && currentState->OnMessage(owner, msg))
		 {
			 return true;
		 }

		 if (globalState && globalState->OnMessage(owner, msg))
		 {
			 return true;
		 }

		 return false;
	 }

	 void  RevertToPreviousState()
	 {
		 ChangeState(previousState);
	 }

	 bool  isInState(const State<entity_type>& st)const
	 {
		 if (typeid(*currentState) == typeid(st)) return true;
		 return false;
	 }

	 State<entity_type>*  CurrentState()  const{ return currentState; }
	 State<entity_type>*  GlobalState()   const{ return globalState; }
	 State<entity_type>*  PreviousState() const{ return previousState; }

 };

#endif 
