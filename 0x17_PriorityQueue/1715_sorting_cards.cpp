#include <bits/stdc++.h>
using namespace std;

int N, ans;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    // pq.push(0);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        pq.push(x);
    }

    if (N == 1) {
        cout << 0 << '\n';
        return 0;
    }

    // ans = pq.top();
    // pq.pop();

    // for (int i = 0; i < N; i++) {
    //     ans += ans + pq.top();
    //     pq.pop();
    //     pq.push(ans + pq.top());
    // }
    // ans += pq.top();
    // pq.pop();
    // ans += pq.top();
    // pq.pop();

    while (pq.size() > 1) {
        int tmp = pq.top();
        pq.pop();
        tmp += pq.top();
        pq.pop();
        pq.push(tmp);
        ans += tmp;
    }

    cout << ans;
}
// 10 20 40
// 30짜리 만들고
// 30이랑 40 합친다.

// 20 30 40 60
// 50 짜리 만들고
// 40이랑 50이랑 합치고
// 60이랑 90이랑 합친다.
