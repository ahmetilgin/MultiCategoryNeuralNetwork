﻿#ifndef SINIRAGI_H
#define SINIRAGI_H
#include "noron.h"
#include "siniflar.h"
#include <vector>
#include <sstream>
using namespace std;

#define ORNEKSAYISI 2
#define GIRISSAYISI 3
#define CIKISSAYISI 1
#define SINIFSAYISI 2
#define ARAKATMANSAYISI 2
#define CIKISNORONSAYISI 1
#define FTUREVI 0.5
#define KATMANSAYISI 1
#define GIRISKATMANINORONSAYISI 5
#define EN 600
#define BOY 600





class SinirAgi
{

    double beklenenHataMiktari = 0.1;
    double mu = 1.0;
    double suAnkiHataMiktari=0;
    double standartSapma[SINIFSAYISI][GIRISSAYISI];
    double ortalama[SINIFSAYISI][GIRISSAYISI];


public:
    SinirAgi();
    Siniflar Sinif[SINIFSAYISI];
    vector <Noron> noron[KATMANSAYISI];
    void InitNetwork();
    void ileriYonluHesaplama(int sinifIndex,int ornekIndex);
    void ogrenmeBaslat();
    void setBeklenenHataOrani(double x);
    double getBeklenenHataMiktari();
    double mutlakDegerAl(double x);
    double getHataMiktari();
    void setHata(double hataMiktari);
    double hataliysamDuzelt();
    void veriSetiniNormalizeEt();
    void standartSapmaHesabi();
    void ortalamaHesabi();
    void printStandartSapma(int index);
};

#endif // SINIRAGI_H
