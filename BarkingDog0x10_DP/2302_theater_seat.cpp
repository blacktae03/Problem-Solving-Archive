#include <bits/stdc++.h>
using namespace std;

int N, M;
int D[44];
int ans = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    D[0] = 1;
    D[1] = 1;
    D[2] = 2;

    for (int i = 3; i <= 40; i++) {
        D[i] = D[i-2] + D[i-1];
    }

    int idx = 0;
    for (int i = 1; i <= M; i++) {
        int tmp; cin >> tmp;
        ans *= D[tmp-1-idx];
        idx = tmp;
    }
    ans *= D[N-idx];

    cout << ans;
}
// D[i] = i번째 좌석까지 있을 때 경우의 수 == i번째 좌석이 i-1번째에 있는 경우(D[i-2]) + i번째 좌석이 i번째에 있는 경우(D[i-1])