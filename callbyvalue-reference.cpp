#include <iostream>
using namespace std;

void swapValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
    cout << "After swap: a = " << x << " b = " << y << endl;
}

void swapReference(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 40;
    int b = 50;
    cout << "Before swap: a = " << a << " b = " << b << endl;
    swapValue(a, b);

    cout << endl;

    int x = 5;
    int y = 10;
    cout << "Before swap: x = " << x << " , y = " << y << endl;
    swapReference(&x, &y);
    cout << "After swap: x = " << x << " , y = " << y << endl;

    return 0;
}