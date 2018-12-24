//
// Created by zelimirmaletic on 12/23/18.
//

#include "Odgovor.h"

void Odgovor::setProcentualni(const double &udio)
{
    if(udio<-100 || udio>100)
        exit(1);
    procentualniUdio=udio;
}

std::ostream &Odgovor::operator<<(std::ostream &output, const Odgovor &odg)
{
    output<<tekstOdgovora<<tekstOdgovora<<":"<<" "<<procentualniUdio<<"%";
    return output;
}

