#pragma once

#include <string>
#include "HueBridge.h"
#include "HTTPclient.h"

class HueLamp
{
public:
	HueLamp(HueBridge& bridge, std::string& id);

	void TurnOn();
	void TurnOff();

private:
	std::string ID;
	HueBridge Bridge;
};

