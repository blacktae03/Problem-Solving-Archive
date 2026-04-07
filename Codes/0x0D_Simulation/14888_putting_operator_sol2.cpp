// Authored by : yongjunleeme
// Co-authored by : -
// http://boj.kr/39fbaf3d33204fb08439ebc26dff6ba4
// 원초적인 백트래킹을 사용한 풀이
// 깔끔하고 이쁜듯. cal[i]--, cal[i]++ 부분을 생각하기가 좀 빡셌을 거라는 느낌이 듦. 잘 배워감.
#include <bits/stdc++.h>
using namespace std;

int n;
int num[102];
int cal[4];
int mx = -0x7f7f7f7f;
int mn = 0x7f7f7f7f;

void func(int ans, int k){
  if(k == n){
    mx = max(mx, ans);
    mn = min(mn, ans);
    return;
  }

  for(int i = 0; i < 4; i++){
    if(!cal[i]) continue;
    cal[i]--;
    if(i == 0) func(ans + num[k], k+1);
    else if(i == 1) func(ans - num[k], k+1);
    else if(i == 2) func(ans * num[k], k+1);
    else if(i == 3) func(ans / num[k], k+1);
    cal[i]++;
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> num[i];
  for(int i = 0; i < 4; i++) cin >> cal[i];
  func(num[0], 1);
  cout << mx << '\n' << mn << '\n';
}