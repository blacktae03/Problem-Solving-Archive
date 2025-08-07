#include <bits/stdc++.h>
using namespace std;
// 갑자기 떠오른 풀이

int N, M;
int F[20000020];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while(N--) {
        int num; cin >> num;
        F[num+10000000]++;
    }

    cin >> M;
    while(M--) {
        int num; cin >> num;
        cout << F[num+10000000] << ' ';
    }
}