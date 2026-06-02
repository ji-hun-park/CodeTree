#include <iostream>
using namespace std;

#define MAX_X 200
#define MAX_Y 200

int main() {
    int mat[MAX_X+1][MAX_Y+1] = {0, };
    int N, X1, Y1, X2, Y2, R = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> X1 >> Y1 >> X2 >> Y2;
        for (int j = X1 + 100; j < X2 + 100; j++)
        {
            for (int k = Y1 + 100; k < Y2 + 100; k++)
                mat[j][k] = 1;
        }
    }

    for (int i = 0; i <= MAX_X; i++)
    {
        for (int j = 0; j <= MAX_Y; j++)
            if (mat[i][j] == 1)
                R++;
    }

    cout << R;

    return 0;
}