#include "headers/noktalar.h"

Noktalar::Noktalar()
{

}


void Noktalar::noktalarEkranaBas() {
    for(int i = 0 ; i < GIRISSAYISI;i++){
        cout<< this->getDegerler(i)<<"  ";
    }
    cout<<endl;
}

double Noktalar::getDegerler(int index){
    return this->degerler[index];
}
void Noktalar::setDegerler(int index,double x){
    this->degerler[index] = x;
}
