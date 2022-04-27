#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Person {
    string name;
    double x;
    double y;
};

bool kleiner(const Person & p1, const Person & p2) {
    if(p1.y == 0 && p2.y == 0) {
        if(p1.x < p2.x) {
            return true;
        } else {
            return false;
        }
    }
    if(p1.y == 0 || p2.y == 0) {
        if(p1.y == 0) {
            if(p2.y > 0) {
                return false;
            } else {
                return true;
            }
        }
        if(p2.y == 0) {
            if(p1.y > 0) {
                return true;
            } else {
                return false;
            }
        }
    }
    if(p1.y > 0 && p2.y > 0) {
        if (atan(p1.x / p1.y) < atan(p2.x / p2.y)) {
            return true;
        } else if (atan(p1.x / p1.y) == atan(p2.x / p2.y)) {
            if (p1.x < p2.x) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    if(p1.y < 0 && p2.y < 0) {
        if (atan(p1.x / p1.y) < atan(p2.x / p2.y)) {
            return true;
        } else if (atan(p1.x / p1.y) == atan(p2.x / p2.y)) {
            if (p1.x < p2.x) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    if(p1.y< 0 || p2.y <0) {
        if(p1.y < 0) {
            return false;
        } else {
            return true;
        }
    }

    return false;
}

int main() {
    vector<Person> ps;
    string name;
    while(cin >> name) {
        int x;
        cin >> x;
        int y;
        cin >> y;
        Person p;
        p.name = name;
        p.x = x;
        p.y = y;
        ps.push_back(p);
    }
    sort(ps.begin(), ps.end(), kleiner);

    for(unsigned int i = 0; i<ps.size(); ++i) {
        cout << ps[i].name << endl;
    }
}
