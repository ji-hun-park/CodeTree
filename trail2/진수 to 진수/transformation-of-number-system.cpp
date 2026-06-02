#include <iostream>
#include <string>
using namespace std;

int main() {
    int A, B, cnt = 0, result = 0;
    int seq[20] = {};
    string N;
    
    cin >> A >> B >> N;

    for (int i = 0; i < (int)N.size(); i++)
        result = result * A + (N[i] - '0');
    
    while(true)
    {
        if (result < B)
        {
            seq[cnt++] = result;
            break;
        }
        seq[cnt++] = result % B;
        result /= B;
    }

    for (int i = cnt - 1; i >=0; i--)
        cout << seq[i];

    return 0;
}