//
// Created by user on 16.03.2024.
//

#ifndef UNTITLED2_FUNCTIONS_H
#define UNTITLED2_FUNCTIONS_H
#include "ship.h"
#include "RapidShip.h"
#include "NormalShip.h"
#include "HeavyShip.h"

inline void LowerCase(std::string &ToLower);
void ShipChoosing(const std::vector<std::string>& ShipTypes, std::string ChosenType);
void SetPointer(RapidShip &RShip, HeavyShip &HShip, NormalShip &NShip, std::unique_ptr<MainShip>GameObject, const std::vector<std::string>& ShipTypes, const std::string& ChosenType);

#endif //UNTITLED2_FUNCTIONS_H