#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <windows.h>

using namespace std;
string Hjmeno;
int  zivot1 = 3;
int zivot2 = 3;
int zivot3 = 3;
int rana = 1;
int kdoH = 1;
int utokna;
bool Konecek;

void casovac(int sekundy)
{
    clock_t start = clock();
    clock_t perioda = sekundy * CLOCKS_PER_SEC;
    clock_t uplynulo;

    do {
        uplynulo = clock() - start;
    } while(uplynulo < perioda);
}
void slozkaNaUkladani(){
    CreateDirectoryA("C:\\Poraz_ostatni_hra", NULL);
    CreateDirectoryA("C:\\Poraz_ostatni_hra\\Logs", NULL);
    CreateDirectoryA("C:\\Poraz_ostatni_hra\\cache", NULL);
    CreateDirectoryA("Poraz_ostatni_hra\\others", NULL);
}
void start(){
    system("CLS");
    cout << "_________________________________________\n";
    cout << "            Vitova Super hra: \n";
    cout << "                Beat they\n";
    cout << "__________________________________________\n";
    cout << "Bylo vytvoreno  " << __DATE__<< " v " << __TIME__ << ".\n\n\n";//èas hodiny minuty sekundy
    cout << "       Zadej svoje jmeno:  " ;
    cin >> Hjmeno;
    cout << "\n";
    cout << "Zmacknete jakekoliv tlacitko pro pokracovani\n";
    getch();
    system("CLS");

    }
    void menu(){
    cout << "\t1. hrac:  " << Hjmeno << "        \n\tPocet zivotu:  "<< zivot1 << "\n\n";
    cout << "\t2. hrac:  Johan(pocitac)"<< "     \n\tPocet zivotu:  "<< zivot2 << "\n\n";
    cout << "\t3. hrac:  Liboslav(pocitac)"<< "  \n\tPocet zivotu:  "<< zivot3 << "\n\n";
    cout << "Zmacknete jakekoliv tlacitko pro pokracovani\n";
    getch();
    system("CLS");
    }
void utok(){
    if(kdoH == 1){
        cout << "Hrajes ty, na koho chces zautocit?";
        cout << "Zautoc na \n" << "  1. Johan(pocitac) \n\tPocet zivotu:  "<< zivot2 << "\n\n";
        cout << "Zautoc na \n" << "  2. Liboslav(pocitac) \n\tPocet zivotu:  "<< zivot3 << "\n\n";
        cout << "Zadej na koho chces zautocit 1, 2\n";
        cin >> utokna;
        if(utokna == 1){
            zivot2 -= rana;
            cout << "Probehl utok na:  Johan(pocitac)\n";
            cout << "Ted uz ma jen " << zivot2 << "zivotu\n";
            cout << "Zmacknete jakekoliv tlacitko pro pokracovani\n";
            kdoH++;
            getch();
            system("CLS");
            return menu();
        }else if(utokna == 2){
            zivot3 -= rana;
            cout << "Probehl utok na:  Liboslav(pocitac)\n";
            cout << "Ted uz ma jen " << zivot3 << " zivotu\n";
            cout << "Zmacknete jakekoliv tlacitko pro pokracovani\n";
            kdoH++;
            getch();
            system("CLS");
            return menu();
        }else if(utokna >= 3){
        cout << "Neplatny utok, utocis znovu\n";
        cout << "Zmacknete jakekoliv tlacitko pro pokracovani\n";
        getch();
        system("CLS");
        utok();
        }
    }else if(kdoH == 2){
    cout << "Hraje Johan(pocitac) na koho zautoci?\n";
    cout << "Utocim na tebe  \n";
    zivot1 -= rana;
    cout << "Mas uz jen:  "<< zivot1 << " zivotu";
    kdoH++;
    cout << "Zmacknete jakekoliv tlacitko pro pokracovani\n";
    getch();
    system("CLS");
    return menu();
    }else if(kdoH == 3){
    cout << "Hraje Liboslav(pocitac) na koho zautoci?\n";
    cout << "Utocim na Johana(pocitac)  \n";
    zivot2 -= rana;
    cout << "Ma uz jen:  "<< zivot2 << " zivotu";
    kdoH++;
    cout << "Zmacknete jakekoliv tlacitko pro pokracovani\n";
    getch();
    system("CLS");
    kdoH = 1; /*nové*/
    return menu();
    }
    }
    void konec(){
    cout << "Zazvonil zvonec a hry je konec :)\n";
    if(zivot1 > zivot2 && zivot2 < zivot3 && zivot1 > zivot3){
        cout << "Vyhral jsi !!" << "\n Gratuluju!\n";
        cout << "Zadejte  end pro ukonceni\n" << endl;
        string prikaz;
        cin >> prikaz;
        if(prikaz == "end"){
        Konecek =true;
    }
    }else if(zivot2 > zivot1 && zivot1 < zivot3 && zivot2 > zivot3){
        cout << "Vyhral Johan(pocitac) !!" << "\n Gratuluju!\n";
        cout << "Nevadi mel jsi  " << zivot1 << "  zivotu\n";
        cout << "Zadejte  end pro ukonceni\n " << endl;
        string prikaz;
        cin >> prikaz;
        if(prikaz == "end"){
        Konecek =true;
    }
    }else{
    cout << "Vyhral Liboslav(pocitac) !!" << "\n Gratuluju!\n";
    cout << "Nevadi mel jsi  " << zivot1 << "  zivotu\n";
    cout << "Zadejte  end pro ukonceni\n" << endl;
    string prikaz;
    cin >> prikaz;
    if(prikaz == "end"){
        Konecek =true;
    }
    }}


int main(){
    start(); /*nové*/
    while(Konecek == false){
    if(zivot1 > 0 && zivot2 > 0 && zivot3 > 0){ /*nové*/
    menu();
    utok();
    }else{
    konec();
    }}
    return 0;
}
