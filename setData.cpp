#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<cstdlib>
#include "setData.h"
#include "output.cpp"
#define u unsigned int
using namespace std;

int strtoi(char c) {
    stringstream str;
    str << c;
    char tmp;
    str >> tmp;
    if((int)tmp < 58)
        return (int)tmp - 48;
    return (int)tmp;
}

void dataIn::beatJimmy(int n, int m){
/////	n for FRIEND long		m for ENEMY long	/////

/////	summon 5 9	/////
    int p9=0, p5=0;
    for(int i=0; i<n; ++i) {
        if(army[i][0] == 9){
            p9++;
		}
        else if(army[i][0] == 5){
            p5++;
		}
    }
	if(p5 + p9 < 20){
    	for(int i=0; i<4; i++) {
       	 	if(deck[i] == 9 || deck[i] == 5)
				summon(deck[i], 19, 1);
		}
	}

/////	summon top	/////
	int top=-10;
	int x=15;
	int y=15;
	if(mana==10)
		x += top;

/////	summon	4 with 6/////
	int have_4=0;
	for(int i=0; i<4; i++) {
		if(deck[i] == 6){
    		for(int j=0; j<n; ++j) 
				if(army[j][0] == 4){
					have_4++;
					break;
				}
			if(have_4>0)
				summon(deck[i], x, y);
		}	
		if(deck[i] == 1 || deck[i] == 4)
			summon(deck[i], x, y);
	}



   	int id = rand()%4;	//4 cards in my hand 
    summon(deck[id], x+2, y);
}

void dataIn::ranDom() {
    int x = rand()%20+1;	//x range from 1~20
    int y = rand()%23+11;	//y range from 1~23  |  but test if put army to enemy's land
    int cards = rand()%4;	//play how many cards in a turn

    while(cards--) {
        int id = rand()%4;	//4 cards in my hand
        summon(deck[id], x, y);
    }
}

void dataIn::muchMana(int n) {
    int n9=0, n5=0;
    for(int i=0; i<n; i++) {
        if(army[i][0] == 9)
            n9++;
        else if(army[i][0] == 5)
            n5++;
    }
    for(int i=0; i<4; i++) {
        if(n9 <= 5 && n5 <= 5) {
            if(deck[i] == 9) {
                int x = rand()%2+10;
                int y = 1;
                summon(deck[i], x, y);
            } else if(deck[i] == 5) {
                int x = rand()%4+9;
                int y = 1;
                summon(deck[i], x, y);
            }
        }
    }
    int x;	//x range from 1~20
    if(tower[0] == 0 && tower[2] != 0)
        x = rand()%8+1;
    else if(tower[2] == 0 && tower[0] != 0)
        x = rand()%8+13;
    else
        x = rand()%20+1;
    int y = rand()%23+11;	//y range from 1~23  |  but test if put army to enemy's land
    int cards = rand()%4;	//play how many cards in a turn
    while(cards--) {
        int id = rand()%4;	//4 cards in my hand
        summon(deck[id], x, y);
    }
}

void dataIn::setStart(int n, int m) {
    ttime=0;
    mana=0;
    deck.assign(4,0);
    tower.assign(6,0);
    row.assign(4,0);
    army.assign(n, row);
	enemy.assign(m, row);
}

void dataIn::setValue(string str) {
    stringstream ss;
    ss << str;
    int itmp;
    char ctmp;
    string stmp;
    ss >> stmp >> itmp;
    ttime = itmp;
    ss >> stmp >> itmp >> stmp;
    mana = itmp;
    for(int i=0; i<4; i++) {
        ss >> ctmp;
        deck[i] = strtoi(ctmp);
    }
    for(int i=0; i<6; i++) {
        ss >> stmp >> stmp >> itmp;
        tower[i] = itmp;
    }
	int i=0, j=0;
	while(true){
        ss >> stmp;
		if(stmp == "END"){
			break;
		} else if(stmp == "FRIEND"){
			ss >> ctmp >> stmp >> itmp;
	        army[i][0] = strtoi(ctmp);
	        army[i][1] = itmp;
	        ss >> ctmp >> itmp >> stmp;
  	      	army[i][2] = itmp;
    	    ss >> itmp;
       	 	army[i][3] = itmp;
			i++;
		} else if(stmp == "ENEMY"){
			ss >> ctmp >> stmp >> itmp;
	        enemy[j][0] = strtoi(ctmp);
	        enemy[j][1] = itmp;
	        ss >> ctmp >> itmp >> stmp;
  	      	enemy[j][2] = itmp;
    	    ss >> itmp;
       	 	enemy[j][3] = itmp;
			j++;
		}
    }
}

int dataIn::retime() {
    return ttime;
}

int dataIn::remana() {
    return mana;
}

int dataIn::redeck(int i) {
    return deck[i];
}

int dataIn::retower(int i) {
    return tower[i];
}

int dataIn::rearmy(int i, int j) {
    return army[i][j];
}
