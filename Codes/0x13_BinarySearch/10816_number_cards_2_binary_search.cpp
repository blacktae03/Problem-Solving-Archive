#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[500050];

int startBinarySearch(int num) {
    int st = 0, en = N;
    int mid = (st+en)/2;

    while (st != en) {
        if (num > A[mid]) st = mid+1;
        else en = mid;
        mid = (st+en)/2;
    }

    return mid;
}

int endBinarySearch(int num) {
    int st = 0, en = N;
    int mid = (st+en)/2;

    while (st != en) {
        if (num >= A[mid]) st = mid+1;
        else en = mid;
        mid = (st+en)/2;
    }

    return mid;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N);
    cin >> M;

    while(M--) {
        int tmp; cin >> tmp;
        cout << endBinarySearch(tmp) - startBinarySearch(tmp) << ' ';
    }
}