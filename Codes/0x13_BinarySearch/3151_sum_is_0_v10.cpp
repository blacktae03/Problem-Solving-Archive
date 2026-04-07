#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, Z, pcnt, ncnt;
ll ans;
int PI[20010], NI[20010];
// vector<int> pos, neg;
int pos[10010], neg[10010];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        if (tmp > 0) {
            // PI[tmp]++;
            pos[pcnt++] = tmp;
        }
        else if (tmp < 0) {
            // NI[tmp*-1]++;
            neg[ncnt++] = tmp;
        }
        else Z++;
    }

    sort(pos, pos+pcnt);
    sort(neg, neg+ncnt);

    // if (Z) 
    for (auto p : pos) ans += (upper_bound(neg, neg+ncnt, p*-1) - lower_bound(neg, neg+ncnt, p*-1)) * Z; // O(N/2 * lg(N/2))
    
    if (Z >= 3) ans += Z * (Z-1) * (Z-2) / 6;

    for (int i = 0; i < pcnt-1; i++) {
        for (int j = i+1; j < pcnt; j++) {
            PI[pos[i]+pos[j]]++;
        }
    } // O(N^2)
    for (int i = 0; i < ncnt-1; i++) {
        for (int j = i+1; j < ncnt; j++) {
            NI[(neg[i] + neg[j])*-1]++;
        }
    } // O(N^2)

    for (int i = 0; i <= 10000; i++) {
        if (!NI[i]) continue;
        ans += (upper_bound(pos, pos+pcnt, i) - lower_bound(pos, pos+pcnt, i)) * NI[i]; // (n,n,p)인 경우 O(NlgN)
    }
    for (int i = 0; i <= 10000; i++) {
        if (!PI[i]) continue;
        ans += (upper_bound(neg, neg+ncnt, i*-1) - lower_bound(neg, neg+ncnt, i*-1)) * PI[i]; // (n,p,p)인 경우 O(NlgN)
    }

    cout << ans;
}
// 와 진짜 거짓말처럼 벡터를 배열로 바꾸니까 해결되네 시22발 앞에것도 그런건 아니겠지?
// 배운 점 : 배열을 쓸 수 있다면 최대한 배열을 쓰자.