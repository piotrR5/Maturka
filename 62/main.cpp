 
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int _10to8(int n){
    string foo;
    while(n){
        foo+=(n%8+'0');

        n/=8;
    }
    return stoi(string(foo.rbegin(), foo.rend()));
}

int main(){

    fstream file;
    vector<int>l1,l2;
    string temp;

    file.open("liczby1.txt");
    while(getline(file,temp)){
        l1.push_back(stoi(temp,nullptr,8));
    }
    file.close();
    file.open("liczby2.txt");
    while(getline(file,temp)){
        l2.push_back(stoi(temp));
    }
    file.close();

//zad1
    int max=0,min=1000000;
    for(auto i:l1){
        if(i>max)max=i;
        if(i<min)min=i;
    }
    cout<<"zad1: "<<_10to8(min)<<" "<<_10to8(max)<<endl;

//zad2
    int firstElement;
    int maxLen=0;
    int len=1;
    for(int i=1;i<1000;i++){
        if(l2[i]>=l2[i-1])len++;
        else{
            if(len>=maxLen){
                maxLen=len;
                //cout<<"["<<i-len<<endl;
                firstElement=l2[i-len]; 
            }
            len=1;
            continue;
        }
    }
    cout<<"zad2: "<<firstElement<<" "<<maxLen<<endl;

//zad3
    int a=0,b=0;
    for(int i=0;i<1000;i++){
        //cout<<"["<<l1[i]<<" "<<l2[i]<<"]";
        if(l1[i]==l2[i]){
            //cout<<" a ";
            a++;
        }
        if(l1[i]>l2[i]){
            //cout<<" b ";
            b++;
        }
        //cout<<"\n";
    }

    cout<<"zad3: "<<a<<" "<<b<<endl;

//zad4
    int n6=0, n6_8=0;
    for(auto i:l2){
        string foo=to_string(i);
        string foo8=to_string(_10to8(i));
        for(auto j:foo)if(j=='6')n6++;
        for(auto j:foo8)if(j=='6')n6_8++;
    }
    cout<<"zad4: "<<n6<<" "<<n6_8<<endl;


    return 0;
}