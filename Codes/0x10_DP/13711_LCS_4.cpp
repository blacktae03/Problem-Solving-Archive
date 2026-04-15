#include <bits/stdc++.h>
using namespace std;

vector<int> v1, v2;
int N;
int table[2][100004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    v1.push_back(0);
    v2.push_back(0);
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        v1.push_back(tmp);
    }
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        v2.push_back(tmp);
    }

    // for (auto i1 : v1) cout << i1 << ' ';
    // cout << '\n';
    // for (auto i2 : v2) cout << i2 << ' ';
    // cout << '\n';


    // int l1 = v1.size()-1, l2 = v2.size()-1;

    for (int i = 1; i <= N; i++) {
        int curIdx = i % 2;
        int befIdx = !curIdx;
        // curIdx++, befIdx++;

        int cur1 = v1[i];

        for (int j = 1; j <= N; j++) {
            int cur2 = v2[j];

            if (cur1 == cur2) table[curIdx][j] = table[befIdx][j-1] + 1;
            else table[curIdx][j] = max(table[befIdx][j], table[curIdx][j-1]);
        }
    }

    // for (int i = 0; i < 2; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         cout << table[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << table[N%2][N];
}