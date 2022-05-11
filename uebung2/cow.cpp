#include <bits/stdc++.h>

using namespace std;


int main() {
    int cases;
    cin >> cases;
    for(int i = 0; i<cases; ++i) {
        int cows;
        cin >> cows;
        int lanes;
        cin >> lanes;
        int sd;
        cin >> sd;
        int limit;
        cin >> limit;

        vector<int> speed;
        vector<int> lane(lanes);
        for(int m = 0; m< lanes; ++m) {
            lane[m] = 0;
        }

        vector<bool> onRoad(cows);
        for(int j = 0; j < cows; ++j) {
            int s;
            cin >> s;
            speed.push_back(s);
            onRoad[j] = false;
        }
        sort(speed.begin(), speed.end());
        int maxCows = 0;

        int index = 0;
        while (speed[index]< limit) {
            index += 1;
        }

        for(int m = index; m<cows; ++m) {
            for(int l = 0; l<lanes; ++l) {
                if(speed[m]-lane[l]*sd >= limit) {
                    //cout << speed[m] << "\n";
                    lane[l] += 1;
                    maxCows += 1;
                    onRoad[m] = true;
                    break;
                }
            }
        }

        cout << maxCows << "\n";




    }
}
