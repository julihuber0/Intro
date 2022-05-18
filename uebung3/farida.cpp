#include <bits/stdc++.h>

using namespace std;

vector<int64_t> values;
vector<int64_t> coins;

int64_t calc() {

    if(coins.size() == 0){return 0;}
    if(coins.size() == 1) {return coins[0];}

    values[0] = 0;
    values[1] = coins[0];

    for(int64_t i = 2; i<values.size(); ++i) {
        values[i] = max(values[i-1], values[i-2]+coins[i-1]);
    }

    return values[coins.size()];
}

int main() {
    values.reserve(10001);
    coins.reserve(10001);

    int64_t cases;
    cin >> cases;

    for(int64_t i = 0; i<cases; ++i) {
        values.clear();
        coins.clear();
        int64_t monsters;
        cin >> monsters;
        for(int64_t j = 0; j<monsters; ++j) {
            int c;
            cin >> c;
            coins.push_back(c);
        }

        values.resize(monsters+1);

        cout << calc() << "\n";
    }
}
