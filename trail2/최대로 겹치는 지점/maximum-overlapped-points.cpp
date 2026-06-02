#include <iostream>
using namespace std;

#define MAX_N 100

int main() {
    int N, MAX = 0;
    int x1[MAX_N], x2[MAX_N];
    int line[MAX_N] = {0, };

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x1[i] >> x2[i];
        x1[i] -= 1;
        x2[i] -= 1;
    }

    for (int i = 0; i < N; i++)
        for (int j = x1[i]; j <= x2[i]; j++)
            line[j]++;
    
    for (int i = 0; i < MAX_N; i++)
        if (line[i] > MAX) MAX = line[i];

    cout << MAX;

    return 0;
}