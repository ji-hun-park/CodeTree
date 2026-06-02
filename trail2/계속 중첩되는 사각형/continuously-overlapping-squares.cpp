#include <iostream>

#define MAX_RANGE 200
#define OFFSET 100
#define RED 1
#define BLUE 2

int Mat[MAX_RANGE+1][MAX_RANGE+1];

using namespace std;

int PlusOffset(int num)
{
    return num + OFFSET;
}

int main() {
    // 입출력 속도 향상을 위한 코드
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, X1, X2, Y1, Y2;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> X1 >> Y1 >> X2 >> Y2;

        X1 = PlusOffset(X1);
        X2 = PlusOffset(X2);
        Y1 = PlusOffset(Y1);
        Y2 = PlusOffset(Y2);

        for (int x = X1; x < X2; x++)
        {
            for (int y= Y1; y < Y2; y++)
            {
                if (i % 2 != 0)
                    Mat[x][y] = RED;
                else
                    Mat[x][y] = BLUE;
            }
        }
    }

    int area = 0;

    for (int x = 0; x <= MAX_RANGE; x++)
    {
        for (int y = 0; y <= MAX_RANGE; y++)
            if (Mat[x][y] == BLUE) area++;
    }

    cout << area;

    return 0;
}