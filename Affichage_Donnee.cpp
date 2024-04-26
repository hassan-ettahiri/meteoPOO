#include "Affichage_Donnee.h"
#include <iostream>
#include<time.h>

Affichage_Donnee::Affichage_Donnee(Subject *donneesMeteo){
    temperature = 0;
    humidite = 0;
    pression = 0;
    this->donneesMeteo = donneesMeteo;
    donneesMeteo->registerObserver(this);
}

void Affichage_Donnee::afficher(){
    time_t t=time(0);
    char *dt= ctime(&t);
    std::cout<<"\t\t\t----------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"\n\t\t\t\t\t"<<dt;
    std::cout<<"\t\t\t-----------------------------------------------------------------------------------"<<std::endl;

    std::cout<<"\t\t\tConditions actualles: Temperature ="<<temperature<<"C  Humidite ="<<humidite<<"% Pression ="<<pression<<"%"<<std::endl;

}
void Affichage_Donnee::update(double t, double h, double p){
    temperature = t;
    humidite = h;
    pression = p;

}

