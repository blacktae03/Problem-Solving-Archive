#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char word[101];
    // string word;

    int aphb[26] = {0,};
    //fill(aphb, aphb+26, 0);

    cin >> word;
    // cin >> word;
    for (int i = 0; i < 100 && word[i] != 0; i++) {
        aphb[word[i]-97] += 1;
    }
    // for (auto c : word) {
    //     aphb[c-'a']++;
    // }

    for (int j = 0; j < 26; j++) {
        cout << aphb[j] << " ";
    }
}