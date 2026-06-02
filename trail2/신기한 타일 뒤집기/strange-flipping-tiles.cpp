#include <iostream>
using namespace std;

#define MAX_RANGE 100000
#define MAX_N 1000
#define MAX_X 100

int main() {
    int N, W = 0, B = 0, cur = MAX_RANGE;
    int line[MAX_RANGE * 2 + 1] = {0,};
    int move[MAX_N] = {0, };
    char direction[MAX_N];

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> move[i] >> direction[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < move[i]; j++)
        {
            if (direction[i] == 'L')
            {
                line[cur] = -1;
                if (j != move[i] - 1) cur--;
            }
            else
            {
                line[cur] = 1;
                if (j != move[i] - 1) cur++;
            }
        }
    }

    for (int i = 0; i < MAX_RANGE * 2 + 1; i++)
    {
        if (line[i] == -1) W++;
        else if (line[i] == 1) B++;
    }

    cout << W << " " << B;

    return 0;
}