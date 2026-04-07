#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
ll T[1000010];

bool solve(int mid) {
    ll ans = 0; // 계속 높이가 1억인 나무들이 더해지다 보면 얼마나 커질지 모르기 때문에 long long 쓰기
    for (int i = 0; i < N; i++) ans += T[i] > mid ? T[i] - mid : 0;
    return ans >= M;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> T[i];

    ll st = 0, en = 1'000'000'000;
    ll mid = (st+en)/2;

    while(st <= en) {
        if (solve(mid)) st = mid+1;
        else en = mid-1;
        mid = (st+en)/2;
    }

    cout << mid;
}