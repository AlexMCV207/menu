#include <iostream>
#include <fstream>

using namespace std;


int Menu() {
    int x;
    cout << endl << "Menu" << endl;
    cout << "1. Dodaj element do tablicy" << endl;
    cout << "2. Wstaw element do tablicy" << endl;
    cout << "3. Usun element z tablicy" << endl;
    cout << "4. Wyswietl elementy tablicy" << endl;
    cout << "5. Zapisz do pliku" << endl;
    cout << "6. Wyjscie" << endl;
    cin >> x;
    return x;
}
int main()
{
    int *p = NULL;
    int n = 0;
    while(true)
    {
        switch(Menu())
        {
        case 1:
            {
                int *p1 = NULL;
                p1 = new int[n+1];
                if(p != NULL)
                {
                    for(int i = 0; i < n; i++)
                    {
                        p1[i] = p[i];
                    }
                    delete[] p;

                }
                cout << endl <<"Podaj wartosc elementu" << endl << endl;
                cin >> p1[n];
                p = p1;
                n++;
                break;
            }
        case 2:
            {
                int *p1 = NULL;
                p1 = new int[n+1];
                int d = 0;
                int w = 0;
                if(p != NULL)
                {
                    cout << endl << "Podaj indeks elementu" << endl << endl;
                    cin >> d;
                    while(d > n)
                    {
                        cout << endl << "Podano niepoprawna wartosc" << endl << endl;
                        cin >> d;
                    }
                    cout << endl << "Podaj wartosc elementu" << endl << endl;
                    cin >> w;
                    for(int i = 0; i < n+1; i++)
                    {
                        if(i >= d)
                        {
                            if(i == d)
                            {
                                p1[i] = w;
                            }
                            p1[i+1] = p[i];
                        }
                        else
                        {
                            p1[i] = p[i];
                        }
                    }
                    delete[] p;
                    p = p1;
                    n++;
                }
                else
                {
                    cout << endl << "Podaj wartosc elementu" << endl << endl;
                    cin >> p1[n];
                    cout << endl;
                    p = p1;
                    n++;
                }
                break;
            }
        case 3:
            {
                int *p1 = NULL;
                int d = 0;

                if(p != NULL)
                {
                    p1 = new int[n-1];
                    cout << endl << "Podaj indeks elementu" << endl << endl;
                    cin >> d;
                    while(d > n)
                    {
                        cout << endl <<  "Podano niepoprawna wartosc" << endl << endl;
                        cin >> d;
                    }
                    for(int i = 0; i < n; i++)
                    {
                        if(i > d)
                        {
                            p1[i-1] = p[i];
                        }
                        p1[i] = p[i];
                    }
                    delete[] p;
                    p = p1;
                    n--;

                }
                else
                {
                    cout << endl << "Tablica jest pusta" << endl;
                }
                break;
            }
        case 4:
            {
                if(p != NULL)
                {
                    cout << endl << "Zawartosc tablicy: " << endl;
                    for(int i = 0; i < n; i++)
                    {
                        cout << p[i] << ", ";
                    }
                    cout << endl;
                }
                else
                {
                    cout << endl << "Tablica jest pusta" << endl << endl;
                }
                break;
            }
        case 5:
            {
                fstream plik;
                plik.open("C:\\zapis.txt", ios::out | ios::app);
                if(plik.is_open())
                {
                    for(int i = 0; i < n; i++)
                    {
                        plik << p[i] << ", ";
                    }
                    cout << endl;
                    plik.close();
                    cout << "Udało się zapisać" << endl;
                }
                else
                {
                    cout << "Nie udało się zapisać" << endl;
                }

                break;
            }
        case 6:
            {
                return 0;
            }
        }
    }
}
