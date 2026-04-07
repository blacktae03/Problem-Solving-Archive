// 아예 첨부터 다시 생각.
// 
#include <bits/stdc++.h>
using namespace std;

int N;
int nums[100002], D[100002], sum[100002];
int idx;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    fill(D, D+N+1, -10000);

    for (int i = 1; i <= N; i++) {
        cin >> nums[i];
        sum[i] = sum[i-1] + nums[i];
        if (sum[i] > D[1]) {
            D[1] = sum[i];
            idx = i;
        }
    }

    for (int i = 2; i <= idx; i++) {
        D[i] = D[i-1] - nums[i-1];
    }

    cout << *max_element(D+1, D+N+1);
}

// D[i][j] = i개의 연속된 수의 합 (j는 시작점) 라고 하면 메모리 부족함
// D[i] = i가 시작점인 합의 최댓값이라고 해야할 듯. 라고 하면 시간 초과 남. (합을 계속 구해야해서) (사실 이렇게 해도 잘 짜면 되긴하는데)
// D[i] = i가 끝점인 합의 최댓값이라고 하자. prefix sum 쓰기 위함.
// 지금까지 한 건 그냥 다 DP가 아니라 일일이 다 하는 느낌이었음. (다 시간 초과 남;;;;;)
// D[i] = i개의 수만큼 연속으로 더 했을 떄의 합의 최댓값
// D[i] = i번째 수를 시작점으로 한 연속합의 최댓값
// 아 오늘은 안디ㅗ겠다 포기 시22발 진짜 왤캐 힘들어 대가리 터질거같네 진짜.