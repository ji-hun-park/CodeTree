#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int bin[20] = {};
    int cnt = 0;
    // Please write your code here.
    while(true)
    {
        if (N < 2)
        {
            bin[cnt++] = N;
            break;
        }
        bin[cnt++] = N % 2;
        N /= 2;
    }
    for(int i = cnt -1; i >= 0; i--)
        cout << bin[i];
    return 0;
}