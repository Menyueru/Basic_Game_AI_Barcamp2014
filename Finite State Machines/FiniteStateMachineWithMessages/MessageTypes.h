#ifndef MESSAGE_TYPES
#define MESSAGE_TYPES

#include <string>

enum message_type
{
	Msg_GiveMeBeer,
	Msg_BeerReady
};


inline std::string MsgToStr(int msg)
{
	switch (msg)
	{
	case Msg_GiveMeBeer:

		return "GiveMeBeer";

	case Msg_BeerReady:

		return "BeerReady";

	default:

		return "Not recognized!";
	}
}

#endif