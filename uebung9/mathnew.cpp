#include <bits/stdc++.h>

using namespace std;

template<
        class result_t   = std::chrono::milliseconds,
        class clock_t    = std::chrono::steady_clock,
        class duration_t = std::chrono::milliseconds
>
auto since(std::chrono::time_point<clock_t, duration_t> const &start) {
    return std::chrono::duration_cast<result_t>(clock_t::now() - start);
}

int64_t size = 10000000;
string zeros = "0000000";
int digits = 7;

vector<vector<int64_t>> fac;
vector<vector<int64_t>> fibo;

bool printNumber(vector<int64_t> &v1) {
    bool empty = false;
    for (int i = 0; i < v1.size(); ++i) {
         if (v1[i] != 0) {
            string num = to_string(v1[i]);

            if(i!=0) {
                for (int i = 0; i < digits - num.size(); ++i) {
                    cout << "0";
                }
            }
            cout << num;
        } else {
            cout << zeros;
        }
    }
    cout << "\n";
    return true;
}

vector<int64_t> add(vector<int64_t> s1, vector<int64_t> s2) {
    int64_t carry = 0;
    std::reverse(s1.begin(), s1.end());
    std::reverse(s2.begin(), s2.end());
    vector<int64_t> result;
    int64_t length = max(s1.size(), s2.size());
    vector<int64_t> sum1(length, 0);
    vector<int64_t> sum2(length, 0);
    for (int i = 0; i < s1.size(); ++i) {
        sum1[i] = s1[i];
    }
    for (int i = 0; i < s2.size(); ++i) {
        sum2[i] = s2[i];
    }
    for (int i = 0; i < length; ++i) {
        int64_t a = sum1[i] + sum2[i] + carry;
        result.push_back(a % size);
        if (a >= size) {
            carry = 1;
        } else {
            carry = 0;
        }
    }
    if (carry == 1) {
        result.push_back(1);
    }
    std::reverse(result.begin(), result.end());
    return result;
}

vector<int64_t> addR(vector<int64_t> s1, vector<int64_t> s2) {
    int64_t carry = 0;
    vector<int64_t> result;
    int64_t length = max(s1.size(), s2.size());
    vector<int64_t> sum1(length, 0);
    vector<int64_t> sum2(length, 0);
    for (int i = 0; i < s1.size(); ++i) {
        sum1[i] = s1[i];
    }
    for (int i = 0; i < s2.size(); ++i) {
        sum2[i] = s2[i];
    }
    for (int i = 0; i < length; ++i) {
        int64_t a = sum1[i] + sum2[i] + carry;
        result.push_back(a % size);
        if (a >= size) {
            carry = 1;
        } else {
            carry = 0;
        }
    }
    if (carry == 1) {
        result.push_back(1);
    }
    return result;
}

vector<int64_t> multiply(vector<int64_t> v1, vector<int64_t> v2) {
    vector<int64_t> result(v1.size() + v2.size(), 0);
    std::reverse(v1.begin(), v1.end());
    std::reverse(v2.begin(), v2.end());
    for (int i = 0; i < v2.size(); ++i) {
        vector<int64_t> part(result.size(), 0);
        vector<int64_t> part2(result.size(), 0);
        for (int j = 0; j < v1.size(); ++j) {
            part[i + j] = (v2[i] * v1[j]) % size;
            part2[i + j + 1] = (v2[i] * v1[j]) / size;
        }
        part = addR(part, part2);
        result = addR(part, result);
    }
    while (result[result.size() - 1] == 0) {
        result.pop_back();
    }
    std::reverse(result.begin(), result.end());
    return result;
}

bool factorial(int v) {
    vector<int64_t> r = {1};
    fac.push_back(r);
    fac.push_back(r);
    vector<int64_t> it = {2};
    for (int i = 1; i < v; ++i) {
        fac.push_back(multiply(fac[i], it));
        it = add(it, {1});
    }
    return true;
}

vector<vector<vector<int64_t>>> multiplyMatrix(vector<vector<vector<int64_t>>> m1, vector<vector<vector<int64_t>>> m2) {
    vector<vector<vector<int64_t>>> res(2, vector<vector<int64_t>>(2, vector<int64_t>(1, 0)));
    res[0][0] = add(multiply(m1[0][0], m2[0][0]), multiply(m1[0][1], m2[1][0]));
    res[0][1] = add(multiply(m1[0][0], m2[0][1]), multiply(m1[0][1], m2[1][1]));
    res[1][0] = add(multiply(m1[1][0], m2[0][0]), multiply(m1[1][1], m2[1][0]));
    res[1][1] = add(multiply(m1[1][0], m2[0][1]), multiply(m1[1][1], m2[1][1]));
    return res;
}

vector<vector<vector<int64_t>>> matPow(vector<vector<vector<int64_t>>> m, int64_t n) {
    if(n == 1) {
        return m;
    } else if(n%2==1) {
        return multiplyMatrix(m, matPow(m, n-1));
    } else {
        vector<vector<vector<int64_t>>> temp = matPow(m, n/2);
        return multiplyMatrix(temp, temp);
    }
}

vector<int64_t> fib(int64_t n) {
    if(n == 0) {
        return {0};
    }
    if(n == 1) {
        return {1};
    }
    vector<vector<vector<int64_t>>> m1(2);
    m1[0].push_back({1});
    m1[0].push_back({1});
    m1[1].push_back({1});
    m1[1].push_back({0});
    vector<vector<vector<int64_t>>> pwd = matPow(m1, n-1);
    return pwd[0][0];
}

bool printString(vector<int64_t> &v) {
    string out;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] != 0) {
            string num = to_string(v[i]);

            if(i!=0) {
                for (int i = 0; i < digits - num.size(); ++i) {
                    out.append("0");
                }
            }
            out.append(num);
        } else {
            out.append(zeros);
        }
    }
    if(out.size()<=100) {
        cout << out << endl;
    } else {
        for(int i = 0; i<100; ++i) {
            cout << out[out.size()-i];
        }
        cout << endl;
    }
    return true;
}

int main() {
    int n;
    while(cin >> n) {
        if(n == 0) {
            cout << 0 << endl;
        } else {
            vector<int64_t> f = fib(n);
            printString(f);
        }
    }

}