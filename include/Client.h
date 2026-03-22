#pragma once
#include <iostream>
#include <cstring>
#include "Adresa.h" // o sa folosim clasa adresa pentru comanda
#include "Pizza.h" // o sa folosim clasa pizza pentru a cacula pretul total

class Client {
private:
    char* nume;
    char* telefon;
    Adresa adresaLivrare; // aici avem adresa de livrare, am folosit clasa Adresa

public:
    // constructori
    Client();
    Client(const char* nume, const char* telefon, const Adresa& adresaLivrare);

    Client(const Client& altu); // constructor de copiere
    Client& operator=(const Client& altu); // operator= de copiere
    ~Client(); // destructor
    
    //vom avea o functie care sa ne calculeze pretul, dar si sa ne genereze o chitanta
    void printeazaChitanta(int nrPizza, const Pizza* pizze) const; 

    // getteri
    const char* getNume() const;
    const Adresa& getAdresa() const;

    // setter 
    void setTelefon(const char* telefonNou);
    void setAdresa(const Adresa& adresaNoua);

    // supraincarcarea operatorului "<<"
    friend std::ostream& operator<<(std::ostream& out, const Client& c);
    
};