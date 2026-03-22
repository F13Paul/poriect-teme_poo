#include "../include/Adresa.h" // path catre headerul clasei

// sa zicem ca trebuie sa validam numarul strazii, sa nu fie negativ sau zero
bool Adresa::valideazaNumar(int nr) const {
    return nr > 0;
}

// constructor fara parametri, cu valori implicite
Adresa::Adresa() {
    this->oras = new char[strlen("Necunoscut") + 1];
    strcpy(this->oras, "Necunoscut");

    this->strada = new char[strlen("Necunoscuta") + 1];
    strcpy(this->strada, "Necunoscuta");

    this->numar = 0;

    this->detalii = new char[strlen("-") + 1];
    strcpy(this->detalii, "-");
}

// constructor cu parametri, cu validare pentru numar
Adresa::Adresa(const char* oras, const char* strada, int numar, const char* detalii){
    this->oras = new char[strlen(oras) + 1];
    strcpy(this->oras, oras);
    
    this->strada = new char[strlen(strada) + 1];
    strcpy(this->strada, strada);

    if (valideazaNumar(numar)) {
        this->numar = numar;
    } else {
        std::cerr << "!!! Numarul strazii nu poate fi mai mic decat 1 !!!\n";
        this->numar = 0;
    }

    this->detalii = new char[strlen(detalii) + 1];
    strcpy(this->detalii, detalii);
}
// constructor de copiere
Adresa::Adresa(const Adresa& alta) {
    this->oras = new char[strlen(alta.oras) + 1];
    strcpy(this->oras, alta.oras);

    this->strada = new char[strlen(alta.strada) + 1];
    strcpy(this->strada, alta.strada);

    this->numar = alta.numar;

    this->detalii = new char[strlen(alta.detalii) + 1];
    strcpy(this->detalii, alta.detalii);
}

// operator=
Adresa& Adresa::operator=(const Adresa& alta) {
    if (this != &alta) { // verificam autoasignarea
        // eliberam memoria existenta
        delete[] this->oras;
        delete[] this->strada;
        delete[] this->detalii;

        // alocam si copiem noile valori
        this->oras = new char[strlen(alta.oras) + 1];
        strcpy(this->oras, alta.oras);

        this->strada = new char[strlen(alta.strada) + 1];
        strcpy(this->strada, alta.strada);

        this->numar = alta.numar;

        this->detalii = new char[strlen(alta.detalii) + 1];
        strcpy(this->detalii, alta.detalii);
    }
    return *this; // returnam obiectul curent 
}

// destructor 
Adresa::~Adresa() {
    std::cout << "Destructor Adresa: " << this->oras << ", str. " << this->strada << " a fost distrusa.\n"; // mesaj pentru a vedea cand se apeleaza destructorul
    delete[] this->oras;
    delete[] this->strada;
    delete[] this->detalii;
}

// avem o functie pentru generarea de eticheta
void Adresa::afiseazaEtichetaLivrare() const {
    std::cout << "Oras: " << this->oras << "\nStrada: " << this->strada
              << ", nr. " << this->numar << "\nDetalii: " << this->detalii << "\n";
}

// getter pentru oras
const char* Adresa::getOras() const {
    return this->oras;
}

//setter
void Adresa::setDetalii(const char* detaliiNoi) {
    delete[] this->detalii; // eliberam memoria veche
    this->detalii = new char[strlen(detaliiNoi) + 1]; // alocam pentru noile detalii
    strcpy(this->detalii, detaliiNoi); // copiem noile detalii
}
// supraincarcarea operatorului "<<"
std::ostream& operator<<(std::ostream& out, const Adresa& a) {
    out << "Adresa-> oras: " << a.oras << ", str. " << a.strada << ", nr. " << a.numar;
    if (strcmp(a.detalii, "-") != 0) { // daca detaliile nu sunt cele implicite, le afisam
        out << " (" << a.detalii << ")";
    }
    return out;

}

