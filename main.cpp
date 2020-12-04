#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <windows.h>
#include "funkce.h"

using namespace std;

string Hjmeno;
string jmeno1;
string jmeno2;
string NacJmeno;
string otazka;

int  zivot1 = 5;
int zivot2 = 5;
int zivot3 = 5;
int rana = 1;
int kdoH = 1;
int utokna;
int kontrola;

bool Konecek;
bool potvrd;

void vygenerujJmeno(){
    srand(time(NULL));
    int cislo;
    int cislo2;

    cislo = rand() % 10;
    cislo2 = rand() % 10;
    if(cislo == cislo2){
        cislo2 = rand() % 10;
    }else{
        if(cislo == 1){
            jmeno1 = "Pepa - pocitac";
        }else if(cislo == 2){
            jmeno1 = "Nela - pocitac";
        }else if(cislo == 3){
            jmeno1 = "Marek - pocitac";
        }else if(cislo == 4){
            jmeno1 = "Jakub - pocitac";
        }else if(cislo == 5){
            jmeno1 = "Ema - pocitac";
        }else if(cislo == 6){
            jmeno1 = "Marie - pocitac";
        }else if(cislo == 7){
            jmeno1 = "Lukas - pocitac";
        }else if(cislo == 8){
            jmeno1 = "Jan - pocitac";
        }else if(cislo == 9){
            jmeno1 = "Adam - pocitac";
        }else if(cislo == 10){
            jmeno1 = "Helena - pocitac";
        }else{
            const char *cesta="C:/Poraz_ostatni_hra/Logs/erorr.txt";
            ofstream soubor2(cesta);
            soubor2 << "[ERORR: " << "spatne vygenerovane cislo-E.01-cas: " << CurrentDateTime("now") << " ]"<< endl;
            soubor2.close();
        }
        if(cislo2 == 1){
            jmeno2 = "Johana - pocitac";
        }else if(cislo2 == 2){
            jmeno2 = "Kristyna - pocitac";
        }else if(cislo2 == 3){
            jmeno2 = "Katerina - pocitac";
        }else if(cislo2 == 4){
            jmeno2 = "Matej - pocitac";
        }else if(cislo2 == 5){
            jmeno2 = "Premysl - pocitac";
        }else if(cislo2 == 6){
            jmeno2 = "Vit - pocitac";
        }else if(cislo2 == 7){
            jmeno2 = "Pavel - pocitac";
        }else if(cislo2 == 8){
            jmeno2 = "Karel - pocitac";
        }else if(cislo2 == 9){
            jmeno2 = "Jana - pocitac";
        }else if(cislo2 == 10){
            jmeno2 = "Hana - pocitac";
        }else{
            const char *cesta="C:/Poraz_ostatni_hra/Logs/erorr2.txt";
            ofstream soubor3(cesta);
            soubor3 << "[ERORR: " << "spatne vygenerovane cislo2-E.02-cas: " << CurrentDateTime("now") << " ]"<< endl;
            soubor3.close();
        }
    }
}


void ulozJmeno(){
    const char *cesta="C:/Poraz_ostatni_hra/cache/file.txt";
    ofstream soubor1(cesta);
    soubor1 << Hjmeno << endl;
    soubor1.close();
}


void uvod(){
    vypisLogo();
    ifstream kontrola("C:/Poraz_ostatni_hra/cache/file.txt");
    if(kontrola != NULL){
        getline(kontrola, NacJmeno);
        cout << "Chcete nacist data pro jmeno \"" << NacJmeno << "\"\n";
        cout << "ano nebo ne(zadejte malymi pismeny)? ";
        cin >> otazka;
        if(otazka == "ano"){
            cout << "\n\nNacitam data...";
            casovac(1);
            Hjmeno = NacJmeno;
            vygenerujJmeno();
        }else{
            cout << "       Zadej svoje jmeno:  " ;
            cin >> Hjmeno;
            ulozJmeno();
        }
    }else{
        cout << "       Zadej svoje jmeno:  " ;
        cin >> Hjmeno;
        ulozJmeno();
    }
    cout << "\n";
    cout << "Zmacknete jakekoliv tlacitko pro pokracovani\n";
    prejdi();
}

void menu(){
    cout << "\t1. hrac:  " << Hjmeno << "        \n\tPocet zivotu:  "<< zivot1 << "\n\n";
    cout << "\t2. hrac:  " << jmeno1 <<"         \n\tPocet zivotu:  "<< zivot2 << "\n\n";
    cout << "\t3. hrac:  " << jmeno2 <<"         \n\tPocet zivotu:  "<< zivot3 << "\n\n";
    cout << "Zmacknete jakekoliv tlacitko pro pokracovani\n";
    prejdi();
}

void utok(){
    if(kdoH == 1){
        cout << "Hrajes ty, na koho chces zautocit?\n";
        cout << "\t1. zautoc na:  " << jmeno1 <<" \n\tPocet zivotu:  "<< zivot2 << "\n\n";
        cout << "\t2. zautoc na:  " << jmeno2 <<" \n\tPocet zivotu:  "<< zivot3 << "\n\n";
        cout << "Zadej na koho chces zautocit 1, 2\n";
        cin >> utokna;
        if(utokna == 1){
            zivot2 -= rana;
            cout << "Probehl utok na: " << jmeno1 << "\n";
            cout << "Ted uz ma jen " << zivot2 << " zivotu\n";
            cout << "Zmacknete jakekoliv tlacitko pro pokracovani\n";
            kdoH++;
            prejdi();
            menu();
        }else if(utokna == 2){
            zivot3 -= rana;
            cout << "Probehl utok na: " << jmeno2 << "\n";
            cout << "Ted uz ma jen " << zivot3 << " zivotu\n";
            cout << "Zmacknete jakekoliv tlacitko pro pokracovani\n";
            kdoH++;
            prejdi();
            menu();
        }else if(utokna >= 3){
            cout << "Neplatny utok, utocis znovu\n";
            cout << "Zmacknete jakekoliv tlacitko pro pokracovani\n";
            prejdi();
            utok();
        }
    }else if(kdoH == 2){
        cout << "Hraje " << jmeno1 << " na koho zautoci?\n";
        casovac(1);
        cout << "Utocim na tebe  \n";
        zivot1 -= rana;
        cout << "Mas uz jen:  "<< zivot1 << " zivotu\n";
        kdoH++;
        cout << "Zmacknete jakekoliv tlacitko pro pokracovani\n";
        prejdi();
        menu();
    }else if(kdoH == 3){
        cout << "Hraje " << jmeno2 << " na koho zautoci?\n";
        casovac(1);
        cout << "Utocim na " << jmeno1 << " \n";
        zivot2 -= rana;
        cout << "Ma uz jen:  "<< zivot2 << " zivotu\n";
        kdoH++;
        cout << "Zmacknete jakekoliv tlacitko pro pokracovani\n";
        prejdi();
        kdoH = 1;
        menu();
        }
    }

void konec(){
    cout << "Zazvonil zvonec a hry je konec :)\n";
    if(zivot1 > zivot2 && zivot2 < zivot3 && zivot1 > zivot3){
        MessageBox(NULL, "Vyhrál jsi.Gratuluju!!", "Info", MB_OK);
        cout << "Zadejte  end pro ukonceni\n" << endl;
        string prikaz;
        cin >> prikaz;
        if(prikaz == "end"){
            Konecek =true;
        }
    }else if(zivot2 > zivot1 && zivot1 < zivot3 && zivot2 > zivot3){
        MessageBox(NULL, "Vyhrál poèítaè, nevadí", "Info", MB_OK);
        cout << "info - vyhral: "<< jmeno1 << endl;
        cout << "Nevadi mel jsi  " << zivot1 << "  zivotu\n";
        cout << "Zadejte  end pro ukonceni\n " << endl;
        string prikaz;
        cin >> prikaz;
        if(prikaz == "end"){
            Konecek =true;
        }
    }else{
        MessageBox(NULL, "Vyhrál poèítaè, nevadí", "Info", MB_OK);
        cout << "info - vyhral: " << jmeno2 << endl;
        cout << "Nevadi mel jsi  " << zivot1 << "  zivotu\n";
        cout << "Zadejte  end pro ukonceni\n" << endl;
        string prikaz;
        cin >> prikaz;
        if(prikaz == "end"){
            Konecek =true;
        }
    }}


int main(){
    vygenerujJmeno();
    slozkaNaUkladani();
    uvod();
    while(Konecek == false){
        if(zivot1 > 0 && zivot2 > 0 && zivot3 > 0){
            menu();
            utok();
        }else if(zivot1 == 0 || zivot2 == 0 || zivot3 == 0){
            konec();
        }else{
            const char *cesta="C:/Poraz_ostatni_hra/Logs/erorr2.txt";
            ofstream soubor4(cesta);
            soubor4 << "[ERORR: " << "chyba v nastavovani zivotu-E.03-cas: " << CurrentDateTime("now") << " ]"<< endl;
            soubor4.close();
        }
        }
    return 0;
}
