#include <bits/stdc++.h>
using namespace std;

int stair[302], score[3][302];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;

    for (int i = 1; i <= N; i++) cin >> stair[i];

    if (N == 1) {cout << stair[1]; return 0;}
    // 이게 없어도 오류는 나지 않지만, N = 1일 때 score[1][2]랑 score[2][2]에 접근하는 것이 바람직하지 않기 때문에 이렇게 처리함.
    
    score[1][1] = stair[1];
    score[2][1] = 0;
    score[1][2] = stair[1] + stair[2];
    score[2][2] = stair[2];

    for (int i = 3; i <= N; i++) {
        score[1][i] = score[2][i-1] + stair[i];
        score[2][i] = max(score[1][i-2], score[2][i-2]) + stair[i];
    }

    cout << max(score[1][N], score[2][N]);
}
// 3칸 연속 못 밟으니까 전칸 값 + 현재 값과 두칸전 값 + 현재 값 중 최댓값을 뽑으면 될 듯.
// D[n] = max(D[n-1], D[n-2]) + 점수[n]
// 이거 아닌가 다시 생각해보자
// 3 = 1+2 or 2+1
// 4 = 1+2+1 or 1+1+2 or (2+2) or 1+1+1+1(x)
// 5 = 1+2+1+1(x)4의 최댓값이 1+2+1인 경우일 수 있기 때문에 애매해짐. 1+1+2+1 or 2+1+2 or 1+2+2
// 아니지 마지막에 1을 탔으면 2만 타야되고
// 마지막에 2탔으면 1, 2 다되니까
// 마지막에 몇개 탔는지까지 인덱스로 표현하자. score[1][i] 는 i번째 계단에 도달하기 직전에 계단 1칸 올랐다는 뜻. 그럼 전에는 2개 올랐어야만 가능함.
// score[2][i]는 마지막에 2칸 탄다는 뜻이니까 전에 1개를 타든 2개를 타든 상관없음. 더 큰 거에다가 계산하기만 하면 돼.