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
void wygenerujSlownik();


int const ILOSC_HASEL_W_PLIKU_FILE = 439;

int main(int argc, const char * argv[]) {

    wygenerujSlownik();


    int proby = ILOSC_PROB;
    string slowa[ILOSC_GENEROWANYCH_SLOW];
    string klucz, odpowiedz;
    srand((unsigned)time(NULL));

    ifstream file("file.txt");

    if (file){
        cout<<"Witaj!\nZapraszam do gry w zgadywanie słowa. \nPowodzenia.\n";
    }


    else{
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

    // wlasciwa czesc programu

 //  wyswietlTabliceZeSlowami(slowa);
    //cout<<klucz<<endl;
    initscr();
   // while(proby--){
       /* cin>>odpowiedz;
        if(odpowiedz == klucz) {
            break;
        }
        sprawdzOdpowiedz(odpowiedz, klucz);


        */
         //1
        keypad( stdscr, TRUE );
        noecho();
        int licznik;
        int znak;
        while(znak != 10){
            printw( "wybierz odpowiedz i wcisnij enter\n" );
            noecho();
        znak = getch();
        switch (znak) {
            case 260:
                odpowiedz=slowa[1];
                printw( "dupa %s",odpowiedz);
                break;
            case 261:
                printw( "strzalka w prawo" );
                break;
            case 259:
                printw( "strzalka w gore\n" );
                break;
            case 258:
                printw( "strzalka w dol\n" );
                break;
            default:
                break;
        }
        }

        printw( "Hello World !!!" ); //2
        getch(); //3
         //4

//    }
    if (proby >= 0) {
        cout<<"ZGADLES YUPI!! DOSTALES MILION PKT DOSWIADCZENIA\n";
    } else {
        cout<<"NIESTETY NIE WYSZLO I JUZ NIGDY SIE NIE DOWIESZ JAKIE DANE POSIADAL TEN ZABEZPIECZONY TERMINAL\n";
    }
    printw( "nacisnij dowolny klawisz..." ); //2
    getch();
    endwin();

    return 0;
}

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
        }
    }

}

void sprawdzOdpowiedz(string odpowiedz, string klucz){
    int licznik = 0;
    for(int i=0;i<ILOSC_LITER_W_KAZDYM_SLOWIE;i++){
        if(odpowiedz[i] == klucz[i]){
            licznik++;
        }
        }
        cout<<"Nieudana proba. Trafileś: "<<licznik<<"/"<<ILOSC_LITER_W_KAZDYM_SLOWIE<<endl;

}

