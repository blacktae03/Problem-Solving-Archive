#include <bits/stdc++.h>
using namespace std;

int M, N, T, x, y, lmt, ans;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while(T--) {
        cin >> M >> N >> x >> y;
        lmt = M > N ? lcm(M, N) : lcm(N, M);
        // x %= M, y %= N;
        y %= N;

        for (ans = x; ans <= lmt; ans += M) {
            // for (int j = y; j <= i; j += N) {
            //     if (i != j) continue;
            //     ans = i;
            //     break;
            // }
            if (ans % N != y) continue;
            break;
        }

        // for (int i = 1; i <= lmt; i++) {
        //     if (i % M == x && i % N == y) {
        //         ans = i;
        //         break;
        //     }
        // }

        if (ans > lmt) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}
// 첫 번째로 1번째 해부터 LCM(M, N)번째 해까지를 봐야하는건 맞는데,
// 사실 코드에서 l = lcm(m, n)을 계산해서 i <= l을 하는 대신 그냥 i <= m*n 으로 두고 for문을 돌려도 답은 똑같이 잘 나옵니다.
// 이렇게 하면 굳이 gcd, lcm 함수를 쓸 필요가 없어서 더 편한데 왜 lcm(m, n)을 계산하지 않고 m*n까지로 범위를 잡아도 똑같이 잘 동작하는지 고민을 해봅시다.
// 이유 : lcm(m, n)까지 가기 전에 어차피 답이 결정되기 때문이다. lcm(m, n) 전에 답이 안나오면 그 이후로 가도 답이 나오지 않는다.
// lcm(m, n) * gcd(m, n) == m * n 이므로, 어떤 수 Z이 Z % M == x && Z % N == y 를 만족하는 최소의 수일 때, Zi = lcm(m, n) * (i-1) + Z;
// 간단히 말하면 순환한다는 뜻이다. m이 10이고 n이 12일 때 Z % 10 == 3 && Z % 12 == 9인 Z를 구하면 33인데, 33에 lcm(m, n)인 60을 더해도 똑같이 성립한다는 것이다.
// 33에 60을 더한 93도 10으로 나누면 나머지 3, 12로 나누면 나머지 9이다.

// 두 번째로 지금은 2개의 식에 대해서 해결을 해야 했는데 만약 식이 3개 혹은 4개 이렇게 더 늘어나면 어떻게 될까요?
// 예를 들어 <x:y:z> 꼴이 되어서 K로 나눈 나머지가 z여야 한다는 조건이 추가된 상황을 생각해봅시다. 식이 2개일 때에는 LCM(N,M) / M개의 수, 즉 최대 N개의 수를 확인했는데 식이 3개일 때에는 몇 개의 수를 확인해야 할까요?
// 33번 줄을 ans % N != y || ans % K != z 로 하면 됨. LCM(LCM(N, M), K) / M개의 수만큼 하면 되겠죠?

// 마지막에 다룰 얘기는 코딩테스트의 범위를 벗어나는 얘기여서 대회를 노릴 분만 참고하면 됩니다. 원래 대회에서는 연립합동방정식을 중국인의 나머지 정리로 풉니다.
// 중국인의 나머지 정리는 N, M에 대한 로그 스케일로 돌기 때문에 N, M이 10^9 정도로 크더라도 아주 빠르게 계산할 수 있습니다.
// 다만 중국인의 나머지 정리를 이해하려면 모듈로 역수, 확장된 유클리드 호제법 등을 다 알아야하기 때문에 강의에서는 다루지 않을 예정이고 따로 자료를 찾아보시는걸 추천드립니다.
// 내일 찾아보기
// 