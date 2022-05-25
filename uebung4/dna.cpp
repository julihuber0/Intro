#include <bits/stdc++.h>

using namespace std;

vector<int> praesuffix(string s) {
    int n = (int) s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
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
    vector<int> c = praesuffix(r);
    int count = 0;
    for (int i = 0; i < c.size(); ++i) {
        if (c[i] == t.length()) {
            count += 1;
        }
    }
    return count;
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
        for(int i = 1; i<st1.size(); ++i) {
            for(int j = 0; j<=i; ++j) {
                string sub = st1.substr(j, st1.size()-i);
                if(kmp(st2, sub)>0) {
                    seq.insert(sub);
                }
            }
            if(!seq.empty()) {
                return seq;
            }
        }
        return seq;
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
