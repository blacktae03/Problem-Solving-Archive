#include <bits/stdc++.h>
using namespace std;

int n;
long long d[12], arr[1000001], tmp[1000001];
vector<long long> l[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> tmp[i];

    
    // d[11] = 1;
    // for (int i = 10; i >= 0; i--) d[i] = d[i+1] * 10;
    d[0] = 1;
    for (int i = 1; i < 12; i++) d[i] = d[i-1] * 10;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 12; j++) {
            int digit = tmp[i] / d[j] % 10;
            // if (!digit) continue;
            arr[i] = arr[i] * 10 + digit;
        }
    }
    
    for (int i = 0; i < n; i++) {
        while(!(arr[i] % 10)) arr[i] /= 10;
    }

    // 일반적인 radix sort 를 생각했을 때 1의 자리부터 비교해서 오름차순으로 정렬한 후 10의 자리 -> 100의 자리 ...
    // 거꾸로니까 10^11의 자리부터 비교해서 오름차순으로 정렬 -> 10^10의 자리 -> 10^9의 자리 ... 로 하면 거꾸로 돌린 것의 정렬 순서랑 같게 됨.
    // 근데 숫자를 거꾸로 표현해야한다는게 크랙인데.. 그걸 어캐할지 생각해보자.
    for (int i = 0; i < 12; i++) {
        int idx = 0;

        for (int j = 0; j < n; j++) {
            l[arr[j] / d[i] % 10].push_back(arr[j]);
        }
        
        for (int j = 0; j < 10; j++) {
            for (auto num : l[j]) arr[idx++] = num;
            l[j].clear();
        }
    }

    for (int i = 0; i < n; i++) cout << arr[i] << '\n';
}