// Authored by : jihwan0123
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/806a14d843c342428e80993e46423b34
// 풀었으나 풀이 참고 // : 풀이 작성한 사람의 주석, //* : 내 주석
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> flower;
  for (int i = 0; i < n; i++) {
    int sm, sd, em, ed;
    cin >> sm >> sd >> em >> ed;
    flower.push_back({sm * 100 + sd, em * 100 + ed}); // 날짜는 대충 파싱해도 됨
  }

  int t = 301; // 현재 시간
  int ans = 0; // 선택한 꽃의 개수
  while (t < 1201) {
    int nxt_t = t; // 이번에 추가할 꽃으로 인해 변경된 시간
    for(int i = 0; i < n; i++){
      if(flower[i].X <= t && flower[i].Y > nxt_t) //* 모든 꽃 중에서 개화가 겹치면서 최대한 늦게 지는 꽃을 선택.
        nxt_t = flower[i].Y; //* nxt_t가 낙화 시기, 커지면 계속 업데이트를 해서 최대한 늦게 지는 꽃을 선택하는 것.
    }
    if(nxt_t == t){ // 시간 t에서 더 전진이 불가능
      cout << 0;
      return 0;
    }
    ans++;
    t = nxt_t; //* 시작 점을 다시 마지막 꽃의 낙화 시기로 해서 개화가 겹치는 꽃을 찾을 준비.
  }
  cout << ans;
}
/*
우선 그리디한 관점에서 생각해보면 매번 현재 시점에서 피어있는 꽃 중에서
가장 마지막에 지는 꽃을 선택하면 된다.

3월 1일에서부터 11월 30일까지는 총 276일의 기간이니 모든 꽃이 하루만에 피었다가
진다 해도 최대 276개의 꽃을 선택하기만 하면 된다. 그렇기 때문에 그냥 매번 O(N)으로 
꽃을 선택하면 된다. 시간복잡도는 최악의 경우 O(276N)이다.

만약 문제가 3월 1일 to 11월 30일이 아니라 1일에서 1,000,000,000일 사이에서 꽃들을
정해야 하는 문제였다면 매번 O(N)으로 다음 꽃을 탐색하는 풀이는 최대 O(N^2)으로
시간초과일텐데 이 경우 어떻게 해결하면 좋을지 고민해보는걸 추천한다.
*/