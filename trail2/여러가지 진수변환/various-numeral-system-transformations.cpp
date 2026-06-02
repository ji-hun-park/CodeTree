#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, B, des = 0, cnt = 0;
    int result[20] = {};
    cin >> N >> B;
    while(true)
    {
        if(N < B)
        {
            result[cnt++] = N;
            break;
        }
        result[cnt++] = N % B;
        N /= B;
    }
    // Please write your code here.
    for (int i = cnt - 1; i >= 0; i--)
        cout << result[i];
    return 0;
}