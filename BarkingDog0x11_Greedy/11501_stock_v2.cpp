#include <bits/stdc++.h>
using namespace std;

int N;
int S[1000010];
int mxidx = 0, oldidx = 0;
long long ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;

    while(T--) {
        cin >> N;
        for (int i = 0; i < N; i++) cin >> S[i];
        mxidx = 0, oldidx = 0;
        ans = 0;
        
        while (oldidx < N) {
            int max = 0;
            for (int i = oldidx; i < N; i++) {
                if (S[i] < max) continue; // <= 라고 하면 1 4 10 9 8 100 100 100 일 때, 3번이나 반복해야함, < 라고 하면 1번만 하고 끝내면 됨. (시간초과 발생 이유)
                max = S[i];
                mxidx = i;
            }

            for (int i = oldidx; i < mxidx; i++) ans += max - S[i];
            oldidx = mxidx+1;
        }

        cout << ans << '\n';
    }
}
// (다음 거가 지금꺼 보다 크면) 일단 산다. tmp += S[i-1] (사고 이가격에 바로 팔면 아무것도 안하는 거나 마찬가지)
// 다음 거를 봤는데 지금꺼 보다 작으면 지금 가격(S[i-1])에 판다. ans += S[i-1] * (i-idx) - tmp; i-idx : 지금까지 tmp에 더해진 값의 개수 
// 다음 거를 봤는데 지금꺼랑 같으면 일단 산다.
// 엥 잠만 이게 아닌가 최고점에서 다 파는게 이득인가
// 1 4 10 9 8 100 99 98 일 때,
// 나처럼 하면 안돼
// 최고점을 찾아. 그 앞에 다 사.
// 최고점 뒤에서 다시 최고점 찾아. 그 앞에 다 사. 맨 끝에 도달할 때까지 반복
// 1 4 10 9 8을 하나씩 사서 100 때 팔면 되므로 답은 99 + 96 + 90 + 91 + 92 = 468
// 10000(S의 최댓값) * 1000000(N의 최댓값) = 10 000 000 000 (100억) 이므로 long long 써야함
// 시간초과 발생! 24번 줄 수정하여 시간초과 해결 (주석 참고)