#pragma once

#include <string>
#include <fstream>
#include "HTTPclient.h"

class HueBridge
{
public:
	HueBridge(std::string& IP, std::string& apiKey);

	void GetDevices();

	std::string IP;
	std::string ApiKey;
	HTTPclient HTTP;
};

