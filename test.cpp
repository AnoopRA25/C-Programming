#include<iostream>
using namespace std;

int min(){

    int a,b;
    cout<<"a:";
    cin>>a;
    cout<<"b:";
    cin>>b;

    int c;
    c=b;
    b=a;
    a-c;

    cout<<"a:"<<a<<endl;
    cout<<"b:"<<a<<endl;

    return 0;
}