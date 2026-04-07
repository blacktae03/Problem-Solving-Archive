#include <bits/stdc++.h>
using namespace std;

struct String {
    string s;

    char operator[] (const int& i) {
        return (this->s)[i-1];
    }
};

String S1, S2;
int table[1004][1004];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.size(), l2 = s2.size();

    S1 = {s1}, S2 = {s2};

    // cout << S1[1] << S1[2] << S2[1] << S2[2];

    // fill(table[0]+1, table[0]+1004, -1);
    // for (int i = 1; i < 1004; i++) table[i][0] = -1;

    for (int i = 1; i <= l1; i++) {
        char curi = S1[i];

        for (int j = 1; j <= l2; j++) {
            char curj = S2[j];

            int cand1 = table[i-1][j-1];
            int cand2 = table[i-1][j];
            int cand3 = table[i][j-1];

            // if (curi == curj) table[i][j] = max(cand1 + 1, max(cand2, cand3));
            // else table[i][j] = max(cand2, cand3);
            table[i][j] = max(cand1 + int(curi == curj), max(cand2, cand3));
        }
    }

    // for (int i = 1; i <= l1; i++) {
    //     for (int j = 1; j <= l2; j++) {
    //         cout << table[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << table[l1][l2];
}