#include <bits/stdc++.h>

using namespace std;

vector<bool> primes(int n) {
    vector<bool> pr(n, true);
    pr[0] = false;
    pr[1] = false;
    int r = ceil(sqrt(n));
    for (int p = 2; p <= r; ++p) {
        if (pr[p]) {
            for (int i = p * p; i < n; i += p) {
                pr[i] = false;
            }
        }
    }
    return pr;
}

vector<int> factor(int n) {
    vector<int> factors;
    int r = ceil(sqrt(n));
    for (int p = 2; p <= r; ++p) {
        while (n % p != 0) {
            factors.push_back(p);
            n = n / p;
        }
    }
    if (n != 1) {
        factors.push_back(n);
    }
    return factors;
}

int64_t mod(int64_t x, int64_t m) {
    return ((x % m) + m) % m;
}

int64_t gcd(int64_t a, int64_t b) {
    if (a < b) {
        return gcd(b, a);
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, mod(a, b));
}

tuple<int64_t, int64_t, int64_t> extended_euclid(int64_t a, int64_t b) {
    if (b == 0) {
        return make_tuple(a, 1, 0);
    }
    int gcd, k, l;
    tie(gcd, k, l) = extended_euclid(b, mod(a,b));
    return make_tuple(gcd, l, k - (a/b) * l);
}

tuple<int, int, int> extended_gcd(int a, int b)
{
    if (a == 0) {
        return make_tuple(b, 0, 1);
    }

    int gcd, x, y;

    tie(gcd, x, y) = extended_gcd(b % a, a);

    return make_tuple(gcd, (y - (b/a) * x), x);
}

int main() {
    int cases;
    cin >> cases;
    for (int t = 0; t < cases; ++t) {
        int k, c;
        cin >> k >> c;
        if(c == 1) {
            cout << k + 1;
        } else {
            tuple<int64_t, int64_t, int64_t> r = extended_euclid(k, c);
            if (get<0>(r) != 1) {
                cout << "IMPOSSIBLE" << endl;
            } else {
                int64_t l = get<2>(r);
                if(l<=0) {
                    l += k;
                }
                cout << l << endl;
            }
        }
    }
    //tuple<int64_t, int64_t, int64_t> r = extended_gcd(23, 1337);
    //int a = 3;
}
