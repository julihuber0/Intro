#include <bits/stdc++.h>

using namespace std;

bool printNumber(vector<int> &v1) {
    for(int i = 0; i<v1.size(); ++i) {
        if(i == 0 && v1[i]==0) {

        } else {
            cout << v1[i];
        }
    }
    cout << "\n";
    return true;
}

vector<int> add(vector<int> v1, vector<int> v2) {
    std::reverse(v1.begin(), v1.end());
    std::reverse(v2.begin(), v2.end());
    int length = max(v1.size(), v2.size());
    vector<int> sum1(length, 0);
    vector<int> sum2(length, 0);
    vector<int> result;
    for(int i = 0; i<v1.size(); ++i) {
        sum1[i] = v1[i];
    }
    for(int i = 0; i<v2.size(); ++i) {
        sum2[i] = v2[i];
    }
    int carry = 0;
    for(int i = 0; i<length; ++i) {
        int a = sum1[i]+sum2[i] + carry;
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

vector<int> addR(vector<int> v1, vector<int> v2) {
    int length = max(v1.size(), v2.size());
    vector<int> sum1(length, 0);
    vector<int> sum2(length, 0);
    vector<int> result;
    for(int i = 0; i<v1.size(); ++i) {
        sum1[i] = v1[i];
    }
    for(int i = 0; i<v2.size(); ++i) {
        sum2[i] = v2[i];
    }
    int carry = 0;
    for(int i = 0; i<length; ++i) {
        int a = sum1[i]+sum2[i] + carry;
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

vector<int> multiply(vector<int> v1, vector<int> v2) {
    vector<int> result(v1.size()+v2.size(), 0);
    std::reverse(v1.begin(), v1.end());
    std::reverse(v2.begin(), v2.end());
    for(int i = 0; i<v2.size(); ++i) {
        vector<int> part(result.size(), 0);
        vector<int> part2(result.size(), 0);
        for(int j = 0; j<v1.size(); ++j) {
            part[i+j] = (v2[i]*v1[j])%10;
            part2[i+j+1] = (v2[i]*v1[j])/10;
        }
        part = addR(part, part2);
        result = addR(part, result);
    }
    if(result[result.size()-1]==0) {
        result.pop_back();
    }
    std::reverse(result.begin(), result.end());
    return result;
}

vector<int> factorial(int v) {
    vector<int> r = {1};
    vector<int> it = {1};
    for(int i = 1; i<v; ++i) {
        it = add(it, {1});
        r = multiply(r, it);
    }
    return r;
}

int pow(int x, int n) {
    if(n == 0) {
        return 1;
    } else if(n==1){
        return x;
    } else if(n%2 == 1) {
        return x * pow(x, n-1);
    } else {
        int temp = pow(x, n/2);
        return temp * temp;
    }
}

vector<vector<int64_t>> multiplyMatrix(vector<vector<int64_t>> m1, vector<vector<int64_t>> m2) {
    vector<vector<int64_t>> res(2, vector<int64_t>(2, 0));
    res[0][0] = m1[0][0]*m2[0][0] + m1[0][1]*m2[1][0];
    res[0][1] = m1[0][0]*m2[0][1] + m1[0][1]*m2[1][1];
    res[1][0] = m1[1][0]*m2[0][0] + m1[1][1]*m2[1][0];
    res[1][1] = m1[1][0]*m2[0][1] + m1[1][1]*m2[1][1];
    return res;
}

vector<vector<int64_t>> matPow(vector<vector<int64_t>> m, int n) {
    if(n == 1) {
        return m;
    } else if(n%2==1) {
        return multiplyMatrix(m, matPow(m, n-1));
    } else {
        vector<vector<int64_t>> temp = matPow(m, n/2);
        return multiplyMatrix(temp, temp);
    }
}

int64_t fib(int n) {
    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return 1;
    }
    vector<vector<int64_t>> m1(2);
    m1[0].push_back(1);
    m1[0].push_back(1);
    m1[1].push_back(1);
    m1[1].push_back(0);
    vector<vector<int64_t>> pwd = matPow(m1, n-1);
    return pwd[0][0];
}

int main() {
    int64_t f = fib(95);
    cout << f;
}
