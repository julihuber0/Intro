#include <bits/stdc++.h>

using namespace std;


int main() {
    int64_t boxCount;
    cin >> boxCount;

    vector<int64_t> boxes(boxCount);


    for (int64_t i = 0; i < boxCount; ++i) {
        cin >> boxes[i];
    }

    sort(boxes.begin(), boxes.end());

    int64_t currentBox = 0;
    int64_t res = boxCount;     //The visible boxes
    for (int64_t i = 0; i < boxCount; ++i) {
        bool found = false;
        for (int64_t j = currentBox; j < boxCount; ++j) {
            if (boxes[i] * 2 <= boxes[j]) {
                currentBox = j + 1;
                res -= 1;
                found = true;
                break;
            }
        }
        if (!found) {
            break;
        }
    }

    cout << res << "\n";
}
