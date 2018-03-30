#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>
#include "input.cpp"
#include "setData.h"
using namespace std;

int main(void) {
    srand((u)time(NULL));
    cout<<"5 9 4 7 1 2 3 6"<<endl;
    while(1) {
        int n;
        int m;
        string str;
        str = input(str);
        n = count_army(str);
        m = count_enemy(str);
        dataIn data;
        data.setStart(n,m);
        data.setValue(str);
        data.beatJimmy(n,m);
    }
    return 0;
}
