#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int boxCount;
    cin >> boxCount;

    vector<int> boxes(boxCount);
    vector<bool> done(boxCount);

    for(int i = 0; i<boxCount; ++i) {
        int b;
        cin >> b;
        boxes[i] = b;
        done[i] = false;
    }
    sort(boxes.begin(), boxes.end());

    int l = 0;
    while(l<boxCount) {
        for(int i = l+1; i<boxCount; ++i) {
            if(boxes[l]*2<=boxes[i] && done[i]!= true) {
                done[i] = true;
                break;
            }
        }
        l +=1;
    }
    int res = 0;
    for(int i = 0; i<boxCount; ++i) {
        if(done[i] == false) {
            res += 1;
        }
    }
    cout << res;

}
