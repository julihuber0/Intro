#include <bits/stdc++.h>

using namespace std;

int main() {
    int people;
    int budget;
    int hotels;
    int weeks;
    cin >> people;
    cin >> budget;
    cin >> hotels;
    cin >> weeks;
    int min = budget +1;

    for(int i = 0; i<hotels; ++i) {
        int price;
        cin >> price;
        for(int j = 0; j<weeks; ++j) {
            int beds;
            cin >> beds;
            if(beds>=people && people*price<=budget && min > people*price) {
                min = people * price;
            }
        }
    }
    if(min != budget + 1) {
        cout << min << "\n";
    } else {
        cout << "stay home" << "\n";
    }
}
