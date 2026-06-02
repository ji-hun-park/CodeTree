#include <iostream>
using namespace std;

#define MAX_AREA 2000
#define OFFSET 1000

int Mat[MAX_AREA+1][MAX_AREA+1];

int PlusOffset(int num)
{
    return num + OFFSET;
}

int main() {
    // 입출력 속도 향상을 위한 코드
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int X1, X2, Y1, Y2;
    int MaxX = 0, MaxY = 0, MinX = MAX_AREA + 1, MinY = MAX_AREA + 1;

    // 첫 번째 직사각형 채우기
    cin >> X1 >> Y1 >> X2 >> Y2;
    X1 = PlusOffset(X1);
    X2 = PlusOffset(X2);
    Y1 = PlusOffset(Y1);
    Y2 = PlusOffset(Y2);

    for (int x = X1; x < X2; x++)
    {
        for (int y = Y1; y < Y2; y++)
            Mat[x][y] = 1;
    }

    // 두 번째 직사각형 지우기
    cin >> X1 >> Y1 >> X2 >> Y2;
    X1 = PlusOffset(X1);
    X2 = PlusOffset(X2);
    Y1 = PlusOffset(Y1);
    Y2 = PlusOffset(Y2);

    for (int x = X1; x < X2; x++)
    {
        for (int y = Y1; y < Y2; y++)
            Mat[x][y] = 0;
    }

    // 최대 최소 찾기
    for (int x = 0; x <= MAX_AREA; x++)
    {
        for (int y = 0; y <= MAX_AREA; y++)
        {
            if (Mat[x][y] == 1)
            {
                if (x < MinX) MinX = x;
                if (x > MaxX) MaxX = x;
                if (y < MinY) MinY = y;
                if (y > MaxY) MaxY = y;
            }
        }
    }

    int area;
    
    if (MinX == MAX_AREA + 1) 
    {
        area = 0;
    }
    else
    {
        area = (MaxX - MinX + 1) * (MaxY - MinY + 1);
    }
    cout << area;

    return 0;
}