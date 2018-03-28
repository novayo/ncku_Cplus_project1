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
    cout<<"5 9 4 7 1 3 C 6"<<endl;	//choosecard
    while(1) {
        int n;		//store the amount of FRIEND
        int m;		//store the amount of ENEMY
        string str;
        str = input(str);
        n = count_army(str);
        m = count_enemy(str);
//		if(n == 0){
//			cout<<str<<endl;
//			cout<<"----------------------\n";
//			cout<< "n = "<<n<<endl;
//			continue;
//		}
        dataIn data;
        data.setStart(n,m);
        data.setValue(str);
		data.beatJimmy(n,m);
//        data.muchMana(n);
    }
    return 0;
}
