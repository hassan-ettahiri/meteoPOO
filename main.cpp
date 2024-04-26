#include <iostream>
#include "StationMeteo.h"
#include "Affichage_Donnee.h"
#include "Statistique.h"

using namespace std;

int main() {

    StationMeteo *SM=new StationMeteo();
    Affichage* Affiche_donneActu=new Affichage_Donnee(SM);
    Affichage* Affiche_statistique=new Statistique(SM);
    double t,h,p;string line;
        int choix=1;
        cout<<"\n\n\n";
        cout <<"\n                    Temperature actuelle               :";cin>>t;
        cout <<"\n                    Humidite actuelle  %               :";cin>>h;
        cout <<"\n                    Pression actuelle  %               :";cin>>p;

        system("cls");
        SM->setTemperature(t);SM->setHumidite(h);SM->setPression(p);

        Affiche_donneActu->afficher();
        Affiche_statistique->afficher();
        while(choix){
                    cout<<"\n\n\n";
                    cout<<"\n                      Saisir les donnee actuelle ...........................:1";
                    cout<<"\n                      Affiche tous les donnee...............................:2";
                    cout<<"\n                      Quitter ..............................................:0";
                    cout<<"\n                                       votre choix :";
                    do{cin>>choix;}while(choix!=1&&choix!=2&&choix!=0);
                    system("cls");
                    Affiche_donneActu->afficher();
                     Affiche_statistique->afficher();
                    if(choix==1){
                        cout<<"\n\n\n";
                        cout <<"\n                    Temperature actuelle               :";cin>>t;
                        cout <<"\n                    Humidite actuelle  %               :";cin>>h;
                        cout <<"\n                    Pression actuelle  %               :";cin>>p;

                        system("cls");
                        SM->setTemperature(t);SM->setHumidite(h);SM->setPression(p);
                        Affiche_donneActu->afficher();
                        Affiche_statistique->afficher();
                    }
                    else if(choix==2){
                        system("cls");
                        ifstream ifd;

                    ifd.open("file.txt");
                        string Line;
                        while(getline(ifd,Line)){
                            cout<<Line<<endl;
                        }
                        system("pause");
                        system("cls");
                    }
        }
    return 0;
}
