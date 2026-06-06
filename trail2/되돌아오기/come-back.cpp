#include <iostream>
using namespace std;

#define DIR_NUM

int ctoi(char dir)
{
    if (dir == 'E') return 0;
    else if (dir == 'W') return 1;
    else if (dir == 'S') return 2;
    else return 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();

    bool flag = false;
    int N = 0, d = 0, x = 0, y = 0, cnt = 0, ans = 0;
    int dx[DIR_NUM] = {1, -1, 0, 0}, dy[DIR_NUM] = {0, 0, 1, -1}; // E, W, S, N
    char c_dir;

    cin >> N;

    while(N--)
    {
        cin >> c_dir >> d;
        while(d--)
        {
            x += dx[ctoi(c_dir)];
            y += dy[ctoi(c_dir)];
            cnt++;
            if (x == 0 && y == 0)
            {
                ans = cnt;
                flag = true;
                break;
            }
        }
        if (flag) break;
    }

    if (!flag) ans = -1;

    cout << ans;

    return 0;
}