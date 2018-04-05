#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<cstdlib>
#include "setData.h"
#include "output.cpp"
#include "useful.cpp"
#define u unsigned int
using namespace std;

void dataIn::battle(int n, int m, bool field) {
    /////	判斷5 跟 9 的數量	p5代表 5的數量 	p9代表 9的數量
    int p9=0, p5=0, dnarmy=0, unarmy=0;
    for(int i=0; i<n; ++i) {
        if(army[i][0] == 9) {
            p9++;
        } else if(army[i][0] == 5) {
            p5++;
        }
        ///// 判斷我上面的兵的數量 unarmy是代表 上面現在有幾隻 dnarmy是代表 下面現在有幾隻
        if(army[i][1]<=10) {
            unarmy++;
        } else {
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
    /////	------------出兵方法-------------	/////
    int x=16;
    int y=15;
    bool up_is_enemy = false;
    bool down_is_enemy = false;
    for(int i=0; i<m; ++i) {
        if(enemy[i][2] < 23 && enemy[i][1] < 10) {
            up_is_enemy = true;
            break;
        } else if(enemy[i][2] < 23 && enemy[i][1] >= 10) {
            down_is_enemy = true;
            break;
        }
    }

/////	9
    for(int i=0; i<4; ++i) {
        if(deck[i] == 9) {
            if(field) {
                x = 16;
                y = 23;
                if(down_is_enemy) {
                    int lefty = 50;
                    for(int j=0; j<m; ++j) {
                        if(enemy[j][2] < lefty) {
                            lefty = enemy[j][2];
                        }
                    }
                    y = lefty - 1;
                }
            } else {
                x = 6;
                y = 23;
                if(up_is_enemy) {
                    int lefty = 50;
                    for(int j=0; j<m; ++j) {
                        if(enemy[j][2] < lefty) {
                            lefty = enemy[j][2];
                        }
                    }
                    y = lefty - 1;
                }
            }
            summon(deck[i], x, y);
            return;
        }
    }
/////	5
    for(int i=0; i<4; ++i) {
        if(deck[i] == 5) { /////////////////////////////
            for(int j=0; j<n; ++j) {
                if(army[j][0] == 7 || army[j][0] == 4) {
                    if(army[j][2] > 23) {
                        if(field) {
                            x = rand()%4+4;
                        } else {
                            x = rand()%4+14;
                        }
                        summon(deck[i], x, 23);
                        return;
                    } else {
                        x = rand()%4+army[j][1];
                        y = army[j][2] - 1;
                        summon(deck[i], x, y);
                        return;
                    }
                }
            }
        }
    }

///// 	7 4
    for(int i=0; i<4; ++i) {
        if(deck[i] == 7 || deck[i] == 4) {
            if(field) {
                x = 6;
                y = 15;
                bool is_47 = false;
                for(int j=0; j<n; ++j) {
                    if(army[j][2] > 23) {
                        is_47 = true;
                        break;
                    }
                }
                if(is_47) {
                    y = 23;
                }
                if(up_is_enemy) {
                    int lefty = 50;
                    for(int j=0; j<m; ++j) {
                        if(enemy[j][2] < lefty) {
                            lefty = enemy[j][2];
                        }
                    }
                    y = lefty - 1;
                }
            } else {
                x = 16;
                y = 15;
                bool is_47 = false;
                for(int j=0; j<n; ++j) {
                    if(army[j][2] > 23) {
                        is_47 = true;
                        break;
                    }
                }
                if(is_47) {
                    y = 23;
                }
                if(down_is_enemy) {
                    int lefty = 50;
                    for(int j=0; j<m; ++j) {
                        if(enemy[j][2] < lefty) {
                            lefty = enemy[j][2];
                        }
                    }
                    y = lefty - 1;
                }
            }
            summon(deck[i], x, y);
            return;
        }
    }
///// 	6 c
    if(field) {
        if(tower[3] > 0) {
            for(int i=0; i<4; ++i) {
                if(deck[i] == 'C' || deck[i] == 6) {
                    for(int j=0; j<n; ++j) {
                        if(army[j][0] == 7 || army[j][0] == 4) {
                            if(army[j][2] > 23) {
                                x = rand()%4+4;
                                summon(deck[i], x, 23);
                                return;
                            } else {
                                if(up_is_enemy) {
                                    int r = rand()%2;
                                    if(r == 1) {
                                        x = 1;
                                    } else {
                                        x = 7;
                                    }
                                } else {
                                    x = rand()%4+4;
                                    y = army[j][2] - 1;
                                }
                            }
                            summon(deck[i], x, 5);
                            return;
                        }
                    }
                }
            }
        } else if(tower[3] == 0) {
            int r = rand()%4;
            x = rand()%4+4;
            summon(deck[r], x, 23);
            return;
        }
    } else {
        if(tower[5] > 0) {
            for(int i=0; i<4; ++i) {
                if(deck[i] == 'C' || deck[i] == 6) {
                    for(int j=0; j<n; ++j) {
                        if(army[j][0] == 7 || army[j][0] == 4) {
                            if(army[j][2] > 23) {
                                x = rand()%4+14;
                                summon(deck[i], x, 23);
                                return;
                            } else {
                                if(down_is_enemy) {
                                    int r = rand()%2;
                                    if(r == 1) {
                                        x = 14;
                                    } else {
                                        x = 20;
                                    }
                                } else {
                                    x = rand()%4+14;
                                    y = army[j][2] - 1;
                                }
                            }
                            summon(deck[i], x, 5);
                            return;
                        }
                    }
                }
            }
        } else if(tower[5] == 0) {
            int r = rand()%4;
            x = rand()%4+14;
            summon(deck[r], x, 23);
            return;
        }
    }
    /////	free
    while(true) {
        int r = rand()%4;
        if(tower[3] < 50 || tower [5] < 50) {
            for(int i=0; i<4; ++i) {
                if(deck[i] == 8) {
                    if(field) {
                        x = rand()%4+4;
                        y = 23;
                    } else {
                        x = rand()%4+14;
                        y = 23;
                    }
                }
                summon(deck[r], x, y);
                return;
            }
        }
        if(deck[r] == 8) {
            continue;
        } else {
            if(field) {
                int r = rand()%4;
                x = rand()%4+4;
                y = 23;
                if(up_is_enemy) {
                    int lefty = 50;
                    for(int j=0; j<m; ++j) {
                        if(enemy[j][2] < lefty) {
                            lefty = enemy[j][2];
                        }
                    }
                    y = lefty - 1;
                }
                summon(deck[r], x, y);
                return;
            } else {
                int r = rand()%4;
                x = rand()%4+14;
                y = 23;
                if(down_is_enemy) {
                    int lefty = 50;
                    for(int j=0; j<m; ++j) {
                        if(enemy[j][2] < lefty) {
                            lefty = enemy[j][2];
                        }
                    }
                    y = lefty - 1;
                }
                summon(deck[r], x, y);
                return;
            }
        }
    }
}


void dataIn::beatJimmy(int n, int m, bool field) {
    /////	判斷5 跟 9 的數量
    /////	p5代表 5的數量
    /////	p9代表 9的數量
    int p9=0, p5=0, dnarmy=0, unarmy=0;
    for(int i=0; i<n; ++i) {
        if(army[i][0] == 9) {
            p9++;
        } else if(army[i][0] == 5) {
            p5++;
        }
        /////	判斷我上面的兵的數量
        /////	unarmy是代表 上面現在有幾隻
        /////	dnarmy是代表 下面現在有幾隻
        if(army[i][1]<=10) {
            unarmy++;
        } else {
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
    /////	判斷塔後面 9 跟 5 的數量總和小於20個才放在塔後面，大於20個就放在戰場上
    if(p5 + p9 < 20) {
        for(int i=0; i<4; i++) {
            if(deck[i] == 9) {
                if(mana==10) {
                    if(field) {
                        summon(deck[i], 7, 11);
                        return;
                    } else {
                        summon(deck[i], 14, 11);
                        return;
                    }
                }
                summon(deck[i], 18, 1);
                return;
            } else if(deck[i] == 5) {
                if(mana==10) {
                    if(field) {
                        summon(deck[i], 7, 11);
                        return;
                    } else {
                        summon(deck[i], 14, 11);
                        return;
                    }
                }
                summon(deck[i], 17, 1);
                return;
            }
        }
    }
    /////	------------出兵方法-------------	/////
    int top=-10;
    int x=16;
    int y=15;
    /////	如果對方第一個放在上面的話，決定x,y
    if(field) {
        top = 10;
        x = 6;
        y = 15;
        if(mana == 10) {
            int tmp = rand()%4+1;
            x -= tmp;
        } else if(unarmy>=10) {
            x += top;
            int tmp = rand()%3;
            x += tmp;
        }
    }
    /////	如果對方第一個放在下面的話，決定x,y
    else {
        if(mana == 10) {
            int tmp = rand()%4+1;
            x += tmp;
        } else if(dnarmy>=10) {
            x += top;
            int tmp = rand()%3;
            x -= tmp;
        }
    }
    int is_4=0;
    for(int i=0; i<4; i++) {
        if(deck[i] == 6) {
            for(int j=0; j<n; ++j)
                if(army[j][0] == 4) {
                    is_4++;
                    break;
                }
            if(is_4>0) {
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

bool dataIn::checkEnemySummon(int m) {
    return m;
}

bool dataIn::checkField(bool tmp, int m) {
    if(tmp) {
        for(int i=0; i<m; i++) {
            if(enemy[i][1] <= 10) {
                return true;
            }
        }
    }
    return false;
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
