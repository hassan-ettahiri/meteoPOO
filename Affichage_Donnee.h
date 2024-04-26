#ifndef PROJET_C___STATION__METEO_AFFICHAGE_DONNEE_H
#define PROJET_C___STATION__METEO_AFFICHAGE_DONNEE_H

#include "Affichage.h"
#include "Observer.h"
#include "Subject.h"
#include "StationMeteo.h"

class Affichage_Donnee : public Affichage, Observer
{
public:
    Affichage_Donnee(Subject *donneesMeteo);
    virtual void afficher();
    virtual void update(double t, double h, double p);

protected:
    Subject* donneesMeteo;
    double temperature;
    double humidite;
    double pression;
};



#endif //PROJET_C___STATION__METEO_AFFICHAGE_DONNEE_H
