#ifndef SVANSSLUKARE_FINAL_EVENT_H
#define SVANSSLUKARE_FINAL_EVENT_H

#include "ship.h"

void EventAsteroidBelt(MainShip* object);
int EventAbandonedPlanet(MainShip* object);
void EventPiratesEscape(MainShip* object, int ResultBargain);
void PiratesChoice(MainShip* object, int BargainValue);
void EventPiratesFight(MainShip* object);
void EventPiratesBargain(MainShip* object, int ResultBargain);
void PiratesChoices(MainShip* object);

#endif //SVANSSLUKARE_FINAL_EVENT_H
