#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;



int main(){

    vector<int>pow3;

    for(int i=1;i*i*i<=1000000;i++){
        pow3.push_back(i*i*i);
        pow3.push_back(-i*i*i);
    }

    fstream file;
    file.open("ciagi.txt");

    int abc=100;

    int rMax=0;

    while(abc--){
        int n;
        vector<int>vec;

        file>>n;
        while(n--){
            int foo;
            file>>foo;
            vec.push_back(foo);
        }

        bool isgood=true;

        for(int i=0;i<vec.size()-2;i++){
            if(vec[i+1]-vec[i] != vec[i+2]-vec[i+1]){
                isgood=false;
                break;
            }
        }

        if(isgood){
            if(vec[1]-vec[0]>rMax)rMax=vec[1]-vec[0];
        }

        int max3=0;
        for(auto i:vec){
            for(auto j:pow3){
                if(i==j){
                    if(i>max3)max3=i;
                }
            }
        }
        if(max3)cout<<"zad2: "<<max3<<endl;


        // for(auto i:vec)cout<<i<<" ";
        // cout<<endl;
        
    }

    cout<<rMax<<endl;

    file.close();

    file.open("bledne.txt");

    abc=20;
    while(abc--){
        int n;
        file>>n;
        vector<int>vec;
        while(n--){
            int foo;
            file>>foo;
            vec.push_back(foo);
        }

        for(int i=0;i<vec.size()-3;i++){
            if(vec[i+1]-vec[i] != vec[i+2]-vec[i+1]){
                // x o x x
                if((vec[i+2]-vec[i])/2 == vec[i+3]-vec[i+2]){
                    cout<<"zad3: "<<vec[i+1]<<endl;
                    break;
                }

                // x x o x
                if((vec[i+3]-vec[i+1])/2 == vec[i+1]-vec[i]){
                    cout<<"zad3: "<<vec[i+2]<<endl;
                    break;
                }


                // o x x x
                if(vec[i+3]-vec[i+2]==vec[i+2]-vec[i+1]){
                    cout<<"zad3: "<<vec[i]<<endl;
                    break;
                }


                //x x x o
                if(vec[i+2]-vec[i+1]==vec[i+1]-vec[i]){
                    cout<<"zad3: "<<vec[i+3]<<endl;
                    break;
                }
            }
        }
    }

    

}