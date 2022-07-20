#include <bits/stdc++.h>

using namespace std;

typedef pair<int64_t, int64_t> pi;

int64_t no(pi f, pi s) {
    return ((f.first - s.first) * (f.first - s.first) + (f.second - s.second) * (f.second - s.second));
}

int main() {
    vector<int64_t> first;
    vector<int64_t> second;
    int64_t x, y, r;
    while (cin >> x >> y >> r) {
        first.push_back(x);
        first.push_back(y);
        first.push_back(r);
        cin >> x >> y >> r;
        second.push_back(x);
        second.push_back(y);
        second.push_back(r);
        if (first[0] == second[0] && first[1] == second[1]) {
            if (first[2] == second[2]) {
                cout << "THE CIRCLES ARE THE SAME" << endl;
            } else {
                cout << "NO INTERSECTION" << endl;
            }
        } else {
            int64_t rSum = (first[2] + second[2]) * (first[2] + second[2]);
            pi f = make_pair(first[0], first[1]);
            pi s = make_pair(second[0], second[1]);
            int64_t dist = no(f, s);
            int64_t diff = dist - rSum;
            //cout << first[0] << ", " << second[0]<< ", " << no(f, s) << endl;

            if (diff > 0) {
                cout << "NO INTERSECTION" << endl;
            } else if (diff < 0) {
                if(second[2]*second[2] > dist || first[2]*first[2] > dist) {
                    if((first[2]-second[2])*(first[2]-second[2])>dist) {
                        cout << "NO INTERSECTION" << endl;
                    } else if((first[2]-second[2])*(first[2]-second[2])<dist) {
                        cout << "TWO INTERSECTIONS" << endl;
                    } else {
                        cout << "ONE INTERSECTION" << endl;
                    }
                } else {
                    cout << "TWO INTERSECTIONS" << endl;
                }

            } else {
                cout << "ONE INTERSECTION" << endl;
            }

        }
        first.clear();
        second.clear();
    }
}
