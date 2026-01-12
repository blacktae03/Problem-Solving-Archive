#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, ans;
vector<ll> D[11]; // 0은 안씀

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < 10; i++) {
        D[1].push_back(i);
        if (ans == N) {
            cout << i;
            return 0;
        }
        ans++;
    }
    
    ll st = 1;
    for (int i = 2; i <= 10; i++) {
        st *= 10;
        for (int j = i-1; j < 10; j++) {
            for (ll n : D[i-1]) {
                if (n / (st/10) >= j) break;
                ll tmp = st * j;
                tmp += n;
                D[i].push_back(tmp);
                if (ans == N) {
                    cout << tmp;
                    return 0;
                }
                ans++;
            }
        }
    }
    // cout << ans; // 1023
    cout << -1;

    // for (auto v : D) {
    //     for (auto n : v) {
    //         cout << n << ' ';
    //     }
    //     cout << '\n';
    // }
}
// DP랑 비슷한 느낌으로 풀었음 코드 보면 무슨 말인지 이해 가능
// long long 쓴 이유 : 마지막 숫자인 9876543210이 int 범위를 벗어남 uint도 벗어남.