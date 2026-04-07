#include <bits/stdc++.h>
using namespace std;

int N, ans, cap;
priority_queue<pair<int, int>> pq;
int cnt[200020];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int d, c;
        cin >> d >> c;

        pq.push({c, d});
        cap = max(d, cap);
    }

    int eaten = 0;

    while(!pq.empty() && eaten < cap) {
        if (cnt[pq.top().second] < pq.top().second && eaten < cap) {
            ans += pq.top().first;
            eaten++;
            cnt[pq.top().second]++;
        }
        pq.pop();
    }

    cout << ans;
}
// 이것도 아닌게..
// 