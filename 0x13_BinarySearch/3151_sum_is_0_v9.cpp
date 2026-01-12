#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, Z, ans;
int PI[20010], NI[20010];
vector<int> pos, neg;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        if (tmp > 0) {
            // PI[tmp]++;
            pos.push_back(tmp);
        }
        else if (tmp < 0) {
            // NI[tmp*-1]++;
            neg.push_back(tmp);
        }
        else Z++;
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    // if (Z) 
    for (auto p : pos) ans += (upper_bound(neg.begin(), neg.end(), p*-1) - lower_bound(neg.begin(), neg.end(), p*-1)) * Z; // O(N/2 * lg(N/2))
    
    if (Z >= 3) ans += Z * (Z-1) * (Z-2) / 6;

    for (int i = 0; i < pos.size()-1; i++) {
        for (int j = i+1; j < pos.size(); j++) {
            PI[pos[i]+pos[j]]++;
        }
    } // O(N^2)
    for (int i = 0; i < neg.size()-1; i++) {
        for (int j = i+1; j < neg.size(); j++) {
            NI[(neg[i] + neg[j])*-1]++;
        }
    } // O(N^2)

    for (int i = 0; i <= 10000; i++) {
        if (!NI[i]) continue;
        ans += (upper_bound(pos.begin(), pos.end(), i) - lower_bound(pos.begin(), pos.end(), i)) * NI[i]; // (n,n,p)인 경우 O(NlgN)
    }
    for (int i = 0; i <= 10000; i++) {
        if (!PI[i]) continue;
        ans += (upper_bound(neg.begin(), neg.end(), i*-1) - lower_bound(neg.begin(), neg.end(), i*-1)) * PI[i]; // (n,p,p)인 경우 O(NlgN)
    }

    cout << ans;
}
// O(N^2)까지는 통과 가능할 듯.
// 어떻게 해야 중복되는 걸 피할 수 있을까?
// 36번 줄 반복문에서 i값이 포함된 벡터에서는 찾으면 안됨.