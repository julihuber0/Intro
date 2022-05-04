#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int64_t rows;
    cin >> rows;
    int64_t columns;
    cin >> columns;

    int64_t min = fmin(rows, columns);
    int64_t rounds;

    if(min%2==0) {
        rounds = min/2;
    } else {
        rounds = min/2 + 1;
    }

    int64_t runCounter = 0;
    vector<vector<int64_t>> mx(rows, vector<int64_t>(columns));

    for(int64_t i = 0; i<rows; ++i) {
        for(int64_t j = 0; j<columns; ++j) {
            int64_t value;
            cin >> value;
            mx[i][j] = value;
        }
    }

    while(runCounter < rounds) {
        for (int64_t i = runCounter; i < columns; ++i) {
            if(mx[runCounter][i] >= 0) {
                cout << mx[runCounter][i] << " ";
                mx[runCounter][i] = -1;
            }
        }
        for(int64_t i = runCounter+1; i<rows; ++i) {
            if(mx[i][columns-1] >= 0) {
                cout << mx[i][columns - 1] << " ";
                mx[i][columns - 1] = -1;
            }
        }
        if(columns >1 && rows > 1) {
            for (int64_t i = columns - 2; i >= runCounter; --i) {
                if (mx[rows - 1][i] >= 0) {
                    cout << mx[rows - 1][i] << " ";
                    mx[rows - 1][i] = -1;
                }
            }
            for (int64_t i = rows - 2; i > runCounter; --i) {
                if (mx[i][runCounter] >= 0) {
                    cout << mx[i][runCounter] << " ";
                    mx[i][runCounter] = -1;
                }
            }
        }
        runCounter += 1;
        columns -= 1;
        rows -= 1;
    }
    return 0;
}
