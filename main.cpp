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
    bool tmp=true;
    bool field=false;
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
        if(data.checkEnemySummon(m)) {
            if(data.checkField(tmp, m)) {
                field = true;
                tmp = false;
            } else {
                tmp = false;
            }
        }
        data.beatJimmy(n,m,field);
    }
    return 0;
}
