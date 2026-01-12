// Authored by : heheHwang
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/c26933e668ff4856874db1108942533c
// 답 보기 전에 풀었으나 참고용
#include <bits/stdc++.h>
using namespace std;

string op;
int N, L, P, G, x;
pair<int, int> probLevel[100'002]; // 문제의 (난이도, 분류) 저장 == 내 코드의 SPLG
// 이거는 근데 이렇게 하는게 훨씬 간편하고 좋은게 뭐냐면 번호를 어차피 tuple의 맨 앞에 내세워서 정렬 시킬 바에는 어차피 모든 문제는 번호가 다르니까 이렇게 하는게 더 심플하고 좋을 듯.
set<int> probByL[102];  // 난이도별로 문제 저장 근데 이렇게 해서 for문 쓸 바엔 나처럼 해서 lower_bound 쓰는 것도 ㄱㅊ은듯
set<int> probByGL[102][102];  // (분류, 난이도) 별로 문제 저장

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  while (N--) {
    cin >> P >> L >> G;
    probLevel[P] = {L, G};
    probByL[L].insert(P);
    probByGL[G][L].insert(P);
  }
  cin >> N;
  while (N--) {
    cin >> op;
    if (op == "recommend") {
      cin >> G >> x;
      if (x == 1) {
        for (int i = 100; i >= 0; i--) {
          if (probByGL[G][i].empty()) continue;
          cout << *(prev(probByGL[G][i].end())) << '\n';
          break;
        }
      } else {
        for (int i = 0; i < 101; i++) {
          if (probByGL[G][i].empty()) continue;
          cout << *probByGL[G][i].begin() << '\n';
          break;
        }
      }
    }
    
    else if(op == "recommend2"){
      cin >> x;
        if (x == 1) {
        for (int i = 100; i >= 0; i--) {
          if (probByL[i].empty()) continue;
          cout << *(prev(probByL[i].end())) << '\n';
          break;
        }
      } else {
        for (int i = 0; i < 101; i++) {
          if (probByL[i].empty()) continue;
          cout << *probByL[i].begin() << '\n';
          break;
        }
      }
    }

    else if(op == "recommend3"){
      cin >> x >> L;
      int ans = -1;
      if(x == 1){
        for(int i = L; i < 101; i++){
          if(probByL[i].empty()) continue;
          ans = *probByL[i].begin();
          break;
        }
      }
      else{
        for(int i = L-1; i >= 0; i--){
          if(probByL[i].empty()) continue;
          ans = *(prev(probByL[i].end()));
          break;
        }
      }
      cout << ans << '\n';
    }
    
    else if (op == "add") {
      cin >> P >> L >> G;
      probLevel[P] = {L, G};
      probByL[L].insert(P);
      probByGL[G][L].insert(P);
    }
    
    else if (op == "solved") {
      cin >> P;
      tie(L, G) = probLevel[P];
      probByL[L].erase(P);
      probByGL[G][L].erase(P);
    }
  }
}