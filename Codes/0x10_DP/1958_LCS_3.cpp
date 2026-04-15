#include <bits/stdc++.h>
using namespace std;

struct String {
    string s;

    char operator[] (const int& i) {
        return (this->s)[i-1];
    }
};

String S1, S2, S3;
int table[104][104][104];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();

    S1 = {s1}, S2 = {s2}, S3 = {s3};

    for (int i = 1; i <= l1; i++) {
        char cur1 = S1[i];

        for (int j = 1; j <= l2; j++) {
            char cur2 = S2[j];

            for (int k = 1; k <= l3; k++) {
                char cur3 = S3[k];

                int candSame = table[i-1][j-1][k-1];

                int cand1 = table[i-1][j-1][k];
                int cand2 = table[i-1][j][k-1];
                int cand3 = table[i][j-1][k-1];
                int cand4 = table[i-1][j][k];
                int cand5 = table[i][j][k-1];
                int cand6 = table[i][j-1][k];

                if (cur1 == cur2 && cur2 == cur3) table[i][j][k] = candSame + 1;
                else table[i][j][k] = max({cand1, cand2, cand3, cand4, cand5, cand6});
            }
        }
    }

    cout << table[l1][l2][l3];
}