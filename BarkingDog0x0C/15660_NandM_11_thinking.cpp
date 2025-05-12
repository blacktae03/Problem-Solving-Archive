#include <bits/stdc++.h>
using namespace std;

// 나 진짜 천잰가 백트래킹으로 풀기 성공함 수고요 님들아 ㅋㅋ

int n, m;
int idx[10];
vector<int> arr;


void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << idx[i] << ' ';
        cout << '\n';
        return;
    }

    for (auto num : arr) {
        idx[k] = num;
        func(k+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    int tmp;
    
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        arr.push_back(tmp);
    }
    
    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin()); // 정렬 후 같은 숫자 없앤 후, 리사이즈하기.

    func(0);
}