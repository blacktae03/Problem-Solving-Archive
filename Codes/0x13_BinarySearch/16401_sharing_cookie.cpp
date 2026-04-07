#include <bits/stdc++.h>
using namespace std;

int M, N;
int L[1000010];

bool solve(int mid) {
    int ans = 0;
    for (int i = 0; i < N; i++) ans += L[i] / mid;
    return ans >= M; // M이랑 같아도 M인 최댓값을 찾아야 하기 때문에 ans가 M이랑 같아도 st를 mid+1로 해 줄 필요가 있음.
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    for (int i = 0; i < N; i++) cin >> L[i];

    int st = 1, en = 1'000'000'000;
    int mid = (st+en)/2;

    while (st <= en) {
        if (solve(mid)) st = mid+1;
        else en = mid-1;
        mid = (st+en)/2;
    }

    cout << mid;
}