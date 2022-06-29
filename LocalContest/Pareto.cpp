#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool leaveTip(int64_t oldResFood, int64_t oldResWine, int64_t curResFood, int64_t curResWine) {
    return oldResFood >= curResFood && oldResWine >= curResWine;
}

struct Res {
    int64_t food;
    int64_t wine;
    int64_t number;
};

bool smallerFood(const Res &c1, const Res &c2) {
    return c1.food < c2.food;
}

bool smallerWine(const Res &c1, const Res &c2) {
    return c1.wine < c2.wine;
}

int main() {
    int64_t numberOfCases;
    cin >> numberOfCases;

    for (int i = 0; i < numberOfCases; i++) {
        int64_t tips = 0;
        int64_t numberRestaurants;
        cin >> numberRestaurants;

        vector<Res> restaurants (numberRestaurants);
        vector<Res> restaurantsFood (numberRestaurants);
        vector<Res> restaurantsWine (numberRestaurants);

        for(int k = 0; k < numberRestaurants; k++) {
            int64_t foodRating, wineRating;
            cin >> foodRating >> wineRating;

            restaurants[k] = {foodRating, wineRating, k};
            restaurantsFood[k] = {foodRating, wineRating, k};
            restaurantsWine[k] = {foodRating, wineRating, k};

            bool hasSeenBetter = false;

            if (!hasSeenBetter) {
                tips++;
            }
        }

        sort(restaurantsFood.begin(), restaurantsFood.end(), smallerFood);
        sort(restaurantsWine.begin(), restaurantsWine.end(), smallerWine);

        for(int k = 0; k < numberRestaurants; k++) {
            
        }
    }
}