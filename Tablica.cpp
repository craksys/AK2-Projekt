#include <iostream>
#include <fstream> //import biblioteki fstream
#include <stdio.h> //import biblioteki stdio.h
using namespace std;
class Tablica {
public:

	int size_of_tab = 1; //rozmiar tablicy dynamicznej
	int actual_size_of_tab = 1;
	int* pointerTab; //wskaŸnik na tablicê 

	void delete_Tab() {
		int* tab = new int[1];
		tab[0] = 0;
		pointerTab = tab;
		size_of_tab = 1;

	}
	void getSizeOfTab() {
		cout << "Podaj rozmiar tablicy: ";
		cin >> size_of_tab;
		if (size_of_tab < 1) { size_of_tab = 1; }
		actual_size_of_tab = size_of_tab;
	}

	void createTabAndFillWithNull() { //wyzerowanie tablicy aby unikn¹æ b³êdnych danych
		int* tab = new int[size_of_tab]; //deklaracja tablicy dynamicznej
		pointerTab = tab; //przypisanie tablicy do wskaŸnika


		for (int i = 0; i < size_of_tab; i++) { //wype³nij tablice nullami 
			tab[i] = NULL;
		}
	}

	void fillWithRandomData() {
		srand(time(NULL));

		for (int i = 0; i < actual_size_of_tab; i++) { //wpisanie losowych licz do tablicy
			pointerTab[i] = rand() % 10000; //zakres losowanych liczb do tablicy
		}
	}

	void printAllVeriables() {
		for (int i = 0; i < actual_size_of_tab; i++) {
			cout << pointerTab[i] << "|";
		}
		cout << "\n";
	}

	void addFirstElement(int element) {
		int* tempTab = new int[actual_size_of_tab + 1];
		tempTab[0] = element;

		for (int i = 0; i < actual_size_of_tab; i++) {
			tempTab[i + 1] = pointerTab[i];
		}
		actual_size_of_tab++;
		delete pointerTab;

		int* tab = new int[actual_size_of_tab];
		pointerTab = tab;


		for (int i = 0; i < actual_size_of_tab; i++) {
			tab[i] = tempTab[i];
		}
		delete tempTab;
	}

	void addLastElement(int element) {
		int* tempTab = new int[actual_size_of_tab + 1]; //tworzenie tablicy tymczasowej

		for (int i = 0; i < actual_size_of_tab; i++) {
			tempTab[i] = pointerTab[i];
		}
		actual_size_of_tab++;
		tempTab[actual_size_of_tab - 1] = element;
		delete pointerTab;

		int* tab = new int[actual_size_of_tab];

		for (int i = 0; i < actual_size_of_tab; i++) {
			tab[i] = tempTab[i];
		}
		pointerTab = tab;

		delete tempTab;
	}

	void removeFirstElement() {
		int* tempTab = new int[actual_size_of_tab - 1]; //tworzenie tablicy tymczasowej

		for (int i = 0; i < actual_size_of_tab - 1; i++) {
			tempTab[i] = pointerTab[i + 1];
		}

		delete pointerTab; //usuniêcie starej tablicy
		actual_size_of_tab--;
		int* tab = new int[actual_size_of_tab]; //ponowne utworzenie tablicy

		for (int i = 0; i < actual_size_of_tab; i++) {
			tab[i] = tempTab[i];
		}

		pointerTab = tab; //przypisanie nowej tablicy do wskaŸnika
		delete tempTab; //usuniêcie tablicy tymczasowej
	}

	void removeLastElement() {
		int* tempTab = new int[actual_size_of_tab - 1]; //tworzenie tablicy tymczasowej

		for (int i = 0; i < actual_size_of_tab - 1; i++) { //przepisanei wartoœci do tablicy tymczasowej
			tempTab[i] = pointerTab[i];
		}

		delete pointerTab;
		actual_size_of_tab--;
		int* tab = new int[actual_size_of_tab]; //ponowne utworzenie tablicy

		for (int i = 0; i < actual_size_of_tab; i++) {
			tab[i] = tempTab[i];
		}
		pointerTab = tab; //przypisanie nowej tablicy do wskaŸnika
		delete tempTab; //usuniêcie tablicy tymczasowej
	}

	void addSelectedElement(int position, int element) {
		int* tempTab = new int[actual_size_of_tab + 1]; //tworzenie tablicy tymczasowej

		if (position < 0 || position > actual_size_of_tab) { //sprawdzanie czy mo¿na zapisaæ dane w podane miesjce
			cout << "\nPrzekroczono zakres tablicy!!!";
			return;
		}
		tempTab[position] = element;//wpisanie elementu na podan¹ pozycjê

		for (int i = 0; i < actual_size_of_tab + 1; i++) {
			if (i < position) {
				tempTab[i] = pointerTab[i];
			}
			else if (i > position) {
				tempTab[i] = pointerTab[i - 1];
			}
		}
		delete pointerTab;
		actual_size_of_tab++;
		int* tab = new int[actual_size_of_tab]; //ponowne utworzenie tablicy
		for (int i = 0; i < actual_size_of_tab; i++) {
			tab[i] = tempTab[i];
		}
		pointerTab = tab; //przypisanie nowej tablicy do wskaŸnika
		delete tempTab; //usuniêcie tablicy tymczasowe

	}

	void removeSelectedElement(int position) {
		int* tempTab = new int[actual_size_of_tab - 1]; //tworzenie tablicy tymczasowej

		if (position < 0 || position > actual_size_of_tab) { //sprawdzanie czy mo¿na usun¹æ dane w podanym miesjce
			cout << "\nPrzekroczono zakres tablicy!!!";
			return;
		}

		for (int i = 0; i < actual_size_of_tab; i++) {
			if (i < position) {
				tempTab[i] = pointerTab[i];
			}
			else if (i > position) {
				tempTab[i - 1] = pointerTab[i];
			}
		}
		delete pointerTab;
		actual_size_of_tab--;
		int* tab = new int[actual_size_of_tab]; //ponowne utworzenie tablicy

		for (int i = 0; i < actual_size_of_tab; i++) {
			tab[i] = tempTab[i];
		}
		pointerTab = tab; //przypisanie nowej tablicy do wskaŸnika
		delete tempTab; //usuniêcie tablicy tymczasowe
	}

	void searchElement(int tofind) {
		bool is_find = false;
		for (int i = 0; i < actual_size_of_tab; i++) {
			if (pointerTab[i] == tofind) {
				cout << "\nZnaleziono na pozycji: " << i;
				is_find = true;
			}
		}
		if (is_find == false) { cout << endl << "Nie znaleziono pasujacych elementow"; } //jezeli nie znalezion napisz
	}

	void sort_Tab() {
		int bufor = 0;
		int stop = 0;
		for (int j = 0; j < size_of_tab; j++) {
			for (int i = 0; i < size_of_tab - 1; i++) {
				if (pointerTab[i] < pointerTab[i + 1]) {
					bufor = pointerTab[i];
					pointerTab[i] = pointerTab[i + 1];
					pointerTab[i + 1] = bufor;
					stop++;
				}
			}
			if (stop == 0) { return; }
			else { stop = 0; }
		}
	}


};
