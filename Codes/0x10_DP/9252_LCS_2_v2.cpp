#include <bits/stdc++.h>
using namespace std;

struct String {
    string s;

    char operator[] (int idx) {
        return s[idx-1];
    }
};

String S1, S2;
int table[1004][1004];
bool mask[1004];
stack<char> ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.size(), l2 = s2.size();

    S1 = {s1}, S2 = {s2};

    for (int i = 1; i <= l1; i++) {
        char curi = S1[i];
        
        for (int j = 1; j <= l2; j++) {
            char curj = S2[j];
            int cand1 = table[i-1][j-1];
            int cand2 = table[i-1][j];
            int cand3 = table[i][j-1];

            if (curi == curj) table[i][j] = cand1 + 1;
            else table[i][j] = max(cand2, cand3);
        }
    }


    // for (auto idx : record) {
    //     cout << idx << ' ';
    //     ans += S1[idx];
    // }

    int tracki = l1, trackj = l2;
    int state = table[tracki][trackj];
    
    while (state) {
        char curi = S1[tracki], curj = S2[trackj];

        if (curi == curj) {
            ans.push(curi);
            tracki--;
            trackj--;
        }

        else {
            int cand1 = table[tracki-1][trackj];
            int cand2 = table[tracki][trackj-1];

            if (cand1 > cand2) tracki--;
            else trackj--;
        }

        state = table[tracki][trackj];
    }

    cout << table[l1][l2] << '\n';

    while (!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
}

// 마지막에 백트래킹 한 번 해주기