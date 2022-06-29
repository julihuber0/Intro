#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cat {
    int64_t X, Y, Z;

    bool operator<(const Cat &rhs) const {
        if (X * rhs.Y == rhs.X * Y) {
            return X * X + Y * Y < rhs.X * rhs.X + rhs.Y * rhs.Y;
        }
        return X * rhs.Y < rhs.X * Y;
    }
};

bool hasSameSight(Cat rhs, Cat lhs) {
    return lhs.X * rhs.Y == rhs.X * lhs.Y;
}

bool smaller(const Cat &c1, const Cat &c2) {
    if (c1.X == c2.X) {
        return c1.Y < c2.Y;
    }
    return c1.X < c2.X;
}

int main() {
    int64_t numberOfCats;

    while (cin >> numberOfCats) {

        if (numberOfCats == 0) {
            break;
        }

        vector<Cat> cats(numberOfCats);
        vector<Cat> bukkit;

        //Input
        for (int64_t i = 0; i < numberOfCats; i++) {
            int64_t X, Y, Z;
            cin >> X >> Y >> Z;
            cats[i] = {X, Y, Z};
        }

        //Algorithm
        sort(cats.begin(), cats.end());
        int64_t maxHeight = -1;

        for (int64_t i = 0; i < numberOfCats; i++) {

            bool canSee = cats[i].Z > maxHeight;
            maxHeight = max(cats[i].Z, maxHeight);
            if (!canSee) {
                bukkit.push_back(cats[i]);
            }
            if (i < numberOfCats - 1 && !hasSameSight(cats[i], cats[i + 1])) {
                maxHeight = -1;
            }
        }

        //Output
        if (bukkit.empty()) {
            cout << "I be keepin mah bukkits." << endl;
        } else {
            sort(bukkit.begin(), bukkit.end(), smaller);
            cout << "Bukkit delivaries:" << endl;
            for (auto & i : bukkit) {
                cout << i.X << " " << i.Y << endl;
            }
        }
    }
}


