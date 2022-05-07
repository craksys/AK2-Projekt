
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Tablica.cpp"
#include <windows.h>
#include <iomanip>


Tablica tablica;
using namespace std;

long long int read_QPC() //pomiar czasu funkcja
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}

void print_benchmark(long long int elapsed, long long int frequency) {
    cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
        frequency << endl;
    cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
        frequency << endl;
    cout << "Time [us] = " << setprecision(3) << (1000000.0 * elapsed) /
        frequency << endl << endl;
}

int main()
{
    float wynik = 0;
    double sum = 0;
    int random = 0;
    srand(time(NULL));
    bool is_tab_created = false;
    bool is_list_created = false;
    bool is_mound_created = false;
    short menu;

    //testy 
    long long int frequency, start, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
    //start = read_QPC();
    //elapsed = read_QPC() - start;
    //system("PAUSE");
    //return 1;

    cout << "Projekt AK2" << endl;
    cout << "Autor: Kamil Kochan, Jakub Fita" << endl;

    while (true) {

        cout << endl << "Wybierz funkcje: " << endl;
        cout << "1. Tablica dynamiczna" << endl;
        cin >> menu;

        while (menu == 1) {
            int select = 0;
            int help1 = 0;
            int help2 = 0;
            if (is_tab_created == false) {
                tablica.getSizeOfTab();
                start = read_QPC(); //rozpoczęcie pomiaru czasu
                tablica.createTabAndFillWithNull();
                elapsed = read_QPC() - start; //zakończenie pomiaru czasu
                is_tab_created = true;
            }
            cout << endl << "Dostepne operacje: " << endl;
            cout << "1. Wykonaj Benchmark (czas)" << endl;
            cout << "2. Wyjdz" << endl;
            cout << "Wpisz: ";
            cin >> select;
            switch (select) {
            case 1:
                cout << endl << "Czas tworzenia sie struktury: " << endl;
                print_benchmark(elapsed, frequency);  //wynik
                start = read_QPC(); //rozpoczęcie pomiaru czasu
                tablica.fillWithRandomData();
                elapsed = read_QPC() - start; //zakończenie pomiaru czasu
                cout << "Czas wypelniania tabicy danymi wynosi: " << endl;
                print_benchmark(elapsed, frequency);  //wynik
                start = read_QPC(); //rozpoczęcie pomiaru czasu
                tablica.sort_Tab();
                elapsed = read_QPC() - start; //zakończenie pomiaru czasu
                cout << "Czas sortowania struktury: " << endl;
                print_benchmark(elapsed, frequency);  //wynik
                break;
            case 2:
                menu = 0;
                break;
            default:
                break;
            }
        }
    }
}


