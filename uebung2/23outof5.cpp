#include <bits/stdc++.h>

using namespace std;

bool calculateValues(vector<int> a, int curRes, char op, int index) {

    if(index == 4) {
        if(op == '+') {
            return curRes + a[4] == 23;
        }
        if(op == '*') {
            return curRes * a[4] == 23;
        }
        return curRes - a[4] == 23;
    } else {
        if(op == '+') {
            curRes = curRes + a[index];
        }
        if(op == '*') {
            curRes = curRes * a[index];
        }
        if(op == '-') {
            curRes = curRes - a[index];
        }
        return calculateValues(a, curRes, '+', index + 1) || calculateValues(a, curRes, '*', index + 1) ||
                calculateValues(a, curRes, '-', index + 1);
    }

}

int main() {
    while(true) {
        vector<int> nums;
        for (int i = 0; i < 5; ++i) {
            int n;
            cin >> n;
            nums.push_back(n);
        }
        if(nums[0] == 0) {
            break;
        }
        sort(nums.begin(), nums.end());

        bool possible = false;
        do {
            if (calculateValues(nums, nums[0], '+', 1) || calculateValues(nums, nums[0], '*', 1) ||
                calculateValues(nums, nums[0], '-', 1)) {

                possible = true;
            }
        } while (next_permutation(nums.begin(), nums.end()));

        if (!possible) {
            cout << "Impossible" << "\n";
        } else {
            cout << "Possible" << "\n";
        }
    }

}

