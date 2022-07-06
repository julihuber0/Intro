#include <bits/stdc++.h>

using namespace std;


using BigInt = vector<int64_t>;
using Matrix = vector<vector<BigInt>>;

template<
        class result_t   = std::chrono::milliseconds,
        class clock_t    = std::chrono::steady_clock,
        class duration_t = std::chrono::milliseconds
>
auto since(std::chrono::time_point<clock_t, duration_t> const &start) {
    return std::chrono::duration_cast<result_t>(clock_t::now() - start);
}

int64_t size = 100000000;
string zeros = "00000000";
int digits = 8;

vector<BigInt> fac;
vector<BigInt> fibo;

bool printNumber(BigInt &v1) {
    bool empty = false;
    for (int i = v1.size() - 1; i >= 0; --i) {
        if (v1[i] != 0) {
            string num = to_string(v1[i]);

            if (i != v1.size() - 1) {
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

BigInt add(BigInt const &s1, BigInt const &s2) {
    int64_t carry = 0;
    BigInt result;
    int64_t length = max(s1.size(), s2.size());
    BigInt sum1(length, 0);
    BigInt sum2(length, 0);
    for (int i = 0; i < s1.size(); ++i) {
        sum1[i] = s1[i];
    }
    for (int i = 0; i < s2.size(); ++i) {
        sum2[i] = s2[i];
    }
    for (int i = 0; i < length; ++i) {
        int64_t a = sum1[i] + sum2[i] + carry;
        result.push_back(a % size);
        carry = a / size;
    }
    if (carry == 1) {
        result.push_back(1);
    }
    return result;
}

BigInt multiply(BigInt const &v1, BigInt const &v2) {
    BigInt result(17, 0);
    for (int i = 0; i < v2.size(); ++i) {
        vector<int64_t> part(result.size(), 0);
        for (int j = 0; j < v1.size(); ++j) {
            if ((i + j) > 15) {
                break;
            }
            part[i + j] += (v2[i] * v1[j]) % size;
            part[i + j + 1] += (v2[i] * v1[j]) / size;
        }
        result = add(part, result);
    }
    while (result[result.size() - 1] == 0) {
        result.pop_back();
    }
    return result;
}

bool factorial(int v) {
    BigInt r = {1};
    fac.push_back(r);
    fac.push_back(r);
    BigInt it = {2};
    for (int i = 1; i < v; ++i) {
        fac.push_back(multiply(fac[i], it));
        it = add(it, {1});
    }
    return true;
}

Matrix multiplyMatrix(Matrix const &m1, Matrix const &m2) {
    Matrix res(2, vector<BigInt>(2, BigInt(1, 0)));
    res[0][0] = add(multiply(m1[0][0], m2[0][0]), multiply(m1[0][1], m2[1][0]));
    res[0][1] = add(multiply(m1[0][0], m2[0][1]), multiply(m1[0][1], m2[1][1]));
    res[1][0] = add(multiply(m1[1][0], m2[0][0]), multiply(m1[1][1], m2[1][0]));
    res[1][1] = add(multiply(m1[1][0], m2[0][1]), multiply(m1[1][1], m2[1][1]));
    return res;
}

Matrix matPow(Matrix m, int64_t n) {
    if (n == 1) {
        return m;
    } else if (n % 2 == 1) {
        return multiplyMatrix(m, matPow(m, n - 1));
    } else {
        Matrix temp = matPow(m, n / 2);
        return multiplyMatrix(temp, temp);
    }
}

BigInt fib(int64_t n) {
    if (n == 0) {
        return {0};
    }
    if (n == 1) {
        return {1};
    }
    Matrix m1(2);
    m1[0].push_back({1});
    m1[0].push_back({1});
    m1[1].push_back({1});
    m1[1].push_back({0});
    Matrix pwd = matPow(m1, n - 1);
    return pwd[0][0];
}

bool printString(BigInt v) {
    string out;
    for (int i = v.size() - 1; i >= 0; --i) {
        if (v[i] != 0) {
            string num = to_string(v[i]);

            if (i != v.size() - 1) {
                for (int i = 0; i < digits - num.size(); ++i) {
                    out.append("0");
                }
            }
            out.append(num);
        } else {
            out.append(zeros);
        }
    }
    if (out.size() < 100) {
        cout << out << endl;
    } else {
        bool zero = false;
        for (int i = 99; i >= 0; --i) {
            if (out[out.size() - i - 1] != '0') {
                zero = true;
            }
            if(zero) {
                cout << out[out.size() - i - 1];
            }
        }
        cout << endl;
    }
    return true;
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            cout << 0 << endl;
        } else {
            BigInt f = fib(n);
            printString(f);
        }
    }
}