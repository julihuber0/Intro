#include <bits/stdc++.h>

using namespace std;

int64_t mod(int64_t x, int64_t m) {
    return ((x % m) + m) % m;
}

int64_t euclid(int64_t a, int64_t b) {
    if (a < b) {
        return euclid(b, a);
    }
    if (b == 0) {
        return a;
    }
    return euclid(b, mod(a, b));
}

int main() {
    int cases;
    cin >> cases;
    for (int t = 0; t < cases; ++t) {
        int b;
        cin >> b;
        vector<int64_t> ls;
        vector<int64_t> rs;
        int64_t max = 0;
        for(int j = 0; j<b; ++j) {
            int64_t l = 0;
            for (int i = 0; i < 9; ++i) {
                int64_t s;
                cin >> s;
                l += s;
            }
            ls.push_back(l);
            int64_t r;
            cin >> r;
            if(r>max) {
                max = r;
            }
            rs.push_back(r);
        }
        int64_t gcd = ls[0]-rs[0];
        bool c = true;
        for(int i = 1; i<b; ++i) {
            if(ls[i]-rs[i]<0) {
                c = false;
                break;
            }
            gcd = euclid(gcd, ls[i]-rs[i]);
        }
        if(gcd > 1 && gcd > max && c) {
            cout << gcd << endl;
        } else {
            cout << "impossible" << endl;
        }

    }
}
