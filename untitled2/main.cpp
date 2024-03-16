#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <ctime>
#include "ship.h"
#include "functions.h"



void print() {
    puts("oyunumuza hosgeldiniz");
    puts("3 tip gemimiz bulunmaktadir hizli gemi, guclu gemi ve normal gemi hangisini secmek istersiniz");
    puts("hizli, guclu veya normal yaziniz");
}
int main() {
    srand(time(NULL));
    std::string ChosenType;
    std::vector<std::string>ShipTypes{"hizli", "guclu", "normal"};
    RapidShip RShip;
    NormalShip NShip;
    HeavyShip HShip;

    std::unique_ptr<MainShip> GameObject{nullptr};
    //MainShip* GameObject= nullptr;

    print();
    std::getline(std::cin, ChosenType);

    ShipChoosing(ShipTypes, ChosenType);


    SetPointer(RShip, HShip, NShip, std::move(GameObject), ShipTypes, ChosenType);
    return 0;
}