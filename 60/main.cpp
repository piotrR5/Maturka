#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void znajdz_dzielniki(int liczba,vector<int>&dzielniki)
{
    for(int i=1; i<=liczba; i++)
    {
        if(liczba%i==0 && i!=1)
        {
            dzielniki.push_back(i);
        }
    }
}

void zad_2(int liczba,vector<int>&dzielniki)
{
    int liczba_dzielnikow=0;
    for(int i=1; i<=liczba; i++)
    {
        if(liczba%i==0)
        {
            liczba_dzielnikow++;
        }
    }

    if(liczba_dzielnikow==18)
    {
        cout<<liczba<<endl;
        for(int i=1; i<=liczba; i++)
        {
            if(liczba%i==0)
            {
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
}

bool porownywanie_dzielnikow(vector<int>dzielniki_1, vector<int>dzielniki_2)
{
    for(int i=0; i<dzielniki_1.size(); i++)
    {
        for(int j=0; j<dzielniki_2.size(); j++)
        {
            if(dzielniki_1[i]==dzielniki_2[j]) return false;
        }
    }
    return true;
}

int main()
{
    fstream plik, odp;
    plik.open("liczby.txt");
    odp.open("odp.txt");

    vector<int>liczby;
    for(int i=0; i<200; i++)
    {
        int liczba;
        plik>>liczba;
        liczby.push_back(liczba);
    }

    int l_1=-1, l_2=-1, odp_1=0;

    for(int i=199; i>0; i--)
    {
        if(liczby[i]<1000)
        {
            odp_1++;
            if(l_1<0) l_1=liczby[i];
            else if(l_2<0) l_2=liczby[i];
        }
    }

    vector<int>dzielniki;
    cout<<odp_1<<" "<<l_1<<" "<<l_2<<endl;

    for(int i=0; i<200; i++)
    {
        zad_2(liczby[i],dzielniki);
    }

    int max_liczba_pierwsza=0;

    vector<vector<int>> pre_robione_dzielniki;
    for(int i=0; i<200; i++)
    {
        vector<int>dummy;
        znajdz_dzielniki(liczby[i],dummy);
        pre_robione_dzielniki.push_back(dummy);
    }

    for(int i=0; i<200; i++)
    {
        bool czy_wspolny_dzielnik=false;
        for(int j=0; j<200; j++)
        {
            if(j==i) break;
            czy_wspolny_dzielnik=!porownywanie_dzielnikow(pre_robione_dzielniki[i], pre_robione_dzielniki[j]);
            if(czy_wspolny_dzielnik==true)break;
        }
        if(czy_wspolny_dzielnik==false)
        {
            if(liczby[i]>max_liczba_pierwsza)max_liczba_pierwsza=liczby[i];
        }
    }

    cout<<endl<<endl<<max_liczba_pierwsza;

    plik.close();
    odp.close();
    return 0;
}
