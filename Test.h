//
// Created by zelimirmaletic on 12/23/18.
//
#pragma  once

#include "Pitanje.h"
#include <functional>


class Test
{
    struct NODE
    {
        Pitanje info;
        NODE *next;
        NODE(const Pitanje &pitanje,NODE *next = nullptr):info(pitanje),next(next){}
    };
    NODE *pHead,*pTail;
    int brojPitanja;
    double poeni = 0;
public:
    inline Test(){pHead=pTail=nullptr;}
    ~Test();
    Test(const Test &) = delete;
    Test &operator=(const Test &)=delete;
    Test &operator+=(const Pitanje &);
    Pitanje &operator[](const int);
    const Pitanje &operator[](const int) const;
    friend std::ostream &operator<<(std::ostream &, const Test &);
    Test &operator()(int , int *, int );
    void ispisiPitanja(const std::function<bool(const int)> &);
    void ispisiOdgovore(const std::function<bool(Odgovor)> &);
};




