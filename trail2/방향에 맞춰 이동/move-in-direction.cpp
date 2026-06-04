// dx, dy 테크닉 - 방향에 맞춰 이동
/*
(0, 0)에서 시작해 총 N번 이동
N번에 걸쳐 움직이려는 방향(W,S,N,E)과 움직일 거리(INT)가 주어짐
*/
// N (1 - 100)
// 한 번 이동 거리 (1 - 10)
// TL: 1000 ms, ML: 80 MiB

#include <iostream>

#define DIRECTION 4

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0, x = 0, y = 0, range;
    char dir_num;
    int dx[DIRECTION] = {-1, 0, 0, 1}, dy[DIRECTION] = {0, -1, 1, 0}; // W, S, N, E

    cin >> n;
    while(n--)
    {
        cin >> dir_num >> range;
        switch (dir_num)
        {
            case 'W':
                x = x + dx[0] * range;
                y = y + dy[0] * range;
                break;
            case 'S':
                x = x + dx[1] * range;
                y = y + dy[1] * range;
                break;
            case 'N':
                x = x + dx[2] * range;
                y = y + dy[2] * range;
                break;
            case 'E':
                x = x + dx[3] * range;
                y = y + dy[3] * range;
                break;
            default:
                break;
        }
    }

    cout << x << " " << y;

    return 0;
}