#include <iostream>
#include <vector>
#include <chrono> // Do pomiaru czasu
#include <math.h> //sqrt
using namespace std;

// Funkcja realizująca algorytm generowania liczb p
void generujL(int64_t rozmiar)
{
    // Tworzymy wektor uint8_t 8bit
    vector<uint8_t> A(rozmiar / 3 + 1, true);     // wektor 8bitowy -gdy true przypisana komórce liczba typu p
    int64_t sqrtmax_wart = sqrt(rozmiar) / 3 + 1; // liczymy pod jakim indexem to sqrtmax_wart się znajdzie;
    size_t a1, a2, a3, a4, r, c;
    size_t max_size = A.size();
    for (size_t i = 0; i < sqrtmax_wart; i += 2) // nn,np
    {
        c = 3 * i * i;        // Wspólna część dla wszystkich wzorów
        a1 = c + 10 * i + 8;  // nn
        a2 = c + 12 * i + 11; // np
        a3 = c + 12 * i + 11; // i+1 pn
        a4 = c + 14 * i + 16; // i+1 pp
        r = 6 * i + 10;
        for (a1; a1 < max_size; a1 += r)
        {
            A[a1] = false;
            if (a2 < max_size)
            {
                A[a2] = false;
                a2 += r;
            }
            if (a3 < max_size)
            {
                A[a3] = false;
                a3 += r + 4;
            }
            if (a4 < max_size)
            {
                A[a4] = false;
                a4 += r + 4;
            }
        }
    }
    int liczbaPierwszych = 2;
    cout << "2, 3, ";
    for ( int i = 1;i < A.size();++i)
    {
        if (A[i])
        cout << ((i & 1) ? 3 * i + 2 : 3 * i + 1) << ", ";
        liczbaPierwszych++;
    }
    cout <<"Ilość liczb pierwszych: " << liczbaPierwszych << endl;
 }
int main()
{
    int64_t rozmiar = 100LL; // 10^?
    cout << "zakres: " << rozmiar << endl;
    // Pomiar czasu dla algorytmu generowania liczb pierwszych
    auto start = chrono::high_resolution_clock::now();
    generujL(rozmiar);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> czasWykonania = end - start;
    cout << "Czas wykonania (algorytm generowania liczb pierwszych): " << czasWykonania.count() << " sekund" << endl;
    return 0;
}
