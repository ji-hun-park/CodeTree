#include <iostream>
#include <string>
using namespace std;

int main() {
    string N;
    int result = 0, cnt = 0;
    int bin[20] = {};
    cin >> N;

    for (int i = 0; i < (int)N.size(); i++)
    {
        result = result * 2 + (N[i] - '0');
    }

    result *= 17;

    while(true)
    {
        if(result < 2)
        {
            bin[cnt++] = result;
            break;
        }
        bin[cnt++] = result % 2;
        result /= 2;
    }

    for (int i = cnt - 1; i >= 0; i--)
        cout << bin[i];

    return 0;
}