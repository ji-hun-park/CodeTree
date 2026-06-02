#include <iostream>
using namespace std;

#define MAX_RANGE 200
#define OFFSET 100

int Mat[MAX_RANGE+1][MAX_RANGE+1];

int main() {
    // 입출력 속도 향상을 위한 코드
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Please write your code here.
    int X, Y, N;

    cin >> N;

    // 색종이 붙이기
    for (int i = 0; i < N; i++)
    {
        cin >> X >> Y;

        X += OFFSET;
        Y += OFFSET;

        for (int x = X; x < X + 8; x++)
        {
            for (int y = Y - 8; y < Y; y++)
                Mat[x][y] = 1;
        }
    }

    // 색종이 넓이 구하기
    int cnt = 0;
    for (int i = 0; i <= MAX_RANGE; i++)
    {
        for (int j = 0; j <= MAX_RANGE; j++)
            if (Mat[i][j] == 1) cnt++;
    }

    cout << cnt;

    return 0;
}