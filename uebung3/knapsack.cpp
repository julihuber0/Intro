#include <bits/stdc++.h>

using namespace std;

int main(){
    int packs, cap;
    cin >> packs >> cap;

    vector<int> packets(3);
    vector<int> knapsack(3);
    packets[0] = 0;
    packets[1] = 0;
    packets[2] = 0;
    knapsack[0] = 0;
    knapsack[1] = 0;
    knapsack[2] = 0;
    for(int i = 0; i<packs; ++i) {
        int p;
        cin >> p;
        switch (p) {
            case 1:
                packets[0] += 1;
                break;
            case 2:
                packets[1] += 1;
                break;
            case 3:
                packets[2] += 1;
                break;
            default:
                break;
        }
    }

    int fill = 0;
        while(packets[2]>0 && fill+3<=cap) {
            knapsack[2] += 1;
            fill += 3;
            packets[2] -= 1;
        }
        while(packets[1]>0 && fill+2<=cap) {
            knapsack[1] += 1;
            fill += 2;
            packets[1] -= 1;
        }
        while(packets[0]>0 && fill+1<=cap) {
            knapsack[0] += 1;
            fill += 1;
            packets[0] -= 1;
        }

        if(fill!=cap) {
            if(packets[1]>1 && knapsack[2]>0) {
                fill -= 3;
                knapsack[2] -= 1;
                fill += 4;
                knapsack[1] +=2;
            }
        }
        cout << fill << "\n";
}
