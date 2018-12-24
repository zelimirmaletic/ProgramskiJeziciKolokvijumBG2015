//
// Created by zelimirmaletic on 12/23/18.
//
#pragma  once
#include <iostream>
#include <string>
#include "Odgovor.h"

class Pitanje
{
    std::string tekstPitanja;
    int brojPoena;
    int brojPonudjenihOdgovora;
    Odgovor *ponudjeniOdgovori;
    void copy(const Pitanje &);
    void move(Pitanje &&);
    void empty(void);
    void realloc(void);
public:
    Pitanje(const std::string &,const int &, const int &);
    inline Pitanje():Pitanje("",0,0){}
    ~Pitanje(){empty();}
    inline Pitanje(const Pitanje &other){copy(other);}
    inline Pitanje(Pitanje &&other){move(std::move(other));
    Pitanje &operator+=(const Odgovor &);
    Pitanje &operator=(const Pitanje &);
    Pitanje &operator=(Pitanje &&);
    double odgovori(int *, int);
    friend std::ostream &operator<<(std::ostream &, const Pitanje &);
};