void wygenerujSlownik() {

    ofstream file("file.txt");
    file<<"taniec"<<endl;
    file<<"aceton"<<endl;
    file<<"tonice"<<endl;
    file<<"tarcie"<<endl;
    file<<"tracie"<<endl;
    file<<"centra"<<endl;
    file<<"cetnar"<<endl;
    file<<"tarnce"<<endl;
    file<<"trance"<<endl;
    file<<"cerato"<<endl;
    file<<"otarci"<<endl;
    file<<"torcie"<<endl;
    file<<"trocie"<<endl;
    file<<"contra"<<endl;
    file<<"centro"<<endl;
    file<<"trocin"<<endl;
    file<<"astice"<<endl;
    file<<"siatce"<<endl;
    file<<"stance"<<endl;
    file<<"stanic"<<endl;
    file<<"incest"<<endl;
    file<<"asceto"<<endl;
    file<<"ciasto"<<endl;
    file<<"stanco"<<endl;
    file<<"stonce"<<endl;
    file<<"ostnic"<<endl;
    file<<"starce"<<endl;
    file<<"starci"<<endl;
    file<<"straci"<<endl;
    file<<"castor"<<endl;
    file<<"castro"<<endl;
    file<<"escort"<<endl;
    file<<"trosce"<<endl;
    file<<"watcie"<<endl;
    file<<"wiatce"<<endl;
    file<<"tacowe"<<endl;
    file<<"tacowi"<<endl;
    file<<"trawce"<<endl;
    file<<"wtarci"<<endl;
    file<<"wrotce"<<endl;
    file<<"stawce"<<endl;
    file<<"swatce"<<endl;
    file<<"ostwic"<<endl;
    file<<"carstw"<<endl;
    file<<"zatoce"<<endl;
    file<<"natocz"<<endl;
    file<<"toczna"<<endl;
    file<<"toczne"<<endl;
    file<<"toczni"<<endl;
    file<<"czerta"<<endl;
    file<<"tarcze"<<endl;
    file<<"tracze"<<endl;
    file<<"trzeci"<<endl;
    file<<"trencz"<<endl;
    file<<"trzcin"<<endl;
    file<<"czorta"<<endl;
    file<<"tarczo"<<endl;
    file<<"czerto"<<endl;
    file<<"stacze"<<endl;
    file<<"szatce"<<endl;
    file<<"sztanc"<<endl;
    file<<"starcz"<<endl;
    file<<"stercz"<<endl;
    file<<"strecz"<<endl;
    file<<"strzec"<<endl;
    file<<"sztorc"<<endl;
    file<<"zwitce"<<endl;
    file<<"wstecz"<<endl;
    file<<"ocenia"<<endl;
    file<<"arnice"<<endl;
    file<<"cierna"<<endl;
    file<<"narcie"<<endl;
    file<<"rancie"<<endl;
    file<<"aorcie"<<endl;
    file<<"ociera"<<endl;
    file<<"orance"<<endl;
    file<<"carino"<<endl;
    file<<"oranci"<<endl;
    file<<"roncie"<<endl;
    file<<"ciasne"<<endl;
    file<<"nasiec"<<endl;
    file<<"scanie"<<endl;
    file<<"ciasno"<<endl;
    file<<"nacios"<<endl;
    file<<"nosaci"<<endl;
    file<<"scanio"<<endl;
    file<<"niosce"<<endl;
    file<<"sionce"<<endl;
    file<<"aserci"<<endl;
    file<<"siarce"<<endl;
    file<<"sracie"<<endl;
    file<<"sernic"<<endl;
    file<<"corsie"<<endl;
    file<<"sorcie"<<endl;
    file<<"atonie"<<endl;
    file<<"taonie"<<endl;
    file<<"arenit"<<endl;
    file<<"nitera"<<endl;
    file<<"tarnie"<<endl;
    file<<"terani"<<endl;
    file<<"tranie"<<endl;
    file<<"arieto"<<endl;
    file<<"otarie"<<endl;
    file<<"teoria"<<endl;
    file<<"tenora"<<endl;
    file<<"terano"<<endl;
    file<<"tonera"<<endl;
    file<<"orient"<<endl;
    file<<"tronie"<<endl;
    file<<"asient"<<endl;
    file<<"nastie"<<endl;
    file<<"stanie"<<endl;
    file<<"tenisa"<<endl;
    file<<"nosate"<<endl;
    file<<"setona"<<endl;
    file<<"nastio"<<endl;
    file<<"nastoi"<<endl;
    file<<"sotnia"<<endl;
    file<<"sotnie"<<endl;
    file<<"reista"<<endl;
    file<<"trasie"<<endl;
    file<<"insert"<<endl;
    file<<"retsin"<<endl;
    file<<"teraso"<<endl;
    file<<"ostria"<<endl;
    file<<"satori"<<endl;
    file<<"sirota"<<endl;
    file<<"ostrie"<<endl;
    file<<"reisto"<<endl;
    file<<"sierot"<<endl;
    file<<"sortie"<<endl;
    file<<"torsie"<<endl;
    file<<"astron"<<endl;
    file<<"narost"<<endl;
    file<<"storna"<<endl;
    file<<"strona"<<endl;
    file<<"estron"<<endl;
    file<<"nestor"<<endl;
    file<<"sotern"<<endl;
    file<<"tensor"<<endl;
    file<<"storni"<<endl;
    file<<"stroni"<<endl;
    file<<"cwanie"<<endl;
    file<<"wancie"<<endl;
    file<<"aowiec"<<endl;
    file<<"cenowa"<<endl;
    file<<"cenowi"<<endl;
    file<<"warcie"<<endl;
    file<<"wciera"<<endl;
    file<<"nerwic"<<endl;
    file<<"carowe"<<endl;
    file<<"cerowa"<<endl;
    file<<"carowi"<<endl;
    file<<"ircowa"<<endl;
    file<<"cerowi"<<endl;
    file<<"ircowe"<<endl;
    file<<"wnorce"<<endl;
    file<<"cisawe"<<endl;
    file<<"siewca"<<endl;
    file<<"swacie"<<endl;
    file<<"cisowa"<<endl;
    file<<"owsica"<<endl;
    file<<"wciosa"<<endl;
    file<<"cisowe"<<endl;
    file<<"owsice"<<endl;
    file<<"siewco"<<endl;
    file<<"wiosce"<<endl;
    file<<"witane"<<endl;
    file<<"otawie"<<endl;
    file<<"natowi"<<endl;
    file<<"nitowa"<<endl;
    file<<"tanowi"<<endl;
    file<<"witano"<<endl;
    file<<"netowi"<<endl;
    file<<"nitowe"<<endl;
    file<<"trawie"<<endl;
    file<<"tawern"<<endl;
    file<<"trawin"<<endl;
    file<<"terowa"<<endl;
    file<<"towera"<<endl;
    file<<"otrawi"<<endl;
    file<<"tarowi"<<endl;
    file<<"triowa"<<endl;
    file<<"retowi"<<endl;
    file<<"terowi"<<endl;
    file<<"triowe"<<endl;
    file<<"nawrot"<<endl;
    file<<"trwano"<<endl;
    file<<"wrotna"<<endl;
    file<<"wrotne"<<endl;
    file<<"trwoni"<<endl;
    file<<"wrotni"<<endl;
    file<<"stawie"<<endl;
    file<<"stawne"<<endl;
    file<<"stawni"<<endl;
    file<<"setowa"<<endl;
    file<<"ostawi"<<endl;
    file<<"owista"<<endl;
    file<<"sitowa"<<endl;
    file<<"sowita"<<endl;
    file<<"ostwie"<<endl;
    file<<"setowi"<<endl;
    file<<"sitowe"<<endl;
    file<<"sowiet"<<endl;
    file<<"sowite"<<endl;
    file<<"wstano"<<endl;
    file<<"swetra"<<endl;
    file<<"strawi"<<endl;
    file<<"wistra"<<endl;
    file<<"siwert"<<endl;
    file<<"strawo"<<endl;
    file<<"stwora"<<endl;
    file<<"ostrew"<<endl;
    file<<"ostrwi"<<endl;
    file<<"wiorst"<<endl;
    file<<"wistro"<<endl;
    file<<"zaceni"<<endl;
    file<<"zacnie"<<endl;
    file<<"znacie"<<endl;
    file<<"azocie"<<endl;
    file<<"cenoza"<<endl;
    file<<"oznace"<<endl;
    file<<"zacier"<<endl;
    file<<"czarne"<<endl;
    file<<"reczan"<<endl;
    file<<"czarni"<<endl;
    file<<"czerni"<<endl;
    file<<"oracze"<<endl;
    file<<"orzcie"<<endl;
    file<<"czarno"<<endl;
    file<<"ranczo"<<endl;
    file<<"roczna"<<endl;
    file<<"cenzor"<<endl;
    file<<"roczne"<<endl;
    file<<"roczni"<<endl;
    file<<"czasie"<<endl;
    file<<"szacie"<<endl;
    file<<"zasiec"<<endl;
    file<<"naczes"<<endl;
    file<<"cenisz"<<endl;
    file<<"sznice"<<endl;
    file<<"ascezo"<<endl;
    file<<"zacios"<<endl;
    file<<"ciosze"<<endl;
    file<<"ociesz"<<endl;
    file<<"osiecz"<<endl;
    file<<"szocie"<<endl;
    file<<"nosacz"<<endl;
    file<<"cesarz"<<endl;
    file<<"raszce"<<endl;
    file<<"sacrze"<<endl;
    file<<"sracze"<<endl;
    file<<"szarce"<<endl;
    file<<"szrenc"<<endl;
    file<<"srocza"<<endl;
    file<<"srocze"<<endl;
    file<<"zatnie"<<endl;
    file<<"entazo"<<endl;
    file<<"tiarze"<<endl;
    file<<"natrze"<<endl;
    file<<"artzin"<<endl;
    file<<"trznia"<<endl;
    file<<"retzin"<<endl;
    file<<"orteza"<<endl;
    file<<"rozeta"<<endl;
    file<<"zetora"<<endl;
    file<<"trioza"<<endl;
    file<<"izoter"<<endl;
    file<<"nitroz"<<endl;
    file<<"zaiste"<<endl;
    file<<"stanze"<<endl;
    file<<"szatne"<<endl;
    file<<"szatni"<<endl;
    file<<"tniesz"<<endl;
    file<<"zastoi"<<endl;
    file<<"stanzo"<<endl;
    file<<"szanto"<<endl;
    file<<"sztona"<<endl;
    file<<"szinto"<<endl;
    file<<"areszt"<<endl;
    file<<"astrze"<<endl;
    file<<"ersatz"<<endl;
    file<<"ratsze"<<endl;
    file<<"reszta"<<endl;
    file<<"starze"<<endl;
    file<<"terasz"<<endl;
    file<<"riszta"<<endl;
    file<<"sitarz"<<endl;
    file<<"transz"<<endl;
    file<<"ostrza"<<endl;
    file<<"szarot"<<endl;
    file<<"szatro"<<endl;
    file<<"trzosa"<<endl;
    file<<"zarost"<<endl;
    file<<"ostrze"<<endl;
    file<<"reszto"<<endl;
    file<<"storze"<<endl;
    file<<"trosze"<<endl;
    file<<"zoster"<<endl;
    file<<"riszto"<<endl;
    file<<"troisz"<<endl;
    file<<"znawce"<<endl;
    file<<"niwecz"<<endl;
    file<<"zwince"<<endl;
    file<<"aowcze"<<endl;
    file<<"cezowa"<<endl;
    file<<"cezowi"<<endl;
    file<<"znawco"<<endl;
    file<<"rwacze"<<endl;
    file<<"zwarci"<<endl;
    file<<"czerwi"<<endl;
    file<<"wzorca"<<endl;
    file<<"wzorce"<<endl;
    file<<"zworce"<<endl;
    file<<"szewca"<<endl;
    file<<"cewisz"<<endl;
    file<<"wciesz"<<endl;
    file<<"soczew"<<endl;
    file<<"wciosz"<<endl;
    file<<"szwarc"<<endl;
    file<<"zawite"<<endl;
    file<<"tezowa"<<endl;
    file<<"tezowi"<<endl;
    file<<"zetowi"<<endl;
    file<<"trzewa"<<endl;
    file<<"twarze"<<endl;
    file<<"watrze"<<endl;
    file<<"zwarte"<<endl;
    file<<"trzewi"<<endl;
    file<<"wietrz"<<endl;
    file<<"zwarto"<<endl;
    file<<"tworze"<<endl;
    file<<"zestaw"<<endl;
    file<<"witasz"<<endl;
    file<<"zostaw"<<endl;
    file<<"trwasz"<<endl;
    file<<"szwert"<<endl;
    file<<"wzrost"<<endl;
    file<<"aronie"<<endl;
    file<<"oranie"<<endl;
    file<<"naosie"<<endl;
    file<<"oseina"<<endl;
    file<<"osiane"<<endl;
    file<<"sarnie"<<endl;
    file<<"sranie"<<endl;
    file<<"eranos"<<endl;
    file<<"osrane"<<endl;
    file<<"osrani"<<endl;
    file<<"orsein"<<endl;
    file<<"senior"<<endl;
    file<<"owiane"<<endl;
    file<<"narwie"<<endl;
    file<<"newari"<<endl;
    file<<"rwanie"<<endl;
    file<<"warnie"<<endl;
    file<<"wierna"<<endl;
    file<<"worane"<<endl;
    file<<"narowi"<<endl;
    file<<"worani"<<endl;
    file<<"wronia"<<endl;
    file<<"onerwi"<<endl;
    file<<"renowi"<<endl;
    file<<"wronie"<<endl;
    file<<"siewna"<<endl;
    file<<"sinawe"<<endl;
    file<<"wsiane"<<endl;
    file<<"nosiwa"<<endl;
    file<<"sanowi"<<endl;
    file<<"wiosna"<<endl;
    file<<"wsiano"<<endl;
    file<<"senowi"<<endl;
    file<<"wiosen"<<endl;
    file<<"warsie"<<endl;
    file<<"rasowe"<<endl;
    file<<"serowa"<<endl;
    file<<"rasowi"<<endl;
    file<<"serowi"<<endl;
    file<<"ozanie"<<endl;
    file<<"nairze"<<endl;
    file<<"nieraz"<<endl;
    file<<"ziaren"<<endl;
    file<<"zorane"<<endl;
    file<<"arizon"<<endl;
    file<<"naziro"<<endl;
    file<<"ziarno"<<endl;
    file<<"zorani"<<endl;
    file<<"orznie"<<endl;
    file<<"zanosi"<<endl;
    file<<"znosie"<<endl;
    file<<"siarze"<<endl;
    file<<"szarie"<<endl;
    file<<"ranisz"<<endl;
    file<<"szreni"<<endl;
    file<<"orisza"<<endl;
    file<<"szario"<<endl;
    file<<"zarosi"<<endl;
    file<<"orisze"<<endl;
    file<<"szaron"<<endl;
    file<<"szoner"<<endl;
    file<<"ronisz"<<endl;
    file<<"nazwie"<<endl;
    file<<"zwanie"<<endl;
    file<<"zwiane"<<endl;
    file<<"ozwane"<<endl;
    file<<"nawozi"<<endl;
    file<<"ozwani"<<endl;
    file<<"wizona"<<endl;
    file<<"wozina"<<endl;
    file<<"zinowa"<<endl;
    file<<"zwiano"<<endl;
    file<<"zenowi"<<endl;
    file<<"zinowe"<<endl;
    file<<"zarwie"<<endl;
    file<<"zwiera"<<endl;
    file<<"rzewna"<<endl;
    file<<"rzewni"<<endl;
    file<<"razowe"<<endl;
    file<<"zerowa"<<endl;
    file<<"razowi"<<endl;
    file<<"wiroza"<<endl;
    file<<"zerowi"<<endl;
    file<<"wrzano"<<endl;
    file<<"newroz"<<endl;
    file<<"wiesza"<<endl;
    file<<"zasiew"<<endl;
    file<<"awosze"<<endl;
    file<<"wiosze"<<endl;
    file<<"nowsza"<<endl;
    file<<"nowsze"<<endl;
    file<<"wznios"<<endl;
    file<<"wznosi"<<endl;
    file<<"wiszar"<<endl;
    file<<"rwiesz"<<endl;
    file<<"wiersz"<<endl;
    file<<"szewro"<<endl;
    file<<"wiszor"<<endl;
    
}

