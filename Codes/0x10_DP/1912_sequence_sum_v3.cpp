#include <bits/stdc++.h>
using namespace std;

int n;
int nums[100002], D[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;
    int cut = 0;
    
    fill(D, D+100002, -10000);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        sum += nums[i];
        D[i] = sum;
        // D[1] = max(D[i], sum); // D[i]는 수의 개수가 i개인 연속합의 최댓값
    }

    for (int i = 2; i <= n; i++) {
        D[i] = max(D[i], D[i-1] - nums[i-1]);
    }

    cout << *max_element(D, D+100002);
}