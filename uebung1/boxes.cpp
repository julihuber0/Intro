#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> boxes;
vector<bool> done;

int main() {
    int boxCount;
    cin >> boxCount;

    done.resize(boxCount);

    for(int i = 0; i<boxCount; ++i) {
        int x = 0;
        cin >> x;
        boxes.push_back(x);
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
