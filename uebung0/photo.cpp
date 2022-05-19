#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Person {
    string name;
    int x;
    int y;
};

bool kleiner(const Person & p1, const Person & p2) {
    int f = p1.y*p2.x;
    int s = p2.y*p1.x;
    if(f>s) {
        return true;
    } else if(f<s) {
        return false;
    } else {
        if(p1.x<p2.x) {
            return true;
        } else {
            return false;
        }
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
