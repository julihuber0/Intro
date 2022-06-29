#include <iostream>
#include <algorithm>

using namespace std;

bool isPossible(int64_t X, int64_t Y, int64_t squares2fill, int64_t currentTile);


int main() {
    int64_t X, Y, N, squares2fill;

    while(cin >> X >> Y >> N) {
        squares2fill = X * Y - ((X - 2) * (Y - 2));

        for (int i = 0; i < N; i++) {
            int64_t currentTile;
            cin >> currentTile;

            bool possible = isPossible(X, Y, squares2fill, currentTile)
                            || isPossible(Y, X, squares2fill, currentTile);

            if (possible) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}

bool isPossible(int64_t X, int64_t Y, int64_t squares2fill, int64_t currentTile) {
    if (currentTile == 1 || currentTile == 2) {
        return true;
    }
    if (squares2fill % currentTile != 0) {
        return false;
    }
    if (X % currentTile == 0) {
        // fill one side of the frame completely

        if ((Y - 2) % currentTile == 0) {
            return true;
        }
        if ((Y - 1) % currentTile == 0 && (X - 2) % currentTile == 0) {
            return true;
        }
    }
    if ((X - 1) % currentTile == 0 && (Y - 1) % currentTile == 0) {
        return true;
    }
    return false;
}


bool isPosible(int64_t X, int64_t Y, int64_t squares2fill, int64_t currentTile) {
    if (X % currentTile == 0 && (Y - 2) % currentTile == 0) {
        return true;
    } else if ((X - 1) % currentTile == 0 && (Y - 1) % currentTile == 0) {
        return true;
    } else if (X % currentTile == 0 && (Y - 1) % currentTile == 0 && currentTile == 2) {
        return true;
    } else {
        return false;
    }
}
