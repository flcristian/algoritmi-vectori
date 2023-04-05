#include <iostream>
#include <fstream>

using namespace std;

// |=======|
// | BASIC |
// |=======|

// Citire - Metoda 1 (Fara dimensiune precizata in fisier)

void citireMethod1(int x[], int& n) {
	ifstream f("input1.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

// Citire - Metoda 2 (Cu dimensiune precizata in fisier)

void citireMethod2(int x[], int& n) {
	ifstream f("input2.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> x[i];
	}
	f.close();
}

// Afisare

void afisare(int x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

// Testare algoritmi Basic

void testareBasic() {
	int x[100], n;
	citireMethod1(x, n);
	cout << "Metoda 1 citire :\n\n";
	cout << "n = " << n << endl;
	afisare(x, n);
	
	int y[100], d;
	citireMethod2(y, d);
	cout << "\nMetoda 2 citire :\n\n";
	cout << "n = " << n << endl;
	afisare(y, d);
}

// |=========|
// | SORTING |
// |=========|

// Selection Sort

void selectionSort(int x[], int d) {
	for (int i = 0; i < d - 1; i++) {
		for (int j = i + 1; j < d; j++) {
			if (x[i] > x[j]) {
				int aux = x[i];
				x[i] = x[j];
				x[j] = aux;
			}
		}
	}
}

// Bubble Sort

void bubbleSort(int x[], int n) {
	bool flag = true;
	do {
		flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (x[i] > x[i + 1]) {
				int r = x[i];
				x[i] = x[i + 1];
				x[i + 1] = r;
				flag = false;
			}
		}
	} while (flag == false);
}

// Bubble Sort cu Santinela

void sentinelBubbleSort(int x[], int n) {
	int i = 0;
	bool flag = true;
	while (flag && i < n) {
		flag = false;
		for (int j = n - 1; j > i; j--) {
			if (x[j - 1] > x[j]) {
				int r = x[j - 1];
				x[j - 1] = x[j];
				x[j] = r;
				flag = true;
			}
		}
		i++;
	}
}

// Merge Sort

void merge(int x[], int min, int max, int mid) {
	int i, j, k, temp[100];
	i = min, k = 0, j = mid + 1;

	while (i <= mid && j <= max) {
		if (x[i] < x[j]) {
			temp[k] = x[i];
			k++;
			i++;
		}
		else {
			temp[k] = x[j];
			k++;
			j++;
		}
	}
	while (i <= mid) {
		temp[k] = x[i];
		k++;
		i++;
	}
	while (j <= max) {
		temp[k] = x[j];
		k++;
		j++;
	}

	for (int i = min; i <= max; i++) {
		x[i] = temp[i - min];
	}
}

void mergeSort(int x[], int min, int max) {
	int mid;
	if (min < max) {
		mid = (min + max) / 2;
		mergeSort(x, min, mid);
		mergeSort(x, mid + 1, max);
		merge(x, min, max, mid);
	}

}

// Testare algoritmi Sorting

void testareSorting() {
	int x1[100], x2[100], x3[100], x4[100], n1, n2, n3, n4;
	citireMethod1(x1, n1), citireMethod1(x2, n2);
	citireMethod1(x3, n3), citireMethod1(x4, n4);

	cout << "Metoda Selection Sort :\n\n";
	selectionSort(x1, n1);
	afisare(x1, n1);

	cout << "\nMetoda Bubble Sort :\n\n";
	bubbleSort(x2, n2);
	afisare(x2, n2);

	cout << "\nMetoda Bubble Sort cu Santinela :\n\n";
	sentinelBubbleSort(x3, n3);
	afisare(x3, n3);

	cout << "\nMetoda Merge Sort :\n\n";
	mergeSort(x4, 0, n4 - 1);
	afisare(x4, n4);
}

// |=====================|
// | INSERARE + STERGERE |
// |=====================|

// Inserarea unui numar in vector (pe o anumita pozitie)

void inserare(int x[], int& n, int numar, int pos) {
	for (int i = n; i > pos; i--) {
		x[i] = x[i - 1];
	}
	x[pos] = numar;
	n++;
}

// Stergerea unui numar din vector (de pe o anumita pozitie)

void stergere(int x[], int& n, int pos) {
	for (int i = pos; i < n - 1; i++) {
		x[i] = x[i + 1];
	}
	n--;
}

// Testare algoritmi Inserare si Stergere

void testareInserareStergere() {
	int x1[100], x2[100], n1, n2;
	citireMethod1(x1, n1);
	citireMethod1(x2, n2);

	cout << "Inserarea numarului '300' pe pozitia 5 :\n\n";
	inserare(x1, n1, 300, 5);
	afisare(x1, n1);

	cout << "\nStergerea numarului de pe pozitia 5 :\n\n";
	stergere(x2, n2, 5);
	afisare(x2, n2);
}

// |================|
// | CAUTARE BINARA |
// |================|

// Binary search

bool binarySearch(int x[], int s, int d, int n) {
	int m = (s + d) / 2;
	if (s > d) {
		return 0;
	}
	if (x[m] == n) {
		return true;
	}
	else {
		if (n < x[m]) {
			binarySearch(x, s, m - 1, n);
		}
		else {
			binarySearch(x, m + 1, d, n);
		}
	}

}

// Testare algoritm Binary Search

void testareBinarySearch() {
	int x[100], n;
	citireMethod1(x, n);
	mergeSort(x, 0, n - 1);

	cout << "Cautarea numarului '9' in vectorul :\n";
	afisare(x, n);
	if (binarySearch(x, 0, n - 1, 9)) {
		cout << "\nGasit!\n";
	}
	else {
		cout << "\nNu apartine!\n";
	}

	cout << "\nCautarea numarului '20' in vectorul :\n";
	afisare(x, n);
	if (binarySearch(x, 0, n - 1, 20)) {
		cout << "\nGasit!\n";
	}
	else {
		cout << "\nNu apartine!\n";
	}
}

// |===========|
// | FRECVENTA |
// |===========|

// Frecventa (numerele unui vector)

void frecventa(int x[], int n, int f[]) {
	for (int i = 0; i < n; i++) {
		f[x[i]]++;
	}
}

// Testare algoritm Frecventa

void testareFrecventa() {
	int x[17] = { 1,3,4,5,1,2,3,4,5,6,7,8,1,23,25,12,3 }, n = 17;
	int f[50]{};
	frecventa(x, n, f);
	for (int i = 0; i < 30; i++) {
		cout << "Numarul " << i << " apare de " << f[i] << " ori." << endl;
	}
}

// |==============|
// | INTERCLASARE |
// |==============|

// Interclasarea a doi vectori

void interclasare(int x[], int y[], int z[], int n, int m, int& d) {
	int i = 0, j = 0, k = 0;
	while (i < n && j < m) {
		if (x[i] == y[j]) {
			z[k] = x[i];
			i++;
			j++;
			k++;
		}
		else if (x[i] < y[j]) {
			z[k] = x[i];
			i++;
			k++;
		}
		else {
			z[k] = y[j];
			j++;
			k++;
		}
	}
	while (i < n) {
		z[k] = x[i];
		i++;
		k++;
	}
	while (j < m) {
		z[k] = y[j];
		j++;
		k++;
	}
	d = k;
}

// Testare algoritm Interclasare

void testareInterclasare() {
	int x[100], z[100], n, d;
	citireMethod1(x, n);
	mergeSort(x, 0, n - 1);
	int y[9] = { 1,2,6,6,7,9,13,23,113 }, m = 9;
	interclasare(x, y, z, n, m, d);
	cout << "Interclasarea vectorilor :\n";
	afisare(x, n);
	afisare(y, m);

	cout << "\nVectorul rezultat este :\n\n";
	afisare(z, d);
}

// |==========|
// | SECVENTE |
// |==========|

// Secventa (pentru exemplu, secventa maxima de numere pare)

void secventa(int x[], int& n, int& smax, int& dmax) {
	smax = 1, dmax = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] % 2 == 0) {
			int j = i;
			while (j + 1 < n && x[j + 1] % 2 == 0) {
				j++;
			}
			if (j - i + 1 > dmax - smax + 1) {
				smax = i, dmax = j;
			}
			i = j;
		}
	}
}

// Testare algoritm Secventa

void testareSecventa() {
	int x[100], n, smax, dmax;
	citireMethod2(x, n);

	secventa(x, n, smax, dmax);
	cout << "Pentru vectorul :\n";
	afisare(x, n);
	cout << "\nSecventa maxima de numere pare este :\n";
	for (int i = smax; i < dmax + 1; i++) {
		cout << x[i] << " ";
	}
}