// Authored by : sukam09
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/a75486aadfc04beeb40786a0728ffc78
#include <bits/stdc++.h>
using namespace std;

int n;
int a[25][25];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];

  vector<int> team(n);
  fill(team.begin() + n / 2, team.end(), 1);
  int ans = 0x7f7f7f7f;
  // team = {0, 0, 0, .., 0, 1, 1, .. ,1}, team[i]는 i번째 선수의 팀을 의미
  do {
    int diff = 0; // 능력치의 차이
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++){ // 초깃값 설정이 다름. 시간복잡도가 내가 더 많이 걸리긴할 듯.
        if(team[i] != team[j]) continue;
        if(team[i] == 0) diff += (a[i][j] + a[j][i]); // 초깃값 설정이 달라서 이런 연산이 가능함.
        else diff -= (a[i][j] + a[j][i]); // diff 라는 변수에 바로 차이를 계산하는 것도 좀 힙함. 나는 따로 따로 구해서 그냥 차이 나중에 구함.
      } // 머리 복잡하면 그냥 나처럼 해도 상관없긴한데 여기까지도 생각할 수 있구나 하고 넘어가면 언젠가는 도움이 될듯.
    }
    ans = min(ans, abs(diff));    
  } while (next_permutation(team.begin(), team.end()));
  cout << ans;
}