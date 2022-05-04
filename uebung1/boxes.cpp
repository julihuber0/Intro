#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int boxCount;
    cin >> boxCount;

    vector<int> boxes(boxCount);

    for(int i = 0; i < boxCount; ++i) {
        int box;
        cin >> box;
        boxes[i] = box;
    }
    sort(boxes.begin(), boxes.end());
    int resBoxes = 0;
    while(!boxes.empty()) {
        int currentBox = boxes[0]*2;
        unsigned int index = 0;
        boxes.erase(boxes.begin()+index);
        while(index < boxes.size()) {
            if(boxes[index] >= currentBox) {
                currentBox = boxes[index]*2;
                boxes.erase(boxes.begin()+index);
            } else {
                index += 1;
            }
        }
        resBoxes += 1;
    }
    cout << resBoxes;

}
