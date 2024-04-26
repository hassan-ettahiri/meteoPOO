//
// Created by ouchraa on 11/19/22.
//

#ifndef PROJET_C___STATION__METEO_STATISTIQUE_H
#define PROJET_C___STATION__METEO_STATISTIQUE_H


#include "Affichage.h"
#include "Observer.h"
#include "Subject.h"
#include "StationMeteo.h"
#include <fstream>
#include<vector>
class Statistique : public Affichage, Observer
{

protected:
    std::vector<StationMeteo*>Vect;
    Subject* donneesMeteo;
    std::fstream file_current;
    std::fstream file;
    double temperature;
    double minTemperature;
    double maxTemperature;
    double MoyTemperature;

    double humidite;
    double minHumidite;
    double maxHumidite;
    double MoyHumidite;

    double pression;
    double minPression;
    double maxPression;
    double MoyPression;
    double nbSaisirT,nbSaisirH,nbSaisirp;

public:
     Statistique(Subject *donneesMeteo);
    virtual void afficher();
    virtual void update(double t, double h, double p);

};
#endif //PROJET_C___STATION__METEO_STATISTIQUE_H
