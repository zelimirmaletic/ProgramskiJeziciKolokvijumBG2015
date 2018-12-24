//
// Created by zelimirmaletic on 12/23/18.
//

#include "Test.h"
#include <algorithm>

Test::~Test()
{
    if(pHead)
    {
        while(pHead)
        {
            NODE *tmp = pHead;
            pHead=pHead->next;
            delete tmp;
        }
        pTail= nullptr;
    }
}

Test &Test::operator+=(const Pitanje &other)
{
    NODE *tmp = pHead;
    pTail=(!pHead:?pHead:pTail->next) =new NODE(other);
    brojPitanja++;
    return *this;
}

Pitanje &Test::operator[](const int index)
{
    if(index<brojPitanja)
    {
        NODE *tmp = pHead;
        for (int i = 0; i < index; ++i)
            tmp=tmp->next;
        return tmp->info;
    }
    exit(3);
}

const Pitanje &Test::operator[](const int index) const
{
    if(index<brojPitanja)
    {
        NODE *tmp = pHead;
        for (int i = 0; i < index; ++i)
            tmp=tmp->next;
        return tmp->info;
    }
    exit(3);
}

std::ostream &operator<<(std::ostream &output, const Test &other)
{
    Test::NODE *tmp = other.pHead;
    while(tmp)
    {
        output<<tmp->info<<std::endl;
        tmp=tmp->next;
    }
    return output;
}

Test &Test::operator()(int i, int *niz, int n)
{
    poeni += (*this)[i].odgovori(niz,n);
    return *this;
}

void Test::ispisiPitanja(const std::function<bool(const int)> &compare)
{
    for (int i = 0; i < brojPitanja; ++i)
        if(compare((*this).operator[](i).brojPonudjenihOdgovora))//(*this)[i].brojPonudjenihOdgovora
            std::cout<<(*this)[i];
}

