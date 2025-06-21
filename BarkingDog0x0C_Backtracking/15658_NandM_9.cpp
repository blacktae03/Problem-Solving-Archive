#include <bits/stdc++.h>
using namespace std;

// 나 진짜 천잰가 백트래킹으로 풀기 성공함 수고요 님들아 ㅋㅋ

int n, m;
int idx[10];
int isused[10000]; // 숫자가 몇 번 들어갔는지 표시

void func(int k, vector<int> arr) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << idx[i] << ' ';
        cout << '\n';
    }

    for (auto num : arr) {
        if (!isused[num]) continue;
        isused[num]--; // 3번 입력 됐으면 3번 쓸 수 있게 처리함.
        idx[k] = num;
        func(k+1, arr);
        isused[num]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    int tmp;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        arr.push_back(tmp);
        isused[arr[i]]++; // 똑같은 거는 1이상으로 올라감.
    }
    
    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin()); // 정렬 후 같은 숫자 없앤 후, 리사이즈하기.

    func(0, arr);
}