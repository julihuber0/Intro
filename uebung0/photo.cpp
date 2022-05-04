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

double angle(double x, double y) {
    if(y>0) {
        return atan(x/y);
    }
    if(y == 0) {
        return 90;
    }
    return 180 + atan(x/y);
}

bool kleiner(const Person & p1, const Person & p2) {
    double a1 = angle(p1.x, p1.y);
    double a2 = angle(p2.x, p2.y);
    if(a1 < a2) {
        return true;
    } else if (a1 == a2) {
        if(p1.x<p2.x) {
            return true;
        } else {
            return true;
        }
    } else {
        return false;
    }
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
        cout << ps[i].name << "\n";
    }
}
