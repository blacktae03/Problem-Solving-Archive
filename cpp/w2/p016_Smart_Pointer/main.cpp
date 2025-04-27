// Hold this problem
#include <iostream>
#include <memory>
using namespace std;

void update (int * a, int * b);

int main() {
    unique_ptr<int> pa {new int{}};
    auto pb = unique_ptr<int> {new int{}}; // same sentence

    cin >> *pa >> *pb;

    update(pa.get(), pb.get()); // Do not forget

    cout << *pa << endl;
    cout << *pb << endl;

    return 0;
}

void update (int * a, int * b) {
    int tmp = *a;
    *a += *b;
    *b = tmp - *b;
}