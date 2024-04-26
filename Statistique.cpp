#include "Statistique.h"
#include "StationMeteo.h"
#include <iostream>
#include <vector>
#include<fstream>
#include<ctime>
using namespace std;

Statistique::Statistique(Subject *donneesMeteo){
    nbSaisirT=nbSaisirH=nbSaisirp=0;

    temperature = 0;
    minTemperature = 100;
    maxTemperature = -100;

    humidite = 0;
    minHumidite = 100;
    maxHumidite = 0;

    pression = 0;
    minPression = 100;
    maxPression = 0;
    MoyTemperature=0; MoyHumidite=0;MoyPression=0;
    this->donneesMeteo = donneesMeteo;
    donneesMeteo->registerObserver(this);
}

void Statistique::afficher(){
    time_t t=time(0);
    char *dt= ctime(&t);
    file_current.open("file_cureent.txt",ios::in|ios::out);
    file.open("file.txt",ios::app|ios::ate|ios::in|ios::out);
    ofstream of;
    of.open("file.txt",ios::app|ios::ate|ios::in|ios::out);
    cout<<"\t\t\t-----------------------------------------------------------------------------------"<<std::endl;

    cout<<"\n\t\t\tDonnee\t\t\t\tMax\t\tMin\t\tMoy"<<endl;
    cout<<"\t\t\tTemperature\t\t\t"<<maxTemperature<<"\t\t"<<minTemperature<<"\t\t"<<MoyTemperature<<endl;
    cout<<"\t\t\tHumidite\t\t\t"<<maxHumidite<<"%\t\t"<<minHumidite<<"%\t\t"<<MoyHumidite<<endl;
    cout<<"\t\t\tPression\t\t\t"<<maxPression<<"\t\t"<<minPression<<"\t\t"<<MoyPression<<endl;
    cout<<"\t\t\t-----------------------------------------------------------------------------------"<<std::endl;

    of<<"\t\t "<<dt;
    of<<" Temp=" << temperature <<"  Temp max="<< maxTemperature <<"     Temp min="<< minTemperature<<"   Temp moy="<< MoyTemperature<<std::endl ;
    of<<" Hum="  << humidite    <<"  Hum  max="<< maxHumidite    <<"     Hum min="<< minHumidite    <<"   Hum moy="<< MoyHumidite<<std::endl ;
    of<<" Pres=" << pression    <<"  Pres max="<< maxPression    <<"     Pres min="<< minPression   <<"   Pres moy="<<MoyPression <<std::endl ;
    of<<"-------------------------------------------------------------------------------- ------------"<<std::endl;

    file_current<<"\t\t "<<dt;
    file_current<<" Temp=" << temperature <<";  T max="<< maxTemperature <<";  T min="<< minTemperature<<";  T moy="<< MoyTemperature<<std::endl ;
    file_current<< " Hum=  " << humidite <<";  H max="<< maxHumidite <<";  H min="<< minHumidite <<";  H moy="<< MoyHumidite<<std::endl ;
    file_current << " Pres=" << pression <<";  P max="<< maxPression <<";  P min="<< minPression <<";  P moy="<<MoyPression <<std::endl ;
    file_current<<"-------------------------------------------------------------------------------- ------------"<<std::endl;

    of.close();
    file_current.close();
}

void Statistique::update(double t, double h, double p){
    if(temperature !=t){
        temperature = t;
        if (temperature < minTemperature){
            minTemperature = temperature;
        }
        if(temperature > maxTemperature){
            maxTemperature = temperature;
        }
         MoyTemperature=(MoyTemperature*nbSaisirT+temperature)/(nbSaisirT+1);nbSaisirT++;
    }
    if(humidite != h){
        humidite = h;
        if (temperature < minHumidite){
            minHumidite = humidite;
        }
        if(temperature > maxHumidite){
            maxHumidite = humidite;
        }
        MoyHumidite=(MoyHumidite*nbSaisirH+humidite)/(nbSaisirH+1);nbSaisirH++;
    }
    if(pression !=p){
        pression = p;
        if (temperature < minPression){
            minPression = pression;
        }
        if(temperature > maxPression){
            maxPression = pression;
        }
        MoyPression=(MoyPression*nbSaisirp+pression)/(nbSaisirp+1);nbSaisirp++;

    }
     Vect.push_back(new StationMeteo(temperature,humidite,pression));
    double sum;
    sum=0;
    for (int i=0;i<Vect.size();i++){
        sum+=Vect[i]->getTemperature();
    }
    MoyTemperature=sum/Vect.size();

    sum=0;
    for (int i=0;i<Vect.size();i++){
        sum+=Vect[i]->getHumidite();
    }
    MoyHumidite=sum/Vect.size();

    sum=0;
    for (int i=0;i<Vect.size();i++){
        sum+=Vect[i]->getPression();
    }
    MoyPression=sum/Vect.size();
}

