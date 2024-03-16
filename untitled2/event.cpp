//
// Created by user on 15.03.2024.
//
#include <iostream>
#include "event.h"

int PiratesChoiceNumber;
bool PiratesChoiceNumberCorrectness;
bool BargainCondition;


void EventAsteroidBelt(std::unique_ptr<MainShip>object) {
    puts("Asteroid kusagina girmektesiniz!!!");
    int EventAsteroidResult{0}; // 0 gelirse hasar almıyor öbür ihtimalde hasar alıyor.
    EventAsteroidResult = object->AsteroidBelt(object->getEscapeX());
    if(EventAsteroidResult == 0) {
        std::cout <<"Sanslisiniz geminiz asteroidlerden kacti geminiz hasar almayacak!" <<"\n";
    }
    else {
        object->decrementHpAsteroid();
        std::cout <<"Olamaz geminize asteroid carpti 10 hasar aldiniz!" <<"\n";
    }
}

int EventAbandonedPlanet(std::unique_ptr<MainShip>object) {
    puts("Terk edilmis bir gezegen bulundu.");
    int EventAbandonedResult{0};
    EventAbandonedResult = object->AbandonedPlanet();
    if(EventAbandonedResult == 0) {
        object->incrementMoney();
        std::cout <<"Sanslisiniz bu bereketli topraklarda 10 altin buldunuz!" << "\n";
        return 0;
    }
    else {
        std::cout<<"OLAMAZ! Bu gezegende saklanan uzay korsanlari ile karsi karsiyayiz" << "\n";
        // burada 1 return edildiğinde GameFunctionda korsanlar çağrılacak
        return 1;
    }
}


void PiratesChoices(std::unique_ptr<MainShip>object) {
    puts("DIKKAT uzay korsanlari hemen onumuzde!");
    int BargainValue{0};
    BargainValue = (object->PiratesBargain()); //pazarlık edilecek para miktarı.
    if(BargainValue <= object->getMoney()){
        BargainCondition = true;
    }
    else if(BargainValue > object->getMoney()){
        BargainCondition = false;
    }

    PiratesChoiceNumberCorrectness = false; // her defasında kontrol ediyor
    PiratesChoiceNumber = 0;
    std::cout<<"Kacmak icin (1), savasmak icin (2), pazarlik etmek icin (3)(-"<<BargainValue<<" altin)"<<"\n";
    while (!PiratesChoiceNumberCorrectness){
        std::cout<<"Ne yapmak istediginizi giriniz:";
        std::cin>>PiratesChoiceNumber;
        if (PiratesChoiceNumber == 1 || PiratesChoiceNumber == 2 || PiratesChoiceNumber == 3){
            if (PiratesChoiceNumber == 1){
                EventPiratesEscape(std::move(object));
            }
            else if (PiratesChoiceNumber == 2){
                EventPiratesFight(std::move(object));
            }
            else if (PiratesChoiceNumber == 3){
                EventPiratesBargain(std::move(object));
            }
            PiratesChoiceNumberCorrectness = true;
        }
        else {
            std::cout<<"Bu kadar zor degil lutfen gecerli bir sayi giriniz";
        }
    }
}

void EventPiratesFight(std::unique_ptr<MainShip>object){
    std::cout<<"Korsanlarla savasa gidiyoruz tanri turku korusun.\n";
    int resultFight{0};
    resultFight = object->PiratesFight();
    if (resultFight == 0){
        std::cout<<"Korsanlari tuzla buz ettiniz! \n";
    }
    else {
        object->decrementHp(30);
        std::cout<<"Korsanlar ile olan cesur savasimizi kaybettik gemimizin"<< object->getHp() << "kadar cani kaldi \n";
    }
}

void EventPiratesBargain(std::unique_ptr<MainShip>object){ // pazarlık edilecek miktar hesaplanır ve eğer eldeki miktar daha büyükse ödenir.
    int ResultBargain;
    ResultBargain = 0;
    ResultBargain = object->PiratesBargain();
    if (BargainCondition == true){
        object->decrementMoney(ResultBargain);
        std::cout<<"Pazarlik ettiniz ve "<<ResultBargain<<" altin odediniz\n";
    }
    else {
        std::cout<<"Yeterli altinimiz yok, pazarlik etmek gibi bir secenegimiz yok...Secenek menusune donuluyor\n";
        PiratesChoices(std::move(object));
    }
}

void EventPiratesEscape(std::unique_ptr<MainShip>object){
    int EventEscapeResult{0};
    EventEscapeResult = object->PiratesEscape(object->getEscapeX());
    if (object->getFuel()>= 33){
        if (EventEscapeResult == 0){
            object->decrementFuel();
            std::cout<<"33 yakit kaybetmis olsaniz da korsanlardan kacip kurtuldunuz\n";
        }
        else {
            std::cout<<"Korsanlardan kacmayi basaramadiniz... Secenek menusune geri donuyorsunuz\n";
            PiratesChoices(std::move(object));
        }
    }
    else{
        std::cout << "Geminin yeterli yakiti kalmamıs ve zor durumdayiz tek care savasmak veya masaya oturup pazarlik etmek" << "\n";
    }
}