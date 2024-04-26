#ifndef PROJET_C___STATION__METEO_SUBJECT_H
#define PROJET_C___STATION__METEO_SUBJECT_H

#include "Observer.h"

class Subject
{
public:
    virtual void registerObserver(Observer* obs)=0;
    virtual void removeObserver(Observer* obs)=0;
    virtual void notifyObservateurs()=0;
};


#endif //PROJET_C___STATION__METEO_SUBJECT_H
