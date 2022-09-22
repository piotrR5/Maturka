 #include <iostream>
 #include <fstream>
 #include <algorithm>
 #include <vector>
 #include <string>
 #include <math.h>

 using namespace std;


string toBin(int n){
    //cout<<"["<<n<<"]:";
    string r="";
    bool sign=n<0;
    if(sign)n=-n;
    while(n!=0){
        r+=(n%2+'0');
        n/=2;
    }
    if(sign)r+='-';
    //cout<<string(r.rbegin(), r.rend())<<endl;
    return string(r.rbegin(), r.rend());
}

int jump(int i, int j, int t1, int t2){
    int r=(t1-t2)*(t1-t2);

    return ceil((double)r/sqrt((i-j)*(i-j)));
}

 int main(){
    vector<int>d1,d2,d3,t1,t2,t3;
    vector<string>sd1,sd2,sd3,st1,st2,st3;

    fstream file;
    string temp1,temp2;

    file.open("dane_systemy1.txt");
    while(file>>temp1>>temp2){
        st1.push_back(temp1);
        sd1.push_back(temp2);
        t1.push_back(stoi(temp1,nullptr,2));
        d1.push_back(stoi(temp2,nullptr,2));
    }
    file.close();

    file.open("dane_systemy2.txt");
    while(file>>temp1>>temp2){
        st2.push_back(temp1);
        sd2.push_back(temp2);
        t2.push_back(stoi(temp1,nullptr,4));
        d2.push_back(stoi(temp2,nullptr,4));
    }
    file.close();

    file.open("dane_systemy3.txt");
    while(file>>temp1>>temp2){
        st3.push_back(temp1);
        sd3.push_back(temp2);
        t3.push_back(stoi(temp1,nullptr,8));
        d3.push_back(stoi(temp2,nullptr,8));
    }
    file.close();

    // for(int i=0;i<1095;i++){
    //     cout<<"["<<t1[i]<<"] "<<d1[i]<<endl;
    //     cout<<"\t["<<st1[i]<<"] "<<sd1[i]<<endl;
    // }

    // for(int i=0;i<1095;i++){
    //     cout<<"["<<t2[i]<<"] "<<d2[i]<<endl;
    //     cout<<"\t["<<st2[i]<<"] "<<sd2[i]<<endl;
    // }

    // for(int i=0;i<1095;i++){
    //     cout<<"["<<t3[i]<<"] "<<d3[i]<<endl;
    //     cout<<"\t["<<st3[i]<<"] "<<sd3[i]<<endl;
    // }
    
//zad1
    int min1=0,min2=0,min3=0;
    for(int i=0;i<1095;i++){
        if(d1[i]<min1){
            min1=d1[i];
        }
    }

    for(int i=0;i<1095;i++){
        if(d2[i]<min2){
            min2=d2[i];
        }
    }

    for(int i=0;i<1095;i++){
        if(d3[i]<min3){
            min3=d3[i];
        }
    }

    cout<<"zad1:"<<endl;
    cout<<"dane1: "<<toBin(min1)<<endl;
    cout<<"dane2: "<<toBin(min2)<<endl;
    cout<<"dane3: "<<toBin(min3)<<endl;

//zad2
    int n2=0;
    for(int i=0;i<1095;i++){
        if((t1[i]-12)%24!=0 && (t2[i]-12)%24!=0 && (t3[i]-12)%24!=0)n2++;
    }
    cout<<"zad2: "<<n2<<endl;

//zad3
    int n3=0;
    int max1=0,max2=0,max3=0;
    for(int i=0;i<1095;i++){
        if(d1[i]>max1 || d2[i]>max2 || d3[i]>max3){
            n3++;
            if(d1[i]>max1)max1=d1[i];
            if(d2[i]>max2)max2=d2[i];
            if(d3[i]>max3)max3=d3[i];
        }
    }
    cout<<"zad3: "<<n3<<endl;

//zad4
    int max4=0;
    for(int i=0;i<1095;i++){
        for(int j=0;j<1095;j++){
            int foo=jump(i,j,d1[i], d1[j]);
            if(foo>max4)max4=foo;
        }
    }
    cout<<"zad4: "<<max4<<endl;



    return 0;
 }
