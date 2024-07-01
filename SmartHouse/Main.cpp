#include <string>
#include <iostream>
#include "HueBridge.h"
#include "HueLamp.h"
#include "MyHouse.h"    //This header file is just a struct with the bridge ip, api key, and ID of all the lights of my house. It's in .gitignore for safety

int lamp;

int ChooseLamp() {
    std::cout << "What lamp do you wish to control?" << std::endl << "0 = Ceiling, 1 = Stand, 2 = Room, 3 = Living Room" << std::endl;
    std::cin >> lamp;
    return lamp;
}

void ControlLamp(HueLamp& lamp, bool onoff) {
    if (onoff)
        lamp.TurnOn();
    else if (!onoff)
        lamp.TurnOff();

    //return;
}


int main() {
    MyHouse House;

    HueBridge bridge(House.bridge_ip, House.api_key);

    HueLamp officeCeilingLamp   (bridge, House.officeCeilingLightID);
    HueLamp officeStandLamp     (bridge, House.officeStandLightID);
    HueLamp RoomLamp            (bridge, House.RoomLightID);
    HueLamp LivingRoomLamp      (bridge, House.LivingRoomLightID);

    bridge.GetDevices();

    int onoff;
    
    lamp = ChooseLamp();
    system("cls");

    while (1) {

        std::cout << "Turn off (0) | Turn on (1) | Choose a new Lamp (2)" << std::endl;
        std::cin >> onoff;
        system("cls");

        if (onoff == 2)
        {
            ChooseLamp();
            system("cls");
        }

        switch (lamp) {
        case 0:
            ControlLamp(officeCeilingLamp, static_cast<bool>(onoff));
            break;

        case 1:
            ControlLamp(officeStandLamp, static_cast<bool>(onoff));
            break;
        case 2:
            ControlLamp(RoomLamp, static_cast<bool>(onoff));
            break;
        case 3:
            ControlLamp(LivingRoomLamp, static_cast<bool>(onoff));
            break;
        default:
            break;
        }

    }
   
}