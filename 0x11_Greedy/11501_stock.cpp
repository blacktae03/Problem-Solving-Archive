#include <bits/stdc++.h>
using namespace std;

int N;
int S[1000010], tmp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;

    while(T--) {
        cin >> N;
        for (int i = 0; i < N; i++) cin >> S[i];
        S[N] = 0;
        int idx = 0, ans = 0;

        for (int i = 1; i <= N; i++) {
            tmp += S[i-1];

            if (S[i] < S[i-1]) {
                ans += S[i-1] * (i-idx) - tmp;
                idx = i;
                tmp = 0;
            }
        }

        cout << ans << '\n';
    }
}
// (다음 거가 지금꺼 보다 크면) 일단 산다. tmp += S[i-1] (사고 이가격에 바로 팔면 아무것도 안하는 거나 마찬가지)
// 다음 거를 봤는데 지금꺼 보다 작으면 지금 가격(S[i-1])에 판다. ans += S[i-1] * (i-idx) - tmp; i-idx : 지금까지 tmp에 더해진 값의 개수 
// 다음 거를 봤는데 지금꺼랑 같으면 일단 산다.
// 엥 잠만 이게 아닌가 최고점에서 다 파는게 이득인가
// 1 4 10 9 8 100 99 98 일 때,
// 나처럼 하면 : 1 4 일 때 산거 10 때 팔아야함. 9 + 6
// 근데 누가봐도.. 에잇 이거 아니네