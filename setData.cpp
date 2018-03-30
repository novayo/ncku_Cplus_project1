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

bool findTower(int i, string str) {
    int pos=0;
    switch(i) {
    case 0:
        if(pos = str.find("TOWER 1") + 1) {
            return true;
        } else {
            return false;
        }
    case 1:
        if(pos = str.find("TOWER 2") + 1) {
            return true;
        } else {
            return false;
        }
    case 2:
        if(pos = str.find("TOWER 3") + 1) {
            return true;
        } else {
            return false;
        }
    case 3:
        if(pos = str.find("TOWER 4") + 1) {
            return true;
        } else {
            return false;
        }
    case 4:
        if(pos = str.find("TOWER 5") + 1) {
            return true;
        } else {
            return false;
        }
    case 5:
        if(pos = str.find("TOWER 6") + 1) {
            return true;
        } else {
            return false;
        }
    default:
        cerr<<"Fuction findTower in setData.cpp -----> i has wrong value\n";
        exit(1);
    }
}



/////	Reform    /////



void dataIn::beatJimmy(int n, int m) {
    int ene_pos = 0;	//0 => d   -1 => u
    for(int i=0; i<m; i++) {
        if(enemy[i][1] <= 10) {
            ene_pos=-1;
            break;
        }
    }
    int p9=0, p5=0, dnarmy=0, unarmy=0;
    for(int i=0; i<n; ++i) {
        if(army[i][0] == 9) {
            p9++;
        } else if(army[i][0] == 5) {
            p5++;
        }
        if(ene_pos == -1) {
            if(army[i][1]<=10) {
                unarmy++;
            }
        } else if(ene_pos == 0) {
            if(army[i][1]>10) {
                if(army[i][0] == 5 || army[i][0] == 9) {
                    if(army[i][2] > 10) {
                        dnarmy++;
                        continue;
                    }
                } else {
                    dnarmy++;
                }
            }
        }
    }
    if(p5 + p9 < 20) {
        for(int i=0; i<4; i++) {
            if(deck[i] == 9) {
                if(mana==10) {
                    if(ene_pos==0) {
                        summon(deck[i], 14, 11);
                        return;
                    } else if(ene_pos == -1) {
                        summon(deck[i], 7, 11);
                        return;
                    }
                }
                summon(deck[i], 18, 1);
                return;
            } else if(deck[i] == 5) {
                if(mana==10) {
                    if(ene_pos==0) {
                        summon(deck[i], 14, 11);
                        return;
                    } else if(ene_pos == -1) {
                        summon(deck[i], 7, 11);
                        return;
                    }
                }
                summon(deck[i], 17, 1);
                return;
            }
        }
    }
    if(ene_pos == 0) {
        int top=-10;
        int x=16;
        int y=15;
        if(mana == 10) {
            int tmp = rand()%4+1;
            x += tmp;
        } else if(dnarmy>=10) {
            x += top;
            int tmp = rand()%3;
            x -= tmp;
        }
        int have_4=0;
        for(int i=0; i<4; i++) {
            if(deck[i] == 6) {
                for(int j=0; j<n; ++j)
                    if(army[j][0] == 4) {
                        have_4++;
                        break;
                    }
                if(have_4>0) {
                    summon(deck[i], x, y);
                    return;
                }
            }
            if(deck[i] == 4) {
                summon(deck[i], x, y);
                return;
            }
        }
        for(int id = 0; id < 4; id++) {
            if(dnarmy != 0) {
                summon(deck[id], x, y);
                return;
            } else {
                if(deck[id] != 2 || deck[id] != 6 || deck[id] != 3) {
                    summon(deck[id], x, y);
                    return;
                }
            }
        }
    } else if(ene_pos == -1) {
        int top=10;
        int x=6;
        int y=15;
        if(mana == 10) {
            int tmp = rand()%4+1;
            x -= tmp;
        } else if(unarmy>=10) {
            x += top;
            int tmp = rand()%3;
            x += tmp;
        }
        int have_4=0;
        for(int i=0; i<4; i++) {
            if(deck[i] == 6) {
                for(int j=0; j<n; ++j)
                    if(army[j][0] == 4) {
                        have_4++;
                        break;
                    }
                if(have_4>0) {
                    summon(deck[i], x, y);
                    return;
                }
            }
            if(deck[i] == 4) {
                summon(deck[i], x, y);
                return;
            }
        }
        for(int id = 0; id < 4; id++) {
            if(unarmy != 0) {
                summon(deck[id], x, y);
                return;
            } else {
                if(deck[id] != 2 || deck[id] != 6 || deck[id] != 3) {
                    summon(deck[id], x, y);
                    return;
                }
            }
        }
    }
}

void dataIn::ranDom() {
    int x = rand()%20+1;
    int y = rand()%23+11;
    int cards = rand()%4;
    while(cards--) {
        int id = rand()%4;
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
        if(findTower(i, str)) {
            ss >> stmp >> stmp >> itmp;
            tower[i] = itmp;
        } else {
            tower[i] = 0;
        }
    }
    int i=0, j=0;
    while(true) {
        ss >> stmp;
        if(stmp == "END") {
            break;
        } else if(stmp == "FRIEND") {
            ss >> ctmp >> stmp >> itmp;
            army[i][0] = strtoi(ctmp);
            army[i][1] = itmp;
            ss >> ctmp >> itmp >> stmp;
            army[i][2] = itmp;
            ss >> itmp;
            army[i][3] = itmp;
            i++;
        } else if(stmp == "ENEMY") {
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
