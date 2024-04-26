//
// Created by ouchraa on 11/19/22.
//

#ifndef PROJET_C___STATION__METEO_STATIONMETEO_H
#define PROJET_C___STATION__METEO_STATIONMETEO_H


#include "Observer.h"
#include "Subject.h"
#include <iostream>
#include <list>

class StationMeteo: public Subject{
protected:
    std::list<Observer*> observateurs;
    double temperature;
    double humidite;
    double pression;
public:
    StationMeteo();

    StationMeteo(double temperature, double humidite, double pression);

    virtual void registerObserver(Observer* obs);
    virtual void removeObserver(Observer* obs);
    virtual void notifyObservateurs();
    virtual void setTemperature(double t);
    virtual void setHumidite(double h);
    virtual void setPression(double p);
    virtual void actualiserMesures();

    double getTemperature() const;

    double getHumidite() const;

    double getPression() const;

};


#endif //PROJET_C___STATION__METEO_STATIONMETEO_H
