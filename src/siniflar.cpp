#include "headers/siniflar.h"

Siniflar::Siniflar()
{

}

void Siniflar::noktaEkle(Noktalar nokta){
    this->sinifaAitNoktalar.push_back(nokta);
    this->ornekSayisi++;
}


void Siniflar::sinifAitNoktalariGoster(){
    for(unsigned int i=0; i<this->sinifaAitNoktalar.size(); ++i)
         cout << this->sinifaAitNoktalar[i].getDegerler(0) << ' ' << this->sinifaAitNoktalar[i].getDegerler(1) << ' ' << this->sinifaAitNoktalar[i].getDegerler(2)<< endl ;
}

void Siniflar::beklenenDegerSet(int sinifSayisi,int sinifIndex){
    beklenenDeger = new double[sinifSayisi];
    for(int i = 0; i < sinifSayisi;i++){
        if(i == sinifIndex) beklenenDeger[i] = 1;
        else beklenenDeger[i] = -1;

    }



}

void Siniflar::beklenenDegerleriEkranaBas(int sinifSayisi){
    for(int i = 0 ; i < sinifSayisi; i++){
        cout<<this->beklenenDeger[i]<<" ";
    }
    cout<<endl;
}

// burda ki index o seçilen indexe ait nokta
Noktalar Siniflar::sinifaAitNoktaGet(int index){
    Noktalar noktam = sinifaAitNoktalar[index];
    return noktam;
}

double Siniflar::beklenenDegerGet(int x){
    return this->beklenenDeger[x];
}

int Siniflar::getOrnekSayisi(){
    return this->ornekSayisi;
}
void Siniflar::sinifaAitNoktaSet(int index, Noktalar nokta){
     this->sinifaAitNoktalar[index] = nokta;
}
