#ifndef SVANSSLUKARE_FINAL_FUNCTIONS_H
#define SVANSSLUKARE_FINAL_FUNCTIONS_H

#include "ship.h"
#include "GameFunction.h"
#include "RapidShip.h"
#include "NormalShip.h"
#include "HeavyShip.h"

void print();
void LowerCase(std::string &ToLower);
void ShipChoosing(const std::vector<std::string>& ShipTypes, std::string ChosenType);
void SetPointer(RapidShip &RShip, HeavyShip &HShip, NormalShip &NShip, MainShip* GameObject, const std::vector<std::string>& ShipTypes, const std::string& ChosenType);

#endif //SVANSSLUKARE_FINAL_FUNCTIONS_H
