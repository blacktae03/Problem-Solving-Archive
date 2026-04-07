// 정답인 거 같은데 백준 서버 먹통 250625
#include <bits/stdc++.h>
using namespace std;

int N;
int T[20], P[20], D[20];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    for (int i = N; i >= 1; i--) {
        if (i + T[i]-1 > N) continue;
        D[i] = P[i];

        for (int j = i+T[i]; j <= N; j++) {
            D[i] = max(D[i], D[j] + P[i]);
        }
    }

    cout << *max_element(D+1, D+1+N);
}

// D[i] = i일에 있는 상담을 첫 상담으로 하는 상담 일정의 최대 페이 값
// 이 문제는 특이하게 끝에서부터 해야할 듯.
// O(N^2)