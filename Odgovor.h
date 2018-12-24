#pragma  once
#include <string>
#include <iostream>

class Odgovor
{
    std::string tekstOdgovora;
    bool tacnost;
    double procentualniUdio;
public:
    Odgovor(const std::string &noviTekst=""):tekstOdgovora(noviTekst){};
    inline std::string  getTekstOdgovora(void)const{ return  tekstOdgovora;}
    constexpr  double getProcentualniUdio(void){return procentualniUdio;}
    constexpr  bool getTacnost(void){return tacnost;}
    void setTekstOdgovora(const std::string &tekst){tekstOdgovora = tekst;}
    void setTacnost(const bool &tacnost){this->tacnost = tacnost;}
    void setProcentualni(const double &);
    friend std::ostream &operator<<(std::ostream &, const Odgovor&);
};

