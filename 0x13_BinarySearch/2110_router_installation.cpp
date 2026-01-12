#include <bits/stdc++.h>
using namespace std;
// 와 진짜 parametric search 존나 어렵다 그냥 말이 안되네;;
// 이거 랜선이랑 접목 시켜서 겨우 풀었음 그냥 말이 안됨. 모든 parametric search 문제 다 익숙해질 때까지는 랜선이랑 접목 시켜서 풀어야함...

int N, C, target;
int X[200020];

bool solve(int mid) { // 공유기 사이의 최대 거리가 mid일 때 공유기 개수가 몇 개인가?
    int cnt = 1; // 공유기 개수
    int st = X[0];
    for (int i = 1; i < N; i++) {
        if (X[i] - st < mid) continue;
        cnt++;
        st = X[i];
    }
    // cout << "* " << mid << ' ' << cnt << " *\n";

    return cnt >= C;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;
    for (int i = 0; i < N; i++) cin >> X[i];
    sort(X, X+N);

    // target = (X[0] + X[N-1]) / (N-1);

    int st = 1, en = X[N-1] - X[0];
    int mid = (st+en)/2;

    while (st <= en) {
        if (solve(mid)) st = mid+1;
        else en = mid-1;
        mid = (st+en)/2;
    }

    cout << mid;
}