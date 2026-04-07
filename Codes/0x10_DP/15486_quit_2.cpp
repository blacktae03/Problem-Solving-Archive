// 정답인 거 같은데 백준 서버 먹통 250625
#include <bits/stdc++.h>
using namespace std;

int N;
int T[1500005], P[1500005], D[1500005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> T[i] >> P[i];
    D[1] = P[1];
    
    for (int i = 2; i <= N; i++) {
        if (i + T[i]-1 > N) continue;
        D[i] = P[i];

        for (int j = 1; j <= 50; j++) {
            if (i-j <= 0) continue;
            if (i-j + T[i-j] <= i) {
                D[i] = max(D[i], D[i-j] + P[i]);
            }
        }
    }

    // for (int i = 1; i <= N; i++) cout << D[i] << ' ';
    // cout << '\n';

    cout << *max_element(D+1, D+1+N);
}

// 14501_quit이랑 같은 문제인데 시간복잡도 O(N) or O(NlgN)..
// 고민 좀 오래해야할 듯.
// O(NlgN)은 안 나올 것 같고 O(N)인데..
// D[i] = i일의 상담이 마지막 상담인 상담 일정의 페이의 최댓값이라고 해보자.
// 된 것 같기도 하고 안에 반복문 하나 있어도 결국 50 * N인데 결국 O(N) 이긴 함.