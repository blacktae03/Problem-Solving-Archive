// merge sort로 풀어보기.

#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1000001], tmp[1000001];

void merge(int st, int en) {
    int mid = (st+en) / 2;

    int aidx = st, bidx = mid;

    for (int i = st; i < en; i++) {
        if (aidx >= mid) tmp[i] = arr[bidx++];
        else if (bidx >= en) tmp[i] = arr[aidx++];
        else tmp[i] = arr[aidx] < arr[bidx] ? arr[aidx++] : arr[bidx++];
    }

    for (int i = st; i < en; i++) arr[i] = tmp[i];
}

void merge_sort(int st, int en) {
    if (en-st <= 1) return;

    int mid = (st+en) / 2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    merge_sort(0, N);
    for (int i = 0; i < N; i++) cout << arr[i] << '\n';
}