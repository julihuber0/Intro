#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct Container {
    string s;
    int i;
};

int main() {
    vector<int> v;

    Container c;
    for(int i = 0; i<v.size(); ++i) {
        cout << v[i] << " ";
    }
}
