#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
    int boxCount;
    cin >> boxCount;

    vector<int> boxes(boxCount);
    vector<bool> done(boxCount);
    vector<bool> belegt(boxCount);



    for(int i = 0; i<boxCount; ++i) {
        cin >> boxes[i];
        done[i] = false;
        belegt[i] = false;
    }

    sort(boxes.begin(), boxes.end());

    int l = 0;
    int res = 0;
    while(l<boxCount) {
        for(int i = l+1; i<boxCount; ++i) {
            if(boxes[l]*2<=boxes[i] && !belegt[i] && !done[i]) {
                done[l] = true;
                belegt[i] = true;
                //res +=1;
                break;
            }
        }
        l += 1;
    }

    for(int i = 0; i< boxCount; ++i) {
        if(!done[i]) {
            res += 1;
        }
    }

    cout << res << "\n";

}
