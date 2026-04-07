// merge sort로 풀어보기.

#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> arr[1000001], tmp[1000001];

void merge_y(int st, int en) {
    int mid = (st+en) / 2;

    int aidx = st, bidx = mid;
    
    for (int i = st; i < en; i++) {
        if (aidx >= mid) tmp[i] = arr[bidx++];
        else if (bidx >= en) tmp[i] = arr[aidx++];
        else tmp[i] = arr[aidx].second <= arr[bidx].second ? arr[aidx++] : arr[bidx++];
    }

    for (int i = st; i < en; i++) arr[i] = tmp[i];
}
void merge_x(int st, int en) {
    int mid = (st+en) / 2;

    int aidx = st, bidx = mid;
    
    for (int i = st; i < en; i++) {
        if (aidx >= mid) tmp[i] = arr[bidx++];
        else if (bidx >= en) tmp[i] = arr[aidx++];
        else tmp[i] = arr[aidx].first <= arr[bidx].first ? arr[aidx++] : arr[bidx++];
    }

    for (int i = st; i < en; i++) arr[i] = tmp[i];
}

void merge_sort_x(int st, int en) {
    if (en-st <= 1) return;

    int mid = (st+en) / 2;
    merge_sort_x(st, mid);
    merge_sort_x(mid, en);
    merge_x(st, en);
}
void merge_sort_y(int st, int en) {
    if (en-st <= 1) return;

    int mid = (st+en) / 2;
    merge_sort_y(st, mid);
    merge_sort_y(mid, en);
    merge_y(st, en);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
    
    merge_sort_y(0, N);
    merge_sort_x(0, N);

    for (int i = 0; i < N; i++) cout << arr[i].first << ' ' << arr[i].second << '\n';
}