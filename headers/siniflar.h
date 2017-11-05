#ifndef SINIFLAR_H
#define SINIFLAR_H
#include <iostream>
#include "noktalar.h"
#include <vector>
using namespace std;

class Siniflar
{
    vector <Noktalar> sinifaAitNoktalar;
    int kacinciSinif;
    int ornekSayisi = 0;
    double * beklenenDeger;
public:
    Siniflar();
    void noktaEkle(double x, double y, double z);
    void sinifAitNoktalariGoster();
    void beklenenDegerSet(int sinifSayisi,int sinifIndex);
    double beklenenDegerGet(int x);
    Noktalar sinifaAitNoktaGet(int index);
    int getOrnekSayisi();
    void beklenenDegerleriEkranaBas(int sinifSayisi);



};

#endif // SINIFLAR_H
