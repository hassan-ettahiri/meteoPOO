#include "StationMeteo.h"
#include <iostream>
#include <list>
#include "Observer.h"

using namespace std;

StationMeteo::StationMeteo(){
    temperature = 0;
    humidite = 0;
    pression = 0;
}

void StationMeteo::registerObserver(Observer* obs){
    observateurs.push_back(obs);
}
void StationMeteo::removeObserver(Observer* obs){
    observateurs.remove(obs);
}

void StationMeteo::notifyObservateurs(){
    list<Observer*>::iterator the_iterator;
    the_iterator = observateurs.begin();
    while( the_iterator != observateurs.end() ) {
        (*the_iterator)->update(temperature,humidite,pression);
        the_iterator++;
    }
}
void StationMeteo::setTemperature(double t){
    temperature = t;
    actualiserMesures();
}
void StationMeteo::setHumidite(double h){
    humidite = h;
    actualiserMesures();
}
void StationMeteo::setPression(double p){
    pression = p;
    actualiserMesures();
}
void StationMeteo::actualiserMesures(){
    notifyObservateurs();
}

StationMeteo::StationMeteo(double temperature, double humidite, double pression): temperature(temperature),humidite(humidite),pression(pression) {}

double StationMeteo::getTemperature() const {
    return temperature;
}

double StationMeteo::getHumidite() const {
    return humidite;
}

double StationMeteo::getPression() const {
    return pression;
}
