#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

bool s_equal(const string& s1, const string& s2){
    if(s1.size()!=s2.size())return false;

    for(int i=0;i<s1.size();i++){
        if(s1[i]!=s2[i])return false;
    }
    return true;
}

bool areThereTwoOnesNextToEachOther(string n){
    for(int i=0;i<n.size()-1;i++){
        if(n[i]=='1' && n[i+1]=='1')return true;
    }
    return false;
}

bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}

bool isHalfPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            if(isPrime(i)){
                if(isPrime(n/i))return true;
            }
        }
    }
    return false;
}

int main(){
    fstream file;
    file.open("ciagi.txt");

    string temp;
    vector<string>vec;

    while(getline(file, temp)){
        temp.erase(temp.size()-1);
        vec.push_back(temp);
    }

//zad1
    for(const auto& i:vec){
        //cout<<i<<endl;
        if(i.size()%2==0){
            string s1(i.begin(), i.begin()+i.size()/2),s2(i.begin()+i.size()/2, i.end());
            //cout<<"["<<s1<<" "<<s2<<"]"<<endl;
            if(s_equal(s1,s2))cout<<i<<endl;
        }
    }

//zad2
    int n2=0;
    for(const auto& i:vec){
        if(!areThereTwoOnesNextToEachOther(i))n2++;
    }
    cout<<n2<<endl;


//zad3
    int max3=0,min3=INT32_MAX;
    int n3=0;
    for(const auto& i:vec){
        int n=stoi(i, 0, 2);    
        if(isHalfPrime(n)){
            n3++;
            if(n>max3)max3=n;
            if(n<min3)min3=n;
        }
    }

    cout<<"zad3: "<<n3<<" "<<max3<<" "<<min3<<endl;



    return 0;
}
