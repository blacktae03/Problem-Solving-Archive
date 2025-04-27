#include <iostream>
using namespace std;

int top = -1;

void push(int * arr, int num);
void pop(int * arr);
void size();
void empty();
void ftop(int * arr);

int main() {
    int N;
    int arr[10000];
    int num;
    string com = "";
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> com;
        
        if(com == "push") {
            cin >> num;
            push(arr, num);
        }

        else if(com == "pop") {
            pop(arr);
        }

        else if(com == "size") {
            size();
        }

        else if(com == "empty") {
            empty();
        }

        else if(com == "top") {
            ftop(arr);
        }
    }

    return 0;
}

void push(int * arr, int num) {
    *(arr+(++top)) = num;
}

void pop(int * arr) {
    if (top >= 0)
        cout << *(arr+(top--)) << endl;

    else
        cout << top << endl;
}

void size() {
    cout << top+1 << endl;
}

void empty() {
    if (top < 0)
        cout << 1 << endl;

    else
        cout << 0 << endl;
}

void ftop(int * arr) {
    if(top < 0)
        cout << top << endl;

    else
        cout << *(arr+top) << endl;
}