#include "HueBridge.h"

HueBridge::HueBridge(std::string& IP, std::string& apiKey)
	:IP(IP), ApiKey(apiKey)
{
	HTTP.AddHeader("hue-application-key: " + ApiKey);
}

void HueBridge::GetDevices() {
	HTTP.SetURL("https://" + IP + "/clip/v2/resource/device");
	std::ofstream devicesFile("PhillipsDevicesOnNetwork.txt");	//file on .gitignore
	HTTP.GETrequest(devicesFile);
}