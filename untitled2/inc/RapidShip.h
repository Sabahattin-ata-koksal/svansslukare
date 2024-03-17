
#ifndef SVANSSLUKARE_FINAL_RAPIDSHIP_H
#define SVANSSLUKARE_FINAL_RAPIDSHIP_H
#include "ship.h"

class RapidShip : public MainShip {
public:
    RapidShip() : MainShip(){
        escapeX = escapeX * RSexapeX;
        damageX = damageX * RSdamageX;
        std::cout << "constructor of RapidShip" << "\n";
    }

public:
    void incrementMoney() override{
        money = money+10;
    }
    void decrementMoney(int DMvalue) override{
        money = money - DMvalue;
    }
    void decrementFuel() override{
        fuel = fuel-FuelDecremention;
    }
    void decrementHp(float DHvalue) override{
        hp = hp - (DHvalue * damageX);
    }
    void decrementHpAsteroid() override{
        hp = hp - 10;
    }
};


#endif //SVANSSLUKARE_FINAL_RAPIDSHIP_H
