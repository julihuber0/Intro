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
    string r = s + "#" + t;
    vector<int> c = praesuffix(r);
    int count = 0;
    for (int i = 0; i < c.size(); ++i) {
        if (c[i] == t.length()) {
            count += 1;
        }
    }
    return count;
}

int main() {
    int cases;
    string numstr;
    getline(cin, numstr);
    cases = atoi(numstr.c_str());

    for (int i = 0; i < cases; ++i) {
        string exp;
        getline(cin, exp);
        string text;
        getline(cin, text);
        char op = 'e';
        bool valid = false;

        if (exp.find('+') != string::npos) {
            op = '+';
            //cout << "Yeet" << "\n";
        } else if (exp.find('*') != string::npos) {
            op = '*';
        }
        switch (op) {
            case 'e':
                if (text == exp) {
                    valid = true;
                }
                break;
            case '+':
                //cout << "Yeet" << "\n";
                if (text.size() >= exp.size()) {
                    int pos = exp.find('+');
                    string pref = exp.substr(0, pos);
                    string suff = exp.substr(pos + 1, exp.size());
                    string tpref = text.substr(0, pos);
                    string tsuff = text.substr(text.size() - suff.size(), text.size());
                    //cout << tpref << "\n";
                    //cout << tsuff << "\n";
                    if (pref == tpref && suff == tsuff) {
                        valid = true;
                    }
                }
                break;
            case '*':
                if (text.size() >= exp.size() - 1) {
                    int pos = exp.find('*');
                    string pref = exp.substr(0, pos);
                    string suff = exp.substr(pos + 1, exp.size());
                    string tpref = text.substr(0, pos);
                    string tsuff = text.substr(text.size() - suff.size(), text.size());
                    if (pref == tpref && suff == tsuff) {
                        valid = true;
                    }
                }
                break;
            default:
                break;
        }
        if (valid) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
}
