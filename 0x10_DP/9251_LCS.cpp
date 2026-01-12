#include <bits/stdc++.h>
using namespace std;

pair<string, int> V[1004][1004];
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str, cmp;
    cin >> str >> cmp;

    for (int c = 0; c < cmp.size(); c++) {
        for (int s = 0; s < str.size(); s++) {
            if (str[s] != cmp[c]) continue;
            ans = 1;
            string buf = "";
            buf += cmp[c];
            V[1][c] = {buf, s};
            break;
        }
    }

    for (int i = 2; i <= 1000; i++) {
        for (int j = 0; j < cmp.size(); j++) {
            auto p = V[i-1][j];
            if (p.first == "") continue;
            for (int c = j+1; c < cmp.size(); c++) {
    
                for (int s = p.second+1; s < str.size(); s++) {
                    if (str[s] != cmp[c]) continue;
                    V[i][c] = {p.first + cmp[c], s};
                    ans = i;
                }
            }
        }
    }

    cout << ans;
}
// str = ACAYKP
// cmp = CAPCAK
// 가 있으면,
// C부터 ACAYKP에 있는지 확인
// 있으니까 V[1][0] = {C, 1}; (str[1]이 C이기 때문)
// A도 str에 있는지 확인
// V[1][1] = {A, 0}; (cmp[1]이 A이고 str[0]이 A이기 때문)
// V[1][2] = {P, 5};
// V[1][3] = {C, 1};
// V[1][4] = {A, 0};
// V[1][5] = {K, 4};
// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA