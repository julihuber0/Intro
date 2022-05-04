#include <iostream>

using namespace std;

int main() {
    cout << "? insert 42" << endl;
    cout << "? insert 1" << endl;
    cout << "? insert 1" << endl;
    cout << "? insert 3" << endl;

    cout << "? remove" << endl;
    int a;
    cin >> a;
    if(a == 1) {
        cout << "? remove" << endl;
        cin >> a;
        if(a == 1) {
            cout << "! pq" << endl;
        } else {
            cout << "! set" << endl;
        }
        return 0;
    } else if(a == 42) {
        cout << "! queue" << endl;
        return 0;
    } else {
        cout << "! stack" << endl;
    }
    return 0;
}
