#include <bits/stdc++.h>

using namespace std;

int64_t mod(int64_t x, int64_t m) {
    int64_t r = ((x % m) + m) % m;
    return r;
}

int64_t euclid(int64_t a, int64_t b) {
    if (a < b) {
        return euclid(b, a);
    }
    if (b == 0) {
        return a;
    }
    return euclid(b, mod(a, b));
}

tuple<int64_t, int64_t, int64_t> extended_euclid(int64_t a, int64_t b) {
    if (b == 0) {
        return make_tuple(a, 1, 0);
    }
    int64_t gcd, k, l;
    tie(gcd, k, l) = extended_euclid(b, mod(a, b));
    return make_tuple(gcd, l, k - (a / b) * l);
}

int64_t solve(vector<int64_t> a, vector<int64_t> m) {
    int64_t M = 1;
    int64_t n = m.size();
    int64_t max = 0;
    for (int i = 0; i < n; ++i) {
        M = M * m[i];
        if(a[i]>max) {
            max = a[i];
        }
    }
    vector<int64_t> b(n);
    for (int i = 0; i < n; ++i) {
        int64_t M_i = M / m[i];
        tuple<int64_t, int64_t, int64_t> t = extended_euclid(M_i, m[i]);
        b[i] = M_i * get<1>(t);
    }
    int64_t r = 0;
    for (int i = 0; i < n; ++i) {
        r += mod(a[i] * b[i], M);
        r = mod(r, M);
    }
    while(r<max) {
        r += M;
    }
    return r;
}

int main() {
    int P;
    while (cin >> P) {
        vector<int64_t> a;
        vector<int64_t> m;
        for (int i = 0; i < P; ++i) {
            int64_t a_i, m_i;
            cin >> a_i >> m_i;
            a.push_back(a_i);
            m.push_back(m_i);
        }
        int64_t r = solve(a, m);
        cout << r << endl;
    }
}
