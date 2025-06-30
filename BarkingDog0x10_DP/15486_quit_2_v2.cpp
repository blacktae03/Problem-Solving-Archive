// 정답인 거 같은데 백준 서버 먹통 250625
#include <bits/stdc++.h>
using namespace std;

int N;
int T[1500005], P[1500005];
int D[1500005][2], idx[1500005][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> T[i] >> P[i];
    if (T[1] <= N) {
        D[1][1] = P[1];
        idx[1][1] = 1;
    }
    D[1][0] = 0;
    idx[1][0] = 0;
    
    for (int i = 2; i <= N; i++) {
        if (D[i-1][1] > D[i-1][0]) {
            D[i][0] = D[i-1][1];
            idx[i][0] = idx[i-1][1];
        }

        else {
            D[i][0] = D[i-1][0];
            idx[i][0] = idx[i-1][0];
        }

        if (i + T[i]-1 > N) continue;
        D[i][1] = P[i];
        idx[i][1] = i;

        for (int j = 1; j <= 50; j++) {
            if (i-j <= 0) break;
            
            for (int k = 0; k <= 1; k++) {
                if (idx[i-j][k] + T[idx[i-j][k]] <= i) {
                    D[i][1] = max(D[i][1], D[i-j][k] + P[i]);
                }
            }
        }
    }

    // for (int i = 1; i <= N; i++) cout << D[i][0] << ' ' << D[i][1] << " | ";
    // cout << '\n';

    cout << max(D[N][0], D[N][1]);
}
// 두번째 시도. 내가 볼 때 2차원 만들어야함
// D[i][0or1] = i일의 상담이 마지막 상담으로 포함된(1) 또는 포함되지 않은(0) 상담 일정의 페이의 최댓값이라고 해보자.

// 14501_quit이랑 같은 문제인데 시간복잡도 O(N) or O(NlgN)..
// 고민 좀 오래해야할 듯.
// O(NlgN)은 안 나올 것 같고 O(N)인데..
// D[i] = i일의 상담이 마지막 상담인 상담 일정의 페이의 최댓값이라고 해보자.
// 된 것 같기도 하고 안에 반복문 하나 있어도 결국 50 * N인데 결국 O(N) 이긴 함.