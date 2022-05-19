#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
    int boxCount;
    cin >> boxCount;

    vector<int> boxes(5);
    vector<bool> done(5);



    for(int i = 0; i<boxCount; ++i) {
        int b = 0;
        cin >> b;
        boxes[i] = b;
        done[i] = false;
    }
    sort(boxes.begin(), boxes.end());

    int l = 0;
    int res = 1;
    while(l<boxCount-1) {
        for(int i = l+1; i<boxCount; ++i) {
            if(boxes[l]*2<=boxes[i] && !done[i]) {
                done[i] = true;
                l = i;
                //res +=1;
                break;
            }
        }
    }
    for(int i = 0; i<boxCount; ++i) {
        if(done[i]) {
            res += 1;
        }
    }

    cout << res;

}
