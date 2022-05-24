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

vector<int> zF(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }

    }
    return z;
}

const int ALPHABET_SIZE = 26;

struct node {
    int children[ALPHABET_SIZE];
    bool end_of_word;
};

vector<node> trie(1);

bool lookup(string s) {
    int tPos;
    for (int i = 0; i < s.size(); ++i) {
        int pos = s[i] - 97;
        if (trie[tPos].children[pos] != 0) {
            tPos = trie[tPos].children[pos];
        } else {
            return false;
        }
    }
    if (trie[tPos].end_of_word) {
        return true;
    } else {
        return false;
    }
}

bool insert(string s) {
    int tPos = 0;
    int i = 0;
    int pos = s[i] - 97;
    while (trie[tPos].children[pos] != 0) {
        tPos = trie[tPos].children[pos];
        i += 1;
        pos = s[i] - 97;
    }
    if (i == s.length()) {
        trie[tPos].end_of_word = true;
    } else {
        for (int j = i; j < s.size(); ++j) {
            node l{};
            pos = s[j] - 97;
            trie[tPos].children[pos] = trie.size();
            trie.push_back(l);
            tPos = trie.size() - 1;
        }
        trie[tPos].end_of_word = true;
    }
    return true;
}

int main() {
    insert("baum");
    insert("bamm");
    cout << lookup("baum") << "\n";
    cout << lookup("bamm") << "\n";
    cout << lookup("bam") << "\n";
}
