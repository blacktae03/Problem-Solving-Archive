#include <bits/stdc++.h>
using namespace std;

int M, N, ans;
vector<int> before, after[104];

void compression() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int tmp; cin >> tmp;
            before.push_back(tmp);
            after[i].push_back(tmp);
        }

        before.erase(unique(before.begin(), before.end()), before.end()); // 이건 빅오에 영향을 끼치지 않음.
        sort(before.begin(), before.end());
        for (int j = 0; j < N; j++) after[i][j] = lower_bound(before.begin(), before.end(), after[i][j]) - before.begin(); // O(MNlgN)
        before.clear();
    }

    for (int i = 0; i < M; i++) {
        for (int j = i+1; j < M; j++) {
            int k;

            for (k = 0; k < N; k++) if (after[i][k] != after[j][k]) break; // O(MMN)
            if (k == N) ans++;
        }
    }

    // for (int i = 0; i < M; i++) {
    //     for (int j = 0; j < N; j++) cout << after[i][j] << ' ';
    //     cout << '\n';
    // }

    cout << ans;
}
// 내가 짠 코드랑 시간 복잡도는 비슷함. 이 코드의 24번 줄과 18869_multiverse_II_v2.cpp 코드의 24-26번 줄이 시간복잡도가 차이나기는 하나 빅오의 관점에서는 영향을 끼치지 않아서 내 코드도 통과 가능
// 만약 이분탐색이 아니라 내 방법으로 했을 때 문제가 발생한다면 이분탐색으로 풀어야하는 문제가 될 듯.