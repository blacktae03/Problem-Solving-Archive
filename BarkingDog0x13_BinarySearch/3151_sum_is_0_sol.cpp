// Authored by : SciEm
// Co-authored by : -
// http://boj.kr/b830d64c3ecd434ba3e554cc709dba3e
// 아니 왤캐 쉽게 푸는거야?
// 근데 이건 내가 수학적 지식이 부족한 듯. 어쨋든 3개를 고르는 조합이라서 j보다 큰 거에서 찾는 규칙으로 하면 겹칠 일이 없는데...
// i랑 j값을 정하는 기준은 조합이니까 안겹치면 되지 하고 j = i+1 이지랄 하면서 왜 k를 j+1 하는 생각을 안하냐는 거지 이 병2신새2끼야
#include <bits/stdc++.h>
using namespace std;

int n;
int a[10002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);

  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      auto ub = upper_bound(a + j + 1, a + n, -a[i] - a[j]);
      auto lb = lower_bound(a + j + 1, a + n, -a[i] - a[j]);
      ans += ub - lb;
    }
  }
  cout << ans;
}
/*
두 명을 선택하고 나머지 한 명을 이분탐색으로 찾되 여러 개 있는 경우를
고려하여 upper_bound와 lower_bound를 이용한다.
*/