#pragma once

#include <string>
#include "HTTPclient.h"

class HueBridge
{
public:
	HueBridge(std::string& IP, std::string& apiKey);

	std::string IP;
	std::string ApiKey;
	HTTPclient HTTP;
};

