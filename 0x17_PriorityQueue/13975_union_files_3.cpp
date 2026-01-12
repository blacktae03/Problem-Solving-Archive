#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T, K;
priority_queue<ll, vector<ll>, greater<>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--) {
        ll ans = 0;
        cin >> K;
        
        while (K--) {
            int C; cin >> C;
            pq.push(C);
        }
        
        while(true) {
            ll tmp = 0;
            tmp += pq.top();
            pq.pop();
            tmp += pq.top();
            pq.pop();
            ans += tmp;
            if (pq.empty()) break;
            pq.push(tmp);
        }

        cout << ans << '\n';
    }
}
// 30 30 40 50일 때
// 30 더하기 팝 (ans = 30)
// 30 더하기 팝 (ans = 60)
// 안 빔
// 60 푸쉬
// 40 더하기 팝 (ans = 100)
// 50 더하기 팝 (ans = 150)
// 
