#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>
#include "input.cpp"
#include "setData.h"
using namespace std;
//5 9 4 7 1 2 3 6
// 7 8 9 5 6 4 2 C

int main(void) {
    srand((u)time(NULL));
    cout<<"9 5 7 4 8 6 2 C"<<endl;
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
        data.battle(n,m,field);
    }
    return 0;
}
