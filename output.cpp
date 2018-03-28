#include<iostream>
using namespace std;

void end() {
    cout<<"0"<<endl;
}

void summon(int id, int x, int y) {
    cout<<"1 ";
    if(id>10)
        cout<<char(id);
    else
        cout<<id;
    cout<<" "<<x<<" "<<y<<endl;
    end();
}
