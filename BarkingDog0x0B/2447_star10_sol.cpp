// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : haneulkimdev
// http://boj.kr/338f1dddcb68434fbcf4552bdf7330f7
#include <bits/stdc++.h>
using namespace std;

char board[2300][2300];

// solve(n, x, y) : board[x][y] to board[x+n-1][y+n-1]에 올바르게 '*'과 ' '을 넣는 함수
void solve(int n, int x, int y) {
  if (n == 1) {
    board[x][y] = '*';
    return;
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) { // 9개로 나눈다는걸 이렇게 명확하게 표현하다니.
      if (i == 1 && j == 1) // 9개 중에 가운데는 안 건들임. (정확히는 공백처리 == 메인에서 함.)
        continue;
      solve(n / 3, x + n / 3 * i, y + n / 3 * j); // 9개로 나눈거니까 가로도 3으로 나누고 세로도 3으로 나눴다고 생각하기.
    }
  }
} 

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;  
  for (int i = 0; i < n; i++)
    fill(board[i], board[i]+n, ' ');
  
  solve(n, 0, 0);
  for (int i = 0; i < n; i++)
    cout << board[i] << '\n';
}
/*
board[...][n]에 NULL 대신 ' '이 들어있을 경우 뒤에 불필요한 공백이 추가로 출력될 수 있음. board는 전역 변수이기 때문에
초기 값이 전부 NULL이어서 잘 동작함.
*/