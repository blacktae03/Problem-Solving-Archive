#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, Z;
ll ans;
// int PI[10010], NI[10010];
vector<ll> V, sum;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll tmp; cin >> tmp;
        V.push_back(tmp);
        // if (tmp > 0) {
        //     PI[tmp]++;
        //     pos.push_back(tmp);
        // }
        // else if (tmp < 0) {
        //     NI[tmp*-1]++;
        //     neg.push_back(tmp);
        // }
        // else Z++;
    }

    for (int i = 0; i < V.size()-1; i++) {
        for (int j = i+1; j < V.size(); j++) {
            sum.push_back(V[i] + V[j]);
        }
    } // O(N^2)

    sort(sum.begin(), sum.end());

    for (auto p : pos) {
        p *= -1;
        ans += upper_bound(NS.begin(), NS.end(), p) - lower_bound(NS.begin(), NS.end(), p); // (n,n,p)인 경우 O(NlgN^2)
    }
    for (auto n : neg) {
        n *= -1;
        ans += upper_bound(PS.begin(), PS.end(), n) - lower_bound(PS.begin(), PS.end(), n); // (p,p,n)인 경우
    }

    cout << ans;
}
// O(N^2)까지는 통과 가능할 듯.
// 어떻게 해야 중복되는 걸 피할 수 있을까?
// 36번 줄 반복문에서 i값이 포함된 벡터에서는 찾으면 안됨.