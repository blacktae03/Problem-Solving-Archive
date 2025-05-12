// Authored by : connieya
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/8c038985c8d24ae2a79aa5288f5f4ee3
#include <bits/stdc++.h>
using namespace std;
// 아 ... 나는 별 지222랄을 다 했는데 레전드 발상이네... 이 함수 자체를 엄청나게 잘 이해해야 이런 발상이 가능할 듯.

int n, m;
int arr[10];
int num[10];
bool isused[10];

void func(int k) { // 현재 k개까지 수를 택했음.
  if (k == m) {
    for (int i = 0; i < m; ++i) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }
  int tmp = 0;  // 중복 수열인지 확인 하기 위해 필요한 임시 변수
  for (int i = 0; i < n; ++i) {
    if (!isused[i] && tmp != num[i]){ // 이전 수열의 마지막 항과 새로운 수열의 마지막 항이 같으면 중복 수열
        // 오름차순으로 정렬되어 있기에 또 가능한 거긴 함. 그냥 레전드 발상인 듯........ 똑똑하다....
      isused[i] = true;
      arr[k] = num[i];
      tmp = arr[k];
      func(k + 1);
      isused[i] = false;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> num[i];
  sort(num, num + n);
  func(0);
}