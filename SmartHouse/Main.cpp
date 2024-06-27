#include <string>
#include <iostream>
#include "HueBridge.h"
#include "HueLamp.h"
#include "MyHouse.h"    //This header file is just a struct with the bridge ip, api key, and ID of all the lights of my house. It's in .gitignore for safety

int main() {
    MyHouse House;

    HueBridge bridge(House.bridge_ip, House.api_key);

    HueLamp officeCeilingLamp   (bridge, House.officeCeilingLightID);
    HueLamp officeStandLamp     (bridge, House.officeStandLightID);
    HueLamp RoomLamp            (bridge, House.RoomLightID);
    HueLamp LivingRoomLamp      (bridge, House.LivingRoomLightID);


    bool onoff;
    int lamp;

    while (1) {
        std::cout << "What lamp do you wish to control?" << std::endl << "1 = Ceiling, 2 = Stand" << std::endl;
        std::cin >> lamp;
        std::cout << "Turn on (1) | Turn off (0)?" << std::endl;
        std::cin >> onoff;

        switch (lamp) {
            case 1:
                if (onoff)
                    officeCeilingLamp.TurnOn();
                else if (!onoff)
                    officeCeilingLamp.TurnOff();
                break;

            case 2:
                if (onoff)
                    officeStandLamp.TurnOn();
                else if (!onoff)
                    officeStandLamp.TurnOff();
                break;

            default:
                break;
        }

    }
   
}