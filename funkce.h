#include <iostream>
#include <conio.h>

using namespace std;

void vypisLogo(){
    system("CLS");
    SetConsoleOutputCP(65001);
    system("color 70");
    cout << "_______________________________________________________________________________" << endl;
    cout << "|   ___     ____            _______      _______           ____               |" << endl;
    cout << "|  |   |   |         /\\       |            |     |    |  |      \\  / \u00a9        |"<< endl;
    cout << "|  |___|   |____    /  \\      |            |     |____|  |____   \\/           |"<< endl;
    cout << "|  |    |  |       /____\\     |            |     |    |  |       |            |"<< endl;
    cout << "|  |____|  |____  /      \\    |            |     |    |  |____   |            |"<< endl;
    cout << "_______________________________________________________________________________" << endl;
    cout << "Bylo vytvoreno  " << __DATE__<< " v " << __TIME__ << ".\n\n\n";
}
inline string CurrentDateTime( string s ){
 time_t now = time(0);
    struct tm  tstruct;
    char  buf[80];
    tstruct = *localtime(&now);
    if(s=="now")
        strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
    else if(s=="date")
        strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
        return string(buf);
}
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
    CreateDirectoryA("C:\\Poraz_ostatni_hra\\others", NULL);
}
void prejdi(){
getch();
system("cls");

}
