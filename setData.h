#ifndef setdata
#define setdata
#include<iostream>
#include<vector>
#define u unsigned int
using namespace std;

class dataIn {
  public:
    /////	data deal	/////
    void setStart(int n, int m);
    void setValue(string str);
    int retime();
    int remana();
    int redeck(int n);
    int retower(int n);
    int rearmy(int n, int m);
    /////	strategy	/////
    void ranDom();
    void muchMana(int n);
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
