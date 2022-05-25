#include <bits/stdc++.h>

using namespace std;

const int ALPHABET_SIZE = 2;

struct node {
    int64_t children[ALPHABET_SIZE] = {0, 0};
    bool end_of_word = false;
    bool subnet = false;
};

vector<node> trie(1);

bool lookup(string s) {
    if (trie[0].subnet) {
        return true;
    }
    int64_t tPos = 0;
    for (int64_t i = 0; i < s.size(); ++i) {
        int pos = s[i] - '0';
        if (trie.at(tPos).children[pos] != 0) {
            tPos = trie.at(tPos).children[pos];
            if (trie.at(tPos).subnet) {
                return true;
            }
        } else {
            if (trie.at(tPos).subnet) {
                return true;
            } else {
                return false;
            }
        }
    }
    if (trie.at(tPos).end_of_word) {
        return true;
    } else {
        return false;
    }
}

bool insert(string s) {
    int64_t tPos = 0;
    int64_t i = 0;
    if (s[i] == '*') {
        trie.at(tPos).subnet = true;
        return true;
    }
    int64_t pos = s[i] - '0';
    while (trie.at(tPos).children[pos] != 0) {
        tPos = trie.at(tPos).children[pos];
        i += 1;
        if (s[i] != '*') {
            pos = s[i] - '0';
        } else {
            trie.at(tPos).subnet = true;
        }
        if(i==s.size()) {
            break;
        }
    }
    if (i == s.length()) {
        trie.at(tPos).end_of_word = true;
    } else {
        for (int64_t j = i; j < s.size(); ++j) {
            if (s[j] != '*') {
                node l{};
                pos = s[j] - '0';
                trie.at(tPos).children[pos] = trie.size();
                trie.push_back(l);
                tPos = trie.size() - 1;
            } else {
                trie.at(tPos).subnet = true;
            }
        }
        trie.at(tPos).end_of_word = true;
    }
    return true;
}

int main() {
    int64_t actCount;
    cin >> actCount;

    for (int64_t i = 0; i < actCount; ++i) {
        string ip;
        cin >> ip;
        insert(ip);
    }

    int64_t empCount;
    cin >> empCount;
    vector<string> emps(empCount);
    for (int i = 0; i < empCount; ++i) {
        string ip;
        cin >> ip;
        if (lookup(ip)) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }


}
