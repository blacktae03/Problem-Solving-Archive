#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A, B, ans;
vector<bool> sieve(10000010, true); // 10MB
const int L = 10000000;

void SOE() {
    sieve[1] = false;
    for (int i = 2; i*i <= L; i++) {
        if (!sieve[i]) continue;
        for (int j = i*i; j <= L; j+=i) sieve[j] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    SOE();

    cin >> A >> B;
    
    for (ll i = 2; i*i <= B; i++) {
        if (!sieve[i]) continue;
        for (ll j = i; j <= B/i; j *= i) { // 와 이거 찾는다고 하루종일 헤맸네.. 답 안보고 끝까지 찾은 게 참 용하다 응??
            if (j*i < A) continue;
            ans++;
            // if (j > 1'000'000'000'000'00ll / i) break;
        }
    }

    // for (ll i = 2; i*i <= B; i++) {
    //     if (!sieve[i]) continue;
    //     for (ll j = i*i; j <= B; j *= i) {
    //         if (j < A) continue;
    //         ans++;
    //     }
    // }

    cout << ans;
    // cout << "sieve[10000000] = " << sieve[10000000] << '\n';
}

// 27번 줄이 제일 중요함. 코드의 전체적인 흐름이나 원리는 사실 그렇게 어렵지 않음. (에라토스테네스의 채 이용)
// 하지만 최댓값인 10^14까지의 거의 소수를 찾을 때 오버플로우 문제가 발생함.
// 34-40처럼 처음에 구현을 했었는데, B가 10^14라고 할 때, 반복문을 수행하는 i의 최댓값은 10^7이고, 이 때 j는 언뜻 보면 10^14까지 도는 것 같지만,
// 사실 10^21까지 곱해지고 그 때 반복문의 조건을 만족하지 않아 반복문을 중단하게 됨. 하지만 10^21은 long long의 범위를 이미 벗어남. 즉, 코드가 내 생각대로 돌아가지 않는다는 뜻.
// 그래서 if (j >= 1'000'000'000'000'0LL) break; (10^13이상 이면 break) 을 38 밑에 추가했었는데, 이유는 대략 10^13이상이면 오버플로우가 일어나지 않을까? 라는 막연한 생각 때문...
// 10^6일 때는 10^12 -> 10^18이라서 overflow 안 일어나기 때문임.
// 근데 딱봐도 깔끔해 보이지는 않음
// 그래서 27번 줄의 조건문을 j*i <= B로 했었음. j가 B(10^14)보다 커지기 전에 저지할 수 있기 때문임. 그래서 j*i가 가능한지를 판단하고 그걸 답의 개수에 추가하는 식. 원래는 j값 자체가 가능한지를 판단함.
// 뭔가 달라보이지만 사실 똑같은 코드인게, j*i 자체도 결국 오버플로우가 발생해야 반복문이 멈추기 때문. j가 overflow가 일어나지 않을 뿐 결국 j*i는 overflow 발생.
// 그래서 j*i <= B 를 판단하기 위한 같은 코드로 j <= B/i로 변경. 사실 이러면 B가 i로 나누어 떨어지지 않을 때 문제가 발생할 거라고 판단헀는데 문제가 발생하지는 않았음.
// 왜 문제가 발생하지 않았는지는 좀 알아봐야 할 듯.