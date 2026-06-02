#include <iostream>
using namespace std;

#define MAX_X 2000
#define MAX_Y 2000
#define OFFSET 1000

int Mat[MAX_X+1][MAX_Y+1];

int main() {
    int X1, X2, Y1, Y2;

    // 입출력 속도 향상을 위한 코드
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // A
    cin >> X1 >> Y1 >> X2 >> Y2;
    for (int x = X1 + OFFSET; x < X2 + OFFSET; x++)
    {
        for (int y = Y1 + OFFSET; y < Y2 + OFFSET; y++)
            Mat[x][y] = 1;
    }
    // B
    cin >> X1 >> Y1 >> X2 >> Y2;
    for (int x = X1 + OFFSET; x < X2 + OFFSET; x++)
    {
        for (int y = Y1 + OFFSET; y < Y2 + OFFSET; y++)
            Mat[x][y] = 1;
    }
    // M
    cin >> X1 >> Y1 >> X2 >> Y2;
    for (int x = X1 + OFFSET; x < X2 + OFFSET; x++)
    {
        for (int y = Y1 + OFFSET; y < Y2 + OFFSET; y++)
            Mat[x][y] = 0;
    }

    int cnt = 0;

    for (int x = 0; x <= MAX_X; x++)
    {
        for (int y = 0; y <= MAX_Y; y++)
            if (Mat[x][y] == 1) cnt++;
    }

    cout << cnt;

    return 0;
}