#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;

int K, N;
int L[10010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> N;
    for (int i = 0; i < K; i++) cin >> L[i];

    ui st = 1, en = *max_element(L, L+K);
    ui mid = (st+en)/2;

    while(st <= en) {
        int cnt = 0;
        for (int i = 0; i < K; i++) cnt += L[i] / mid;

        if (cnt < N) en = mid-1;
        else st = mid+1;
        mid = (st+en)/2;
    }

    cout << mid;
}

// 진짜 말도 안되는 풀이.. 내가 직접 구현만 했지 엄청난 개념이다.
// 조건을 만족하는 최소/최댓값을 구하는 문제 (최적화 문제)를 결정 문제로 변환해 이분탐색 하는 방법 : Parametric Search
// N개의 랜선을 만들 수 있는 랜선 길이의 최댓값 -> 어떤 길이의 랜선이 랜선을 N개 만큼 만들 수 있는가 아닌가?
// 강좌 블로그 그래프 참고 진짜 말도 안되게 충격적이네.
// sorted 이어야 이분탐색을 쓸 수 있었듯, 그래프로 표현하였을 때 증가/감소 함수 여야만 사용이 가능함.
// 풀이에서는 long long 씀 왜냐하면 st와 en의 최댓값이 각각 INT_MAX 인데, mid에서 그럼 더해질 때 오버플로우가 발생하기 때문.
// 더해지면 최댓값이 INT_MAX*2 == UINT_MAX 이므로 그냥 나는 uint 사용함.
// 엥 근데 왜 mid만 ui면 오답이라고 뜨지 흠..