#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[8] = {6, -8, 1, 12, 8, 3, 7, -7};
    int pvt = 0, l = 1, r = 7;
    bool stop = 1;

    while(l <= r) {
        stop = 1;
        if (arr[l] < arr[pvt]) {l++; stop = 0;}
        if (arr[r] > arr[pvt]) {r--; stop = 0;}
        if (stop) swap(arr[l], arr[r]);
    }

    swap(arr[pvt], arr[r]);
    
    for (int i = 0; i < 8; i++) cout << arr[i] << ' ';
}