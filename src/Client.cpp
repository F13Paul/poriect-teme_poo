#include "../include/Client.h" // path catre headerul clasei

//constructor fara parametri, cu valori implicite
Client::Client() : adresaLivrare() {
    this->nume = new char[strlen("Necunoscut") + 1];
    strcpy(this->nume, "Necunoscut");

    this->telefon = new char[strlen("-") + 1];
    strcpy(this->telefon, "-");
}

// constructor cu parametri
Client::Client(const char* nume, const char* telefon, const Adresa& adresaLivrare) {
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);

    this->telefon = new char[strlen(telefon) + 1];
    strcpy(this->telefon, telefon);

    this->adresaLivrare = adresaLivrare; 
}

Client::Client(const Client& altu){
    this->nume = new char[strlen(altu.nume) + 1];
    strcpy(this->nume, altu.nume);

    this->telefon = new char[strlen(altu.telefon) + 1];
    strcpy(this->telefon, altu.telefon);

    this->adresaLivrare = altu.adresaLivrare; // folosim operatorul= de copiere al clasei Adresa
}

Client& Client::operator=(const Client& altu) {
    if (this != &altu) { // verificam autoasignarea
        delete[] this->nume; // eliberam memoria alocata pentru nume
        delete[] this->telefon; // eliberam memoria alocata pentru telefon

        this->nume = new char[strlen(altu.nume) + 1];
        strcpy(this->nume, altu.nume);

        this->telefon = new char[strlen(altu.telefon) + 1];
        strcpy(this->telefon, altu.telefon);

        this->adresaLivrare = altu.adresaLivrare; // folosim operatorul= de copiere al clasei Adresa
    }
    return *this; // returnam obiectul curent pentru a permite asignari in lant (c1 = c2 = c3)
}

//destructor
Client::~Client() {
    std::cout << "Destructor Client: " << this->nume << " a fost distrus.\n"; // mesaj pentru a vedea cand se apeleaza destructorul
    delete[] this->nume;
    delete[] this->telefon;

}

//setter
void Client::setTelefon(const char* telefonNou) {
    delete[] this->telefon; // eliberam memoria veche
    this->telefon = new char[strlen(telefonNou) + 1];
    strcpy(this->telefon, telefonNou);
}

void Client::setAdresa(const Adresa& adresaNoua){
    this->adresaLivrare =  adresaNoua; 
}

void Client::printeazaChitanta(int nrPizza, const Pizza* pizze) const {
    std::cout << "\n========================================\n";
    std::cout << "          CHITANTA COMANDA              ";
    std::cout << "\n========================================\n";
    std::cout << "Client: " << this->nume << "\nTelefon: " << this->telefon << "\n\nAdresa de livrare:\n";
    this->adresaLivrare.afiseazaEtichetaLivrare();
    std::cout << "----------------------------------------\n";

    double total = 0.0;
    for (int i = 0; i < nrPizza; ++i) {
        std::cout << "Pizza " << (i + 1) << ": " << pizze[i].getNume() << " - " << pizze[i].getPret() << " lei\n";
        total += pizze[i].getPret();
    }

    std::cout << "----------------------------------------\n";
    std::cout << "       TOTAL DE PLATA : " << total << " LEI\n";
    std::cout << "=========================================\n\n";
}

// getteri
const char* Client::getNume() const {
    return this->nume;
}
const Adresa& Client::getAdresa() const {
    return this->adresaLivrare;
}

//supraincarcarea operatorului "<<"
std::ostream& operator<<(std::ostream& out, const Client& c) {
    out << "Client: " << c.nume << ", Telefon: " << c.telefon << "\nAdresa de livrare:\n" << c.adresaLivrare;
    return out;
}