#include <iostream>
//#include <string>
#include "include/Pizza.h"
#include "include/Adresa.h"
#include "include/Client.h"

int main() {
   
    std::cout << "=== PizzaDelivery ===\n\n";

    // setam noi niste pizze, cu ingrediente si preturi
    const char* ingr1[] = {"Sos de rosii", "Mozzarella", "Busuioc"};
    Pizza p1("Margherita", 3, ingr1, 35.0);
    
    const char* ingr2[] = {"Sos de rosii", "Mozzarella", "Salam picant", "Ardei"};
    Pizza p2("Diavola", 4, ingr2, 42.5);
    
    const char* ingr3[] = {"Smantana", "Mozzarella", "Bacon", "Parmezan"};
    Pizza p3("Carbonara", 4, ingr3, 45.0);

    // sa zicem ca eu, Paul, comand 2 pizze, Margherita si Carbonara
    Pizza comandaLuiPaul[] = {p1, p3}; 
    int nrPizzeComandate = 2;

    // setam si o adresa pentru livrare
    Adresa adresaPaul("Bucuresti", "Primaverii", 15, "Ap. 12, Interfon 12");

    // aici ne folosim de clasa client pentru a ne inregistra si a da comanda
    Client clientPaul("Paul Frincu", "0712345678", adresaPaul);

    // primi si un feedback sa vedem daca ne am inregistrat corect
    std::cout << "Am inregistrat in sistem urmatorul client:\n";
    std::cout << clientPaul << "\n";

    //folosire getteri si setteri
    std::cout << "Orasul initial al livarii: " << adresaPaul.getOras()<<"\n";
    clientPaul.setTelefon("07987654321");
    comandaLuiPaul[0].setPret(38.5);

    // testam si setterul pt adresa( sa zicem ca am uitat sa trec etajul)
    std::cout << "---Actualizare date client---\n";
    Adresa adresaNoua = clientPaul.getAdresa(); // luam adresa veche
    adresaNoua.setDetalii("Ap. 12, Etaj 5, Interfon 12"); // o modificam, sa zicem ca am uitat sa pun etajul

    std::cout << "Adresa actualizata:\n" << adresaNoua << "\n";
    clientPaul.setAdresa(adresaNoua);

    // printam chitanta
    clientPaul.printeazaChitanta(nrPizzeComandate, comandaLuiPaul);

    std::cout << "\n=== Sfarsitul programului (Curatenie Memorie) ===\n";
    return 0; 
}