#include <bits/stdc++.h>
using namespace std;

int N, K;
int A[13];
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    int Ncopy = N;
    while(N--) cin >> A[N];

    for (int i = 0; i < Ncopy; i++) {
        ans += K / A[N];
        K %= A[N]; // 바킹독은 이렇게 했더라 ㄷㄷ 왜 이생각을 못했징..
    }

    cout << ans;
}
// 동전 간 배수 관계가 성립하지 않는다면??
// 7 5 1가 있다고 생각해보자
// 11을 만들 때 7 하고 1 4개가 아니라
// 5 2개 하고 1 1개가 이득 ㄷㄷ;