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
