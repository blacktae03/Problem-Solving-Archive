// quick sort로 짜보기
#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1001];

void quick_sort(int st, int en) {
    if (en - st <= 1) return;

    int pivot = arr[st];
    int l = st+1;
    int r = en-1;
    bool stop;

    while(l <= r) {
        stop = 1;
        if (arr[l] < pivot) {l++; stop = 0;}
        if (arr[r] > pivot) {r--; stop = 0;}
        if (stop) swap(arr[l], arr[r]);
    }

    swap(arr[st], arr[r]);
    quick_sort(st, r);
    quick_sort(l, en);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    quick_sort(0, N);
    
    for (int i = 0; i < N; i++) cout << arr[i] << '\n';
    
}