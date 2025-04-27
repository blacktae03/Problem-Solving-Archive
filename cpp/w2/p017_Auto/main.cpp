// auto is legendary
#include <iostream>
#include <memory>
using namespace std;

auto sum(int a, int b) {
    return tuple{"sum: ", a + b};
}

int main() {
    auto pa = make_unique<int>(1);
    auto pb = make_unique<int>(2);

    cout << *pa << ", " << *pb << endl;

    auto my_swap = [](auto a, auto b) {auto temp = *a; *a = *b; *b = temp;};
    my_swap(pa.get(), pb.get());
    cout << "a: " << *pa << ", b: " << *pb << endl;

    auto [label, result] = sum(*pa, *pb); // What name of this variable
    cout << label << result << endl;

    return 0;
}