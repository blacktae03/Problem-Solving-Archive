#include <bits/stdc++.h>
using namespace std;

int v1[100004], v2[100004];
int N;
pair<int, int> table[100004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) cin >> v1[i];
    for (int i = 1; i <= N; i++) {
        int tmp; cin >> tmp;
        v2[tmp] = i;
    }

    for (int i = 1; i <= N; i++) {
        int curIdx = i % 2;
        int befIdx = !curIdx;
        // curIdx++, befIdx++;

        int cur1 = v1[i]; // 첫번째 배열의 i번쨰 숫자
        int cur2 = v2[cur1]; // 두번째 배열의 curi와 같은 숫자의 인덱스

        if (cur2 > table[i].second)
    }

    // for (int i = 0; i < 2; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         cout << table[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << table[N];
}
// 1 2 3 4 5 6
// 4 5 6 3 2 1