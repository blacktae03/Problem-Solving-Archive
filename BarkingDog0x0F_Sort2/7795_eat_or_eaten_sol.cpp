// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/c8698bc57ac343dea8f836660aecc0b4
// 아니 뇌가 굳었나 이렇게 하면 훨씬 편한데 이런이런..
// 큰게 작은걸 먹는다고 해서 내림차순으로 정렬하라는 보장이 없음. 그냥 반대로 정렬하는 건 어떨까? 하고 한 번만 더 생각해 보도록 하자.

#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> v(n+m);
    for(int i = 0; i < n; i++){
      int a;
      cin >> a;
      v[i] = {a, 0};
    }
    for(int i = n; i < n+m; i++){
      int b;
      cin >> b;
      v[i] = {b, 1};
    }
    sort(v.begin(), v.end());
    int cnt = 0; // 현재까지 나온 b의 개수
    int ans = 0;
    for(int i = 0; i < n+m; i++){
      if(v[i].second == 0) // 현재 보는 수가 A에 속한 수
        ans += cnt;
      else // 현재 보는 수가 B에 속한 수
        cnt++;
    }
    cout << ans << '\n';
  }
}