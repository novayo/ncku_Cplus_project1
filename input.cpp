#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include "setData.h"
using namespace std;

string input(string str) {
    while(true) {
        string tmp;
        getline(cin, tmp);
        str +=  tmp;
        if(tmp == "END")
            break;
    }
    return str;
}

int count_army(string str) {
    int pos=0, ans=0, end=0;
    while(1) {
        pos = str.find("FRIEND", pos);
        if(end == 2){
            return ans;
		}
        if(pos == -1) {
            end++;
            continue;
        }
        ans++;
        pos++;
    }
}

int count_enemy(string str) {
    int pos=0, ans=0, end=0;
    while(1) {
        pos = str.find("ENEMY", pos);
        if(end == 2){
            return ans;
		}
        if(pos == -1) {
            end++;
            continue;
        }
        ans++;
        pos++;
    }
}
