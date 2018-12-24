//
// Created by zelimirmaletic on 12/23/18.
//

#include "Pitanje.h"
#include <utility>

Pitanje::Pitanje(const std::string &tekst, const int &brojPoena, const int &brojOdgovora)
{
    tekstPitanja=tekst;
    this->brojPoena=brojPoena;
    brojPonudjenihOdgovora=brojOdgovora;
    if(brojOdgovora==0)
        ponudjeniOdgovori= nullptr;
    else
        ponudjeniOdgovori = new Odgovor[brojOdgovora];
}

Pitanje &Pitanje::operator+=(const Odgovor odg)
{
    realloc();

    double noviProcent;
    if(!odg.getTacnost())
        odg.setProcentualni(-100);
    else {
        int counter = 0;
        for (int i = 0; i < brojPonudjenihOdgovora; ++i)
            if (ponudjeniOdgovori[i].getTacnost())
                counter++;
        noviProcent = 100 / counter;
        for (int i = 0; i < brojPonudjenihOdgovora; ++i)
            if (ponudjeniOdgovori[i].getTacnost())
                ponudjeniOdgovori[i].setProcentualni(noviProcent);
        odg.setProcentualni(noviProcent);
    }
    ponudjeniOdgovori[brojPonudjenihOdgovora-1]= odg;
    return *this;
}

void Pitanje::realloc(void)
{
    Odgovor noviNiz = new Odgovor[brojPonudjenihOdgovora+1];
    for (int i = 0; i < brojPonudjenihOdgovora; ++i)
        noviNiz[i]=ponudjeniOdgovori[i];
    delete[] this->ponudjeniOdgovori;
    ponudjeniOdgovori=noviNiz;
    brojPonudjenihOdgovora++;
}

void Pitanje::copy(const Pitanje &other)
{
    tekstPitanja = other.tekstPitanja;
    brojPoena = other.brojPoena;
    brojPonudjenihOdgovora= other.brojPonudjenihOdgovora;
    Odgovor *noviNiz =  new Pitanje[brojPonudjenihOdgovora];

    for (int i = 0; i <brojPonudjenihOdgovora ; ++i)
        noviNiz[i] = other.ponudjeniOdgovori[i];
    ponudjeniOdgovori = noviNiz;
    //std::copy(other.ponudjeniOdgovori, other.ponudjeniOdgovori+broj, noviNiz);
}

void Pitanje::move(Pitanje &&other)
{
    tekstPitanja = std::move(other.tekstPitanja);
    brojPoena= std::move(other.brojPoena);
    brojPonudjenihOdgovora = std::move(other.brojPonudjenihOdgovora);
    ponudjeniOdgovori = std::move(other.ponudjeniOdgovori);
}

void Pitanje::empty(void)
{
    delete[] ponudjeniOdgovori;
    ponudjeniOdgovori = nullptr;
}

Pitanje &Pitanje::operator=(const Pitanje &other) {
    if(this != &other)
    {
        this->~Pitanje();
        copy(other);
    }
    return *this;
}

Pitanje &Pitanje::operator=(const Pitanje &&other)
{
    if(this != &other)
    {
        this->~Pitanje();
        move(std::move(other));
    }
    return *this;
}

double Pitanje::odgovori(int *niz, int broj)
{
    double poeni = 0;
    if(broj>brojPonudjenihOdgovora)
        exit(2);
    else
    {
        for (int i = 0; i < broj; ++i)
            if(ponudjeniOdgovori[niz[i]].getTacnost())
                poeni+= brojPoena*ponudjeniOdgovori[niz[i]].getProcentualniUdio();
    }
    if(poeni<0)
        return 0;
    return poeni;
}

std::ostream &operator<<(std::ostream &output, const Pitanje &other)
{
    output<<other.tekstPitanja<<": poeni: ("<<other.brojPoena<<") "<<std::endl;
    for (int i = 0; i < other.brojPonudjenihOdgovora; ++i)
        output<<"\t"<<other.ponudjeniOdgovori[i];
    return output;
}
