// Authored by : yongjunleeme
// Co-authored by : -
// http://boj.kr/dd570a33a8e14e778224bb499a015ca3
// 와 진짜 똑똑하다.. 이런 생각을 하려면 어떻게 해야할까.. 흠 방향을 기록하고 시작점에서부터 그 방향대로 확장하는 생각을 어떻게하지
// 어떻게 보면 그냥 문제의 지시를 따라간 것 뿐인데 문제를 조금 더 오래 들여다 볼 필요가 있을지도
#include <bits/stdc++.h>
using namespace std;

int n, x, y, d, g;
int board[105][105];
int cnt = 0;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  while(n--){
    cin >> x >> y >> d >> g;

    vector<int> v;
    v.push_back(d%4);
    board[y][x] = 1;

    while(g--){
      int vSize = v.size();
      // 세대가 증가할 때마다 기존 세대의 방향(숫자)을 뒤에서부터 1을 더한 방향(숫자)을 추가
      // 0: 0
      // 1: 0, 1
      // 2: 0, 1, 2, 1
      // 3: 0, 1, 2, 1, 2, 3, 2, 1
      for(int j = vSize-1; j >= 0; j--)
        v.push_back((v[j]+1)%4);
    }

    for(int i = 0; i < v.size(); i++){
      int dir = v[i];
      if(dir == 0) x++;
      else if(dir == 1) y--;
      else if(dir == 2) x--;
      else if(dir == 3) y++;
      board[y][x] = 1;
    }
  }

  for(int i = 0; i < 100; i++){
    for(int j = 0; j < 100; j++){
      if(!board[i][j]) continue;
      if(board[i+1][j] && board[i][j+1] && board[i+1][j+1]) cnt++;
    }
  }
  cout << cnt;
}