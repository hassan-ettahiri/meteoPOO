#ifndef PROJET_C___STATION__METEO_OBSERVER_H
#define PROJET_C___STATION__METEO_OBSERVER_H
class Observer
{
public:
    virtual void update(double temperature, double humidite, double pression)=0;
};

#endif //PROJET_C___STATION__METEO_OBSERVER_H
