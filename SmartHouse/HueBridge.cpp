#include "HueBridge.h"

HueBridge::HueBridge(std::string& IP, std::string& apiKey)
	:IP(IP), ApiKey(apiKey)
{
	HTTP.AddHeader("hue-application-key: " + ApiKey);
}