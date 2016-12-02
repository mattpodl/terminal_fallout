/*

 Created by Mateusz Podlasinski on 02.12.2016.
 Copyright © 2016 Mateusz Podlasinski. All rights reserved.

 Gra w zgadywanie hasla. Uzytkownik ma 4 szanse.

 */
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <ncurses.h>


#include "generatorSlow.hpp"

using namespace std;

int const ILOSC_GENEROWANYCH_SLOW = 12;
int const ILOSC_PROB = 4;
int const ILOSC_LITER_W_KAZDYM_SLOWIE = 6;


void wyswietlTabliceZeSlowami(string slowa[]);
void sprawdzOdpowiedz(string odpowiedz, string klucz);
void czekaj( double sekundy );
void dzwiek(){
    cout << "\a";
}


int const ILOSC_HASEL_W_PLIKU_FILE = 439;

int main(int argc, const char * argv[]) {

    wygenerujSlownik();


    int proby = ILOSC_PROB;
    string slowa[ILOSC_GENEROWANYCH_SLOW];
    string klucz, odpowiedz;
    string powitanie = "TERMINAL ROBOCORP\nLOGIN: ADMIN\nPODAJ HASLO\n";

    srand((unsigned)time(NULL));


    ifstream file("file.txt");

    if (file){
        for(int i=0;i<powitanie.size();i++){
            cout<<powitanie[i];
            czekaj(0.01);
            if (powitanie[i] == '\n'){
                dzwiek();
                czekaj(1);
            }
    }


    }
    else {
        cout<<"brak pliku zrodlowego"<<endl;
    }

    // losowanie generowanych slow w zadeklarowanej na poczatku ilosci i wpisanie ich do tablicy slowa[]
    for(int j=0;j<ILOSC_GENEROWANYCH_SLOW;j++){
        int linia = ((int)rand() % ILOSC_HASEL_W_PLIKU_FILE)+1;
        file.seekg(0, ios::beg);

        for(int i=1;i<=linia;i++){
            getline(file, slowa[j]);
        }
    }
    // wylosowanie slowa "klucz" z wybranych powyzej
    int random = (rand() % ILOSC_GENEROWANYCH_SLOW);
    klucz = slowa[random];

/***************************
*
*  wlasciwa czesc programu
*
***************************/

   wyswietlTabliceZeSlowami(slowa);

    while(proby--){
        cout<<"pozostało "<<proby<<" prob. Podaj odpowiedz"<<endl;
        cin>>odpowiedz;
        if(odpowiedz == klucz) {
            break;
        }
        sprawdzOdpowiedz(odpowiedz, klucz);



    }
    if (proby >= 0) {
        cout<<"\n\n\n\n\n\n\n\n";
        cout<<"LOGIN: ADMIN"<<endl;
        dzwiek();
        czekaj(1);
        cout<<"HASLO: ******"<<endl;
        dzwiek();
        czekaj(1);
        cout<<"\n\n\n\n\n\n\n\n";

    } else {
        cout<<"ACCESS DIENIED"<<endl;
    }
    std::cout << "LOGGING OUT..." << std::endl;
    for( int i = 5; i > 0; i-- ) {
        for(int j=0;j<i;j++){
        cout << ".";
        }
        cout<<endl;
        czekaj( 1 );
        dzwiek();

    }

    return 0;
}
/*****************************************************/

void wyswietlTabliceZeSlowami(string slowa[]){
    srand((unsigned)time(NULL));


    char znak[] = {'$' , '%','#','<','>','@','!','^','&','(',')','[',']','{','}','?'};
    for(int i=0; i<ILOSC_GENEROWANYCH_SLOW;i++){
        int random1 = (rand() % 20);
        cout<<" 0xF"<<(random1+6)%9<<"F"<<(random1+8)%10<<" ";
        for(int j=0;j<random1;j++){
            int random2 = (rand() % 16);
            cout<<znak[random2];
        }
        cout<<slowa[i];
        for(int j=(20-random1);j>=0;j--){
            int random2 = (rand() % 16);
            cout<<znak[random2];
        }
        if(i % 2 != 0){
            cout<<endl;
            dzwiek();
            czekaj(1);
        }
    }

}

/*****************************************************/
void sprawdzOdpowiedz(string odpowiedz, string klucz){
    int licznik = 0;
    for(int i=0;i<ILOSC_LITER_W_KAZDYM_SLOWIE;i++){
        if(odpowiedz[i] == klucz[i]){
            licznik++;
        }
        }
        cout<<"Nieudana proba. Trafileś: "<<licznik<<"/"<<ILOSC_LITER_W_KAZDYM_SLOWIE<<endl;

}

/*****************************************************/
void czekaj( double sekundy ){
    clock_t koniec_czekania;
    koniec_czekania = clock() + sekundy * CLOCKS_PER_SEC;
    while( clock() < koniec_czekania ) { }
}

