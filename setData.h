#ifndef setdata
#define setdata
#include<iostream>
#include<vector>
#define u unsigned int
using namespace std;

class dataIn {
  public:
    void setStart(int n, int m);
    void setValue(string str);
    void ranDom();
    void beatJimmy(int n, int m);
  private:
    u ttime;
    u mana;
    vector<u> deck;
    vector<u> tower;
    vector<u> row;
    vector< vector<u> > army;
    vector< vector<u> > enemy;
};
#endif
