#include <iostream>
using namespace std;

int top = 0;
string buf = "";

void push(int * arr, int num);
void pop(int * arr);

int main() {
    int N, tmp;
    int arr[100001] = {0,};
    int ntop = 0;
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tmp;

        while(buf != "NO" && arr[top] < tmp) push(arr, ++ntop);
        if (arr[top] > tmp) buf = "NO";
        if (buf != "NO") pop(arr);
    }

    cout << buf;

    return 0;
}

void push(int * arr, int num) {
    *(arr+(++top)) = num;
    buf += "+\n";
}

void pop(int * arr) {
    top--;
    buf += "-\n";
}