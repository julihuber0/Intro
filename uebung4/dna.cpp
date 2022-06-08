#include <bits/stdc++.h>

using namespace std;

vector<int64_t> praesuffix(string s) {
    int64_t n = (int64_t) s.length();
    vector<int64_t> pi(n);
    for (int64_t i = 1; i < n; i++) {
        int64_t j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int kmp(string s, string t) {
    string r = t + "#" + s;
    vector<int64_t> c = praesuffix(r);
    int64_t count = 0;
    for (int64_t i = 0; i < c.size(); ++i) {
        if (c[i] == t.length()) {
            count += 1;
        }
    }
    return count;
}

int64_t maxV(vector<int64_t> v, int64_t wl) {
    int64_t max = 0;
    for(int64_t i = wl; i<v.size(); ++i) {
        if(v[i]>max) {
            max = v[i];
        }
    }
    return max;
}

int64_t maxSF(int64_t a, int64_t b) {
    if(a>b) {
        return a;
    }
    return b;
}

set<string> longestSeq(string s1, string s2) {
    string st1;
    string st2;
    if(s1.size()<s2.size()) {
        st1=s1;
        st2=s2;
    } else {
        st1=s2;
        st2=s1;
    }

    set<string> seq;
    if(s1==s2) {
        seq.insert(s1);
        return seq;
    } else {
        int64_t m = 0;
        for(int64_t i = 0; i<st1.size(); ++i) {
            string sub = st1.substr(i, st1.size()-i);
            m = maxSF(maxV(praesuffix(sub+"#"+st2), sub.size()), m);
        }
        if(m>0) {
            for (int64_t i = 0; i <= st1.size() - m; ++i) {
                string sub = st1.substr(i, m);
                if (kmp(st2, sub) > 0) {
                    seq.insert(sub);
                }
            }
        }
    }
}

int main() {
    string s1, s2, nl;
    do{
        getline(cin, s1);
        getline(cin, s2);

        set<string> s = longestSeq(s1, s2);
        if(s.empty()) {
            cout << "No common sequence." << "\n";
        } else {
            for(string st:s) {
                cout << st << "\n";
            }
        }
        cout << "\n";

    } while(getline(cin, nl));

}
