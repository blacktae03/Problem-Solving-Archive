// http://boj.kr/ba53d62b7651443cbf7b2028c28ce197
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dist[100002];
int n,k;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  fill(dist, dist+100001,-1);
  // 시작점과 구분하기 위해 시작점을 제외한 부분을 -1로 해놓는 버릇이 있는 듯.
  // 복잡한 문제일수록 이렇게 하는 버릇을 들이는게 좋은 것 같기도 함.
  // 예를 들면 4179_불! : 나는 길이랑 다 0으로 조졌는데 그랬다가 봉변 당했으니...
  dist[n] = 0;
  queue<int> Q;
  Q.push(n);
  while(dist[k] == -1){
    int cur = Q.front(); Q.pop();
    for(int nxt : {cur-1, cur+1, 2*cur}){
      if(nxt < 0 || nxt > 100000) continue;
      if(dist[nxt] != -1) continue;
      dist[nxt] = dist[cur]+1;
      Q.push(nxt);
    }        
  }
  cout << dist[k];
}