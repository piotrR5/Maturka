#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_set>

using namespace std;



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
        //for(auto i:d)cout<<i<<" ";
        //cout<<endl;
        return true;
    }
    return false;
}

bool isPalindrome(string n){
    for(int i=0;i<n.size()/2;i++){
        if(n[i]!=n[n.size()-1-i])return false;
    }
    return true;
}


int main(){


    fstream file;
    file.open("liczby.txt");
    vector<string>data;
    string temp;
    while(getline(file, temp))data.push_back(temp);


//zad1


    int _1=0;
    for(auto& i:data){
        uint64_t foo=stoi(i);
        if(foo%2==0)continue;
        if(zad1(foo))_1++;
    }
    cout<<"zad1: "<<_1<<endl;


//zad2
    int _2=0;
    for(const auto& i:data){
        string rev=string(i.rbegin(), i.rend());
        uint64_t n=stoi(i)+stoi(rev);
        if(isPalindrome(to_string(n))){
            //cout<<"["<<n<<"] TAK\n";
            _2++;
        }
        //else cout<<"["<<n<<"] NIE\n";
    }
    cout<<"zad2: "<<_2<<endl;



//zad3
    uint64_t _3[8];
    for(int i=0;i<8;i++)_3[i]=0;
    uint64_t max1=0, min1=1000000000;

    for(auto& i:data){
        //cout<<i<<endl;
        string temp=i;
        temp.erase(temp.size()-1);
        int k=0;
        int foo=1;
        while(temp.size()>1){
            k++;
            foo=1;
            for(char c:temp){
                //cout<<c<<" ";
                foo*=(c-'0');
            }
            //cout<<endl;
            temp=to_string(foo);
            foo=1;
        }
        //cout<<"["<<k<<"]\n";

        if(k<9)_3[k-1]++;
        if(k==1){
            if(stoi(i)>max1)max1=stoi(i);
            if(stoi(i)<min1)min1=stoi(i);
        }
    }

    cout<<"zad3: ";
    for(int i=0;i<8;i++)cout<<_3[i]<<" ";
    cout<<"max: "<<max1<<" min: "<<min1<<endl;

    file.close();

    return 0;
}
