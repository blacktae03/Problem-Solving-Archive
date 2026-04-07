#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, Z;
ll ans;
// int A[10010], B[10010];
vector<short> pos, neg, PS, NS;
// vector<pair<int, int>> idx;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        short tmp; cin >> tmp;
        if (tmp > 0) pos.push_back(tmp);
        else if (tmp < 0) neg.push_back(tmp);
        else Z++;
    }
    
    if (Z) { // (n, 0, p)인 경우
        if (neg.size() < pos.size()) {
            sort(neg.begin(), neg.end());
            for (auto p : pos) {
                p*=-1;
                ans += (upper_bound(neg.begin(), neg.end(), p) - lower_bound(neg.begin(), neg.end(), p)) * Z;
            }
        }
        else {
            sort(pos.begin(), pos.end());
            for (auto n : neg) {
                n *= -1;
                ans += (upper_bound(pos.begin(), pos.end(), n) - lower_bound(pos.begin(), pos.end(), n)) * Z;
            }
        }
    }
    if (Z >= 3) {
        ans += Z * (Z-1) * (Z-2) / 6;
    }

    for (int i = 0; i < pos.size()-1; i++) {
        for (int j = i+1; j < pos.size(); j++) {
            PS.push_back(pos[i] + pos[j]);
        }
    } // O(N^2)
    for (int i = 0; i < neg.size()-1; i++) {
        for (int j = i+1; j < neg.size(); j++) {
            NS.push_back(neg[i] + neg[j]);
        }
    } // O(N^2)
    sort(PS.begin(), PS.end()); // O(N^2lgN^2)
    sort(NS.begin(), NS.end());

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