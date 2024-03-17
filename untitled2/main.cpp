#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "ship.h"
#include "functions.h"

int main() {
    srand(time(NULL));
    std::string ChosenType;
    std::vector<std::string>ShipTypes{"hizli", "guclu", "normal"};
    RapidShip RShip;
    NormalShip NShip;
    HeavyShip HShip;
    MainShip *GameObject= nullptr;

    print();
    std::getline(std::cin, ChosenType);

    ShipChoosing(ShipTypes, ChosenType);

    SetPointer(RShip, HShip, NShip, GameObject, ShipTypes, ChosenType);
    return 0;
}
