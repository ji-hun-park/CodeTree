#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    int before, after, result;
    // Please write your code here.
    cin >> A >> B >> C;
    before = 10 * 60 * 24 + 11 * 60 + 11;
    after = (A-1) * 60 * 24 + B * 60 + C;
    result = after - before;
    result = result < 0 ? -1 : result;
    cout << result;
    return 0;
}