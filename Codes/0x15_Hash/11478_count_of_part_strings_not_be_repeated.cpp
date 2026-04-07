#include <bits/stdc++.h>
using namespace std;

string str;
unordered_set<string> S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        string tmp = "";
        for (int j = i; j < str.size(); j++) {
            tmp += str[j];
            S.insert(tmp);
        }
    }

    cout << S.size();
}