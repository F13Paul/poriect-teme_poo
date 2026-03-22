#pragma once
#include <iostream>
#include <cstring>

class Adresa {
private:
    char* oras;
    char* strada;
    int numar;
    char* detalii; // daca sta la bloc, etajul, nr de apartamnet, cum sa sune, etc..
    static bool valideazaNumar(int nr);

public:
    // constructori
    Adresa();
    Adresa(const char* oras, const char* strada, int numar, const char* detalii = "-");

    //destructor 
    ~Adresa();
    
    //constructor de copiere
    Adresa(const Adresa& alta);
    Adresa& operator=(const Adresa& alta);

    // o functie pentru a genera o eticheta de livrare
    void afiseazaEtichetaLivrare() const;

    // getter
    const char* getOras() const;
    // setter
    void setDetalii(const char* detaliiNoi);

    //supraincarcarea operatorului "<<"
    friend std::ostream& operator<<(std::ostream& out, const Adresa& a);
    
};