#ifndef NOKTALAR_H
#define NOKTALAR_H
#define GIRISSAYISI 3
#include <iostream>
using namespace std;
class Noktalar
{
   double degerler[GIRISSAYISI];
public:
    Noktalar();
    void noktalarEkranaBas();
    double getDegerler(int index);
    void setDegerler(int index,double x);

};

#endif // NOKTALAR_H
