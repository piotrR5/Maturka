#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <unordered_set>

using namespace std;

int odwroc_liczbe(int liczba)
{
    int copy_=liczba, length=0;
    while(copy_>0)
    {
        copy_/=10;
        length++;
    }
    char liczba_s[length];
    itoa(liczba,liczba_s,10);

    int ret=0;
    for(int i=length-1; i>=0; i--)
    {
        ret*=10;
        ret+=(int)liczba_s[i]-48;
    }

    return ret;
}

bool czy_palindrom(int liczba)
{
    int copy_=liczba, length=0;
    while(copy_>0)
    {
        copy_/=10;
        length++;
    }
    char liczba_s[length];
    itoa(liczba,liczba_s,10);

        for(int i=0; i<length/2; i++)
        {
            if(liczba_s[i]!=liczba_s[length-1-i]) return false;
        }
        return true;

    return false;
}

bool zad1(uint64_t n){
    unordered_set<int>d;
    while(n!=1){
        for(uint64_t i=2;i<=n;i++){
            if(n%i==0){
                if(i!=2)d.emplace(i);
                n/=i;
                break;
            }
        }
    }
    if(d.size()==3){
        return true;
    }
    return false;
}

int iloczyn_cyfr(int liczba)
{
    int copy_=liczba, length=0;
    while(copy_>0)
    {
        copy_/=10;
        length++;
    }
    char liczba_s[length];
    itoa(liczba,liczba_s,10);

    int wymnozona_liczba=1;

    for(int i=0; i<length; i++)
    {
        wymnozona_liczba*=(int)liczba_s[i]-48;
    }
    return wymnozona_liczba;
}

int main()
{
    fstream plik, odp;

    plik.open("liczby.txt");
    odp.open("wyniki_liczby.txt");

    vector<int>liczby;

    int odp_1=0;

    for(int i=0; i<1000; i++)
    {
        int liczba;
        plik>>liczba;
        liczby.push_back(liczba);

        if(zad1(liczba)==true && liczba%2==1) odp_1++;
    }

    odp<<odp_1<<endl;

    int odp_2=0;

    for(int i=0; i<1000; i++)
    {
        if(czy_palindrom(liczby[i]+odwroc_liczbe(liczby[i]))==true) odp_2++;
    }

    odp<<odp_2<<endl;

    int odp_3[8];
    for(int i=0; i<8; i++)
    {
        odp_3[i]=0;
    }

    int max_moc_1=0, min_moc_1=999999999;

    for(int i=0; i<1000; i++)
    {
        int moc=0, liczba=liczby[i];
        while(liczba>9)
        {
            liczba=iloczyn_cyfr(liczba);
            moc++;
        }
        if(moc<9)odp_3[moc-1]++;
        if(moc==1)
        {
            if(liczby[i]>max_moc_1) max_moc_1=liczby[i];
            if(liczby[i]<min_moc_1) min_moc_1=liczby[i];
        }
    }

    for(int i=0; i<8; i++)
    {
        odp<<odp_3[i]<<" ";
    }
    odp<<endl<<min_moc_1<<" "<<max_moc_1<<endl;

    plik.close();
    odp.close();
    return 0;
}
