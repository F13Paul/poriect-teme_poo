#pragma once // optional, pentru a preveni erori de includere multipla
#include <iostream> // biblioteca pentru input/output
#include <cstring> // biblioteca pentru stringuri

class Pizza { // facem o clasa "Pizza"
private:  // tot ce in private nu poate fi accesat direct din exteriorul clasei
    char* nume;
    int nrIngrediente;
    char** ingrediente; // un vector in care fiecare element este un cuvant (char*)
    double pret;

public: // aici avem fuctiile pe care le putem apela din main

    Pizza(); // constructor fara parametri
    Pizza(const char* nume, int nrIngrediente, const char* ingrediente[], double pret); // constructor cu parametri -> nume, numar ingrediente, ...
    
    Pizza(const Pizza& alta); // constructor de copiere
    Pizza& operator=(const Pizza& alta); // operator= de copiere, pentru a putea face p1 = p2, p3 = p1, etc. (copierea unui obiect in altul)
    ~Pizza(); // destructor

    const char* getNume() const; //getter pentru nume
    double getPret() const; // getter pentru pret, ca sa putem afisa numele/pretul din main, fiind privat

    //setter
    void setPret(double pretNou);

    friend std::ostream& operator<<(std::ostream& out, const Pizza& p);
    // functie printen pentru a afisa pizza
    // supraincarcarea operatorului << pentru a putea face "cout<<....(pizza)"
};