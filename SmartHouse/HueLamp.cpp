#include "HueLamp.h"

HueLamp::HueLamp(HueBridge& bridge, std::string& id)		//constructor
	:Bridge(bridge), ID(id)
{
}

void HueLamp::TurnOn() {
	Bridge.HTTP.SetURL("https://" + Bridge.IP + "/clip/v2/resource/light/" + ID);

	Bridge.HTTP.PUTrequest("{\"on\":{\"on\":true}}");
}

void HueLamp::TurnOff() {
	Bridge.HTTP.SetURL("https://" + Bridge.IP + "/clip/v2/resource/light/" + ID);

	Bridge.HTTP.PUTrequest("{\"on\":{\"on\":false}}");
}
