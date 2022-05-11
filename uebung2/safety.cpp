#include <bits/stdc++.h>

using namespace std;

bool isSafe(double perc, vector<int> points, int cont, int sum) {
    double other = 1-perc;
    double ownP = points[cont]+perc*sum;
    double count = 0;
    double add = 0;
    for(int i = 0; i<points.size(); ++i) {
        if(points[i]<ownP && i != cont) {
            add += points[i];
            count += 1;
        }
    }
    add += other * sum;
    return add/count < ownP;
}

int main() {
    int cases;
    cin >> cases;
    cout.precision(8);

    for(int i = 0; i<cases; ++i) {
        int cont;
        cin >> cont;
        int sum = 0;
        vector<int> points;
        for(int j = 0; j<cont; ++j) {
            int p;
            cin >> p;
            points.push_back(p);
            sum += p;
        }

        double mid;
        for(int j = 0; j<points.size(); ++j) {
            double lower = 0;
            double upper = 100;

            for(int m = 0; m<100; ++m) {
                mid = (lower+upper)/2;
                if(isSafe(mid, points, j, sum)) {
                    upper = mid;
                } else {
                    lower = mid;
                }
            }
            cout << mid*100 << " ";
        }
        cout << "\n";


    }
}
