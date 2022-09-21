#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string na_osemkowy(string liczba)
{
    int liczba_int=stoi(liczba);
    string ret;

    while(liczba_int>1)
    {
        ret+=to_string(liczba_int%8);
        liczba_int/=8;
    }
    //cout<<ret<<endl;
    return ret;
}

int main()
{
    fstream plik1, plik2;
    plik1.open("liczby1.txt");
    plik2.open("liczby2.txt");

    vector<string>liczby_osemkowe;
    vector<int>liczby_dziesietne;
    string max_osemkowa, min_osemkowa;
    int max_osemkowa_int=0, min_osemkowa_int=999999;

    for(int i=0; i<1000; i++)
    {
        string liczba;
        int liczba_int;
        plik1>>liczba;
        liczba_int=stoi(liczba,nullptr,8);

        if(liczba_int>max_osemkowa_int)
        {
            max_osemkowa_int=liczba_int;
            max_osemkowa=liczba;
        }

        if(liczba_int<min_osemkowa_int)
        {
            min_osemkowa_int=liczba_int;
            min_osemkowa=liczba;
        }

        liczby_osemkowe.push_back(liczba);
    }

    for(int i=0; i<1000; i++)
    {
        int liczba;
        plik2>>liczba;
        liczby_dziesietne.push_back(liczba);
    }

    cout<<min_osemkowa<<" "<<max_osemkowa<<endl;

    int ciag_start=0, ciag_len=1;
    int max_ciag_start=0, max_ciag_len=0;

    for(int i=1; i<1000; i++)
    {
        ciag_len++;
        if(liczby_dziesietne[i]<liczby_dziesietne[i-1])
        {
            ciag_start=i;
            ciag_len=1;
        }
        if(ciag_len>max_ciag_len)
        {
            max_ciag_len=ciag_len;
            max_ciag_start=ciag_start;
        }
    }

    cout<<liczby_dziesietne[max_ciag_start]<<" "<<max_ciag_len<<endl;

    int taka_sama_wartosc=0, wieksza_wartosc=0;

    for(int i=0; i<1000; i++)
    {
        int dummy;
        dummy=stoi(liczby_osemkowe[i],nullptr,8);
        if(liczby_dziesietne[i]==dummy) taka_sama_wartosc++;
        if(liczby_dziesietne[i]<dummy) wieksza_wartosc++;
    }

    cout<<taka_sama_wartosc<<" "<<wieksza_wartosc<<endl;

    vector<string>liczby_dziesietne_string;
    for(int i=0; i<1000; i++)
    {
        liczby_dziesietne_string.push_back(to_string(liczby_dziesietne[i]));
    }

    int liczba_szostek=0, liczba_szostek_gdyby_8=0;

    for(int i=0; i<1000; i++)
    {
        for(int j=0; j<liczby_dziesietne_string[i].size(); j++)
        {
            if(liczby_dziesietne_string[i][j]=='6') liczba_szostek++;

        }

        string liczba_w_8=na_osemkowy(liczby_dziesietne_string[i]);

        for(int j=0; j<liczba_w_8.size(); j++)
        {
            if(liczba_w_8[j]=='6') liczba_szostek_gdyby_8++;
        }

    }

    cout<<liczba_szostek<<" "<<liczba_szostek_gdyby_8<<endl;

    cout<<endl<<endl<<"chyba blad w odp od CKE"<<endl;

    plik1.close();
    plik2.close();
    return 0;
}
