#include <iostream>
using namespace std;

int main() {
    int N, MAX = 0;
    int x1[100], x2[100];
    int line[201] = {0, };
    cin >> N;
    
    for (int i = 0; i < N; i++)
        cin >> x1[i] >> x2[i];

    for (int i = 0; i < N; i++)
        for (int j = x1[i] + 100; j < x2[i] + 100; j++)
            line[j]++;

    for (int i = 0; i < 201; i++)
        if (line[i] > MAX) MAX = line[i];
    
    cout << MAX;
    return 0;
}