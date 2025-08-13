// 원래하던 방식으로 해볼라 했는데 생각해보니까 내가 벡터 썼던 이유가
// 합을 저장하려면 1억개의 인덱스를 만들어야해서 그럼 애초에 안될듯.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, Z, pcnt, ncnt;
ll ans;
short PI[20010], NI[20010];
short pos[10010], neg[10010];



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        short tmp; cin >> tmp;
        if (tmp > 0) {
            pos[pcnt++] = tmp;
        }
        else if (tmp < 0) {
            neg[ncnt++] = tmp;
        }
        else Z++;
    }

    sort(pos, pos+pcnt);
    sort(neg, neg+ncnt);
    
    for (auto p : pos) ans += (upper_bound(neg, neg+ncnt, p*-1) - lower_bound(neg, neg+ncnt, p*-1)) * Z; // O(N/2 * lg(N/2))
    if (Z >= 3) {
        ans += Z * (Z-1) * (Z-2) / 6;
    }

    for (int i = 0; i < pcnt-1; i++) {
        for (int j = i+1; j < pcnt; j++) {

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