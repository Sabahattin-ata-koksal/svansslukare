
#include <iostream>
#include "event.h"
#include <thread>

int PiratesChoiceNumber;
bool PiratesChoiceNumberCorrectness;
bool BargainCondition;
static constexpr int HpDecremention{30};

void EventAsteroidBelt(MainShip* object) {
    puts("Asteroid kusagina girmektesiniz!!!");
    std::this_thread::sleep_for(std::chrono::seconds(2));
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

int EventAbandonedPlanet(MainShip* object) {
    puts("Terk edilmis bir gezegen bulundu.");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    int EventAbandonedResult{0};
    EventAbandonedResult = object->AbandonedPlanet();
    if(EventAbandonedResult == 0) {
        object->incrementMoney();
        std::cout <<"Sanslisiniz bu bereketli topraklarda 10 altin buldunuz!" << "\n";
        return 0;
    }
    else {
        std::cout<<"OLAMAZ! Bu gezegende saklanan uzay korsanlari ile karsi karsiyayiz" << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        // burada 1 return edildiğinde GameFunctionda korsanlar çağrılacak
        return 1;
    }
}

void PiratesChoices(MainShip* object){
    int BargainValue{0};
    BargainValue = (object->PiratesBargain());//pazarlık edilecek para miktarı.
    PiratesChoice(object, BargainValue);
}


void PiratesChoice(MainShip* object, int BargainValue) {
    puts("DIKKAT uzay korsanlari hemen onumuzde!");
    std::this_thread::sleep_for(std::chrono::seconds(2));

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
                EventPiratesEscape(object, BargainValue);
            }
            else if (PiratesChoiceNumber == 2){
                EventPiratesFight(object);
            }
            else if (PiratesChoiceNumber == 3){
                EventPiratesBargain(object, BargainValue);
            }
            PiratesChoiceNumberCorrectness = true;
        }
        else {
            std::cout<<"Bu kadar zor degil lutfen gecerli bir sayi giriniz";
        }
    }
}

void EventPiratesFight(MainShip* object){
    std::cout<<"Korsanlarla savasa gidiyoruz tanri turku korusun.\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    int resultFight{0};
    resultFight = object->PiratesFight();
    if (resultFight == 0){
        std::cout<<"Korsanlari tuzla buz ettiniz! \n";
    }
    else {
        object->decrementHp(HpDecremention);
        std::cout<<"Korsanlar ile olan cesur savasimizi kaybettik gemimizin "<< object->getHp() << " kadar cani kaldi \n";
    }
}

void EventPiratesBargain(MainShip* object, int ResultBargain){ // pazarlık edilecek miktarı alır ve eğer eldeki miktar daha büyükse ödenir.

    if (BargainCondition == true){
        object->decrementMoney(ResultBargain);
        std::cout<<"Pazarlik ettiniz ve "<<ResultBargain<<" altin odediniz\n";
    }
    else {
        std::cout<<"Yeterli altininiz yok, pazarlik etmek gibi bir secenegimiz yok...Secenek menusune donuluyor \n";
        PiratesChoice(object, ResultBargain);
    }
}

void EventPiratesEscape(MainShip* object, int ResultBargain){
    int EventEscapeResult{0};
    EventEscapeResult = object->PiratesEscape(object->getEscapeX());
    if (object->getFuel() >= FuelDecremention){
        if (EventEscapeResult == 0){
            object->decrementFuel();
            std::cout<< FuelDecremention << " yakit kaybetmis olsaniz da korsanlardan kacip kurtuldunuz \n";
        }
        else {
            std::cout<<"Korsanlardan kacmayi basaramadiniz... Secenek menusune geri donuyorsunuz\n";
            PiratesChoice(object, ResultBargain);
        }
    }
    else{
        std::cout << "Geminin yeterli yakiti kalmamıs ve zor durumdayiz tek care savasmak veya masaya oturup pazarlik etmek" << "\n";
    }
}
