 #include <iostream>
 #include <fstream>
 #include <vector>
 #include <string>
 #include <algorithm>

 using namespace std;

 void zad1(const vector<int>& vec){
    int foo=2;
    int n=0;
    for(int i=vec.size()-1;i>=0;i--)
    {
        if(vec[i]<1000){
            if(foo){
                cout<<vec[i]<<endl;
                foo--;
            }
            n++;
        }
    }
    cout<<n<<endl;
}

vector<int> getDivisors(int n){
    vector<int>ret;
    for(int i=1;i*i<=n;i++){
        if(i*i==n){
            ret.push_back(i);
            sort(ret.begin(),ret.end());
            return ret;
        }
        if(n%i==0){
            ret.push_back(i);
            ret.push_back(n/i);
        }
    }
    sort(ret.begin(),ret.end());
    return ret;
}

void zad2(const vector<int>& vec){
    for(auto i:vec){
        vector<int>d=getDivisors(i);
        if(d.size()==18){
            cout<<i<<" ";

            for(auto j:d)cout<<j<<" ";
            cout<<endl;
        }
    }
}

bool areRelativelyPrime(const vector<int>& d1, const vector<int>& d2){
    for(auto i:d1){
        for(auto j:d2)if(i==j)return false;
    }
    return true;
}

void zad3(const vector<int>& vec){
    int n=0;
    vector<vector<int>>d;
    for(auto i:vec)d.push_back(getDivisors(i));
    for(auto& i:d)i.erase(i.begin(),i.begin()+1);

    bool didBreak=false;

    for(int i=0;i<vec.size();i++){
        didBreak=false;
        for(int j=0;j<vec.size();j++){
            if(i==j)continue;
            if(!areRelativelyPrime(d[i], d[j])){
                didBreak=true;
                //cout<<"!!!"<<vec[i]<<" i "<<vec[j]<<" nie sa wspolnie pierwsze\n";
                break;
            }
            //cout<<vec[i]<<" i "<<vec[j]<<"sa wspolnie pierwsze"<<endl;
        }
        if(vec[i]>n && !didBreak){
            n=vec[i];
            //cout<<vec[i]<<" jest pierwsze wzgledem kazdej liczby"<<endl;
        }
        didBreak=true;
    }

    cout<<n<<endl;
    // for(auto i:d){
    //     for(auto j:i)cout<<j<<" ";
    //     cout<<endl;
    // }
}

int main(){
    fstream file;
    file.open("liczby.txt");
    string temp;
    vector<int>vec;
    while(getline(file, temp)){
        vec.push_back(stoi(temp));
    }

    zad1(vec);//git
    zad2(vec);//git
    zad3(vec);
}