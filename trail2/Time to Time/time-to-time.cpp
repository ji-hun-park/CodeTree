#include <iostream>
using namespace std;

int A,B,C,D;
int a,b;

int main() {
    cin >> A >> B >> C >> D;
    a = A * 60 + B;
    b = C * 60 + D;
    cout << b - a;
    return 0;
}