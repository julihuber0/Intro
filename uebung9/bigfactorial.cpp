#include <bits/stdc++.h>

using namespace std;

vector<vector<short>> fibo;

bool printNumber(vector<short> &v1) {
    for(int i = 0; i<v1.size(); ++i) {
        if(i == 0 && v1[i]==0) {

        } else {
            cout << v1[i];
        }
    }
    cout << "\n";
    return true;
}

vector<short> add(vector<short> v1, vector<short> v2) {
    std::reverse(v1.begin(), v1.end());
    std::reverse(v2.begin(), v2.end());
    int length = max(v1.size(), v2.size());
    vector<short> sum1(length, 0);
    vector<short> sum2(length, 0);
    vector<short> result;
    for(int i = 0; i<v1.size(); ++i) {
        sum1[i] = v1[i];
    }
    for(int i = 0; i<v2.size(); ++i) {
        sum2[i] = v2[i];
    }
    short carry = 0;
    for(int i = 0; i<length; ++i) {
        short a = sum1[i]+sum2[i] + carry;
        result.push_back(a%10);
        if(a>9) {
            carry = 1;
        } else {
            carry = 0;
        }
    }
    if(carry == 1) {
        result.push_back(1);
    }
    std::reverse(result.begin(), result.end());
    return result;

}

vector<short> addR(vector<short> v1, vector<short> v2) {
    int length = max(v1.size(), v2.size());
    vector<short> sum1(length, 0);
    vector<short> sum2(length, 0);
    vector<short> result;
    for(int i = 0; i<v1.size(); ++i) {
        sum1[i] = v1[i];
    }
    for(int i = 0; i<v2.size(); ++i) {
        sum2[i] = v2[i];
    }
    short carry = 0;
    for(int i = 0; i<length; ++i) {
        short a = sum1[i]+sum2[i] + carry;
        result.push_back(a%10);
        if(a>9) {
            carry = 1;
        } else {
            carry = 0;
        }
    }
    if(carry == 1) {
        result.push_back(1);
    }
    //std::reverse(result.begin(), result.end());
    return result;
}

vector<short> multiply(vector<short> v1, vector<short> v2) {
    vector<short> result(v1.size()+v2.size(), 0);
    std::reverse(v1.begin(), v1.end());
    std::reverse(v2.begin(), v2.end());
    for(int i = 0; i<v2.size(); ++i) {
        vector<short> part(result.size(), 0);
        vector<short> part2(result.size(), 0);
        for(int j = 0; j<v1.size(); ++j) {
            part[i+j] = (v2[i]*v1[j])%10;
            part2[i+j+1] = (v2[i]*v1[j])/10;
        }
        part = addR(part, part2);
        result = addR(part, result);
    }
    while(result[result.size()-1]==0) {
        result.pop_back();
    }
    std::reverse(result.begin(), result.end());
    return result;
}

bool factorial(int v) {
    vector<short> r = {1};
    fibo.push_back(r);
    fibo.push_back(r);
    vector<short> it = {2};
    for(int i = 1; i<v; ++i) {
        fibo.push_back(multiply(fibo[i], it));
        it = add(it, {1});
        //r = multiply(r, it);
    }
    return true;
}

int main() {
    int cases = 1;
    //cin >> cases;
    for(int t = 0; t< cases; ++t) {
        int n;
        //cin >> n;
        factorial(1000);
        printNumber(fibo[1000]);
    }
}
