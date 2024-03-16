//
// Created by user on 15.03.2024.
//

#ifndef UNTITLED2_EVENT_H
#define UNTITLED2_EVENT_H
#include "ship.h"



void EventAsteroidBelt(std::unique_ptr<MainShip>object);
int EventAbandonedPlanet(std::unique_ptr<MainShip>object);
void EventPiratesEscape(std::unique_ptr<MainShip>object);
void PiratesChoices(std::unique_ptr<MainShip>object);
void EventPiratesFight(std::unique_ptr<MainShip>object);
void EventPiratesBargain(std::unique_ptr<MainShip>object);
#endif //UNTITLED2_EVENT_H
