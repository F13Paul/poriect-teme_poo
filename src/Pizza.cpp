#include "../include/Pizza.h" // path-ul relativ catre header

// constructor fara parametri
Pizza::Pizza() { // '::' specifica ca Pizza apartine clasei Pizza
    this->nume = new char[strlen("Necunoscuta") + 1]; // alocam memorie pentru nume
    strcpy(this->nume, "Necunoscuta");
    this->nrIngrediente = 0; // folosim 'this->' pentru ca ne referim la variabilele obiectul curent
    this->ingrediente = nullptr;
    this->pret = 0.0;
} 

// constructor cu parametri
Pizza::Pizza(const char* nume, int nrIngrediente, const char* ingrediente[], double pret) {
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
    
    this->nrIngrediente = nrIngrediente;
    this->pret = pret;
    
    this->ingrediente = new char*[nrIngrediente]; //alocam dinamic un vector pentru ingrediente
    for (int i = 0; i < nrIngrediente; ++i) {
        this->ingrediente[i] = new char[strlen(ingrediente[i]) + 1];
        strcpy(this->ingrediente[i], ingrediente[i]); // copiem fiecare ingredient in vectorul nostru
    }
}

// constructor de copiere
Pizza::Pizza(const Pizza& alta) {
    this->nume = new char[strlen(alta.nume) + 1];
    strcpy(this->nume, alta.nume);
    
    this->nrIngrediente = alta.nrIngrediente;
    this->pret = alta.pret;
    
    this->ingrediente = new char*[alta.nrIngrediente];
    for (int i = 0; i < alta.nrIngrediente; ++i) {
        this->ingrediente[i] = new char[strlen(alta.ingrediente[i]) + 1];
        strcpy(this->ingrediente[i], alta.ingrediente[i]);
    }
}

// operator= de copiere
Pizza& Pizza::operator=(const Pizza& alta) {
      if (this != &alta) { // verificam sa nu fie acelasi obiect
        delete[] this->nume; // eliberam memoria alocata pentru nume
        if (this->ingrediente != nullptr) {
            for (int i = 0; i < this->nrIngrediente; ++i) {
                delete[] this->ingrediente[i]; // stergem fiecare ingredient in parte
            }
            delete[] this->ingrediente; // stergem vectorul de ingrediente
        }
        this->nume = new char[strlen(alta.nume) + 1];
        strcpy(this->nume, alta.nume);
        
        this->nrIngrediente = alta.nrIngrediente;
        this->pret = alta.pret;
        
        this->ingrediente = new char*[alta.nrIngrediente];
        for (int i = 0; i < alta.nrIngrediente; ++i) {
            this->ingrediente[i] = new char[strlen(alta.ingrediente[i]) + 1];
            strcpy(this->ingrediente[i], alta.ingrediente[i]);
        }
    }
    return *this;
}

// destructor
Pizza::~Pizza() {
    //daca verau sa afisez numele, o faca inainte de eliberarea memoriei
    std::cout << "Destructor Pizza: " << this->nume << " a fost distrusa.\n"; // mesaj pentru a vedea cand se apeleaza destructorul
    delete[] this->nume; // eliberam memoria alocata pentru nume
    if (this->ingrediente != nullptr) {
        for (int i = 0; i < this->nrIngrediente; ++i) {
            delete[] this->ingrediente[i]; // stergem fiecare ingredient in parte
        }
        delete[] this->ingrediente; // stergem vectorul de ingrediente
    }
}

// getter pentru nume
const char* Pizza::getNume() const {
    return this->nume;
}

// getter pentru pret
double Pizza::getPret() const {
    return this->pret;
}

// setter
void Pizza::setPret(double pretNou) {
    this->pret = pretNou;
}

// supraincarcare operatorului "<<" pentru a afisa pizza
std::ostream& operator<<(std::ostream& out, const Pizza& p) {
    out << "Pizza: " << p.nume << " | Pret: " << p.pret << " lei | Ingrediente: ";
    for (int i = 0; i < p.nrIngrediente; ++i) {
        out << p.ingrediente[i];
        if (i < p.nrIngrediente - 1) {
            out << ", ";
        }
    }
    return out;
}