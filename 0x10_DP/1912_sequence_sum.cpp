#include <bits/stdc++.h>
using namespace std;

int N;
int nums[100002], D[100002], sum[100002];
int st, en;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    fill(D, D+N+1, -10000);

    for (int i = 1; i <= N; i++) {
        cin >> nums[i];
        if (nums[i] > D[1]) {
            D[1] = nums[i];
            st = i, en = i;
        }
        D[1] = max(nums[i], D[1]);
    }

    for (int i = 2; i <= N; i++) {
        for (int dir = 0; dir < 2; dir++) {
            int nx;
            if (dir) nx = en+1;
            else nx = st-1;

            if (nx > N || nx < 1) continue;
            
            if (D[i-1] + nums[nx] > D[i]) {
                D[i] = D[i-1] + nums[nx];
                if (dir) {en++; st = en - (i-1);}
                else {st--; en = st + (i-1);}
            }
        }
    }

    cout << *max_element(D+1, D+N+1);
}

// D[i][j] = i개의 연속된 수의 합 (j는 시작점) 라고 하면 메모리 부족함
// D[i] = i가 시작점인 합의 최댓값이라고 해야할 듯. 라고 하면 시간 초과 남. (합을 계속 구해야해서) (사실 이렇게 해도 잘 짜면 되긴하는데)
// D[i] = i가 끝점인 합의 최댓값이라고 하자.
// 지금까지 한 건 그냥 다 DP가 아니라 일일이 다 하는 느낌이었음.
// D[i] = i개의 수만큼 연속으로 더 했을 떄의 합의 최댓값