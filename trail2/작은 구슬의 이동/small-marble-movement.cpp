// dx dy 기술 - 격자에서 방향 전환
/*
벽으로 둘러싸인 N 행 N 열 격자 안에 한 개의 구슬이 놓여져 있음
구슬은 상하좌우 중 특정 방향으로 1초에 한 칸씩 이동
최좌최상 칸을 1행 1열, 최우최하 칸을 N 행 N 열로 정의
구슬이 벽에 부딫히면 움직이는 방향이 뒤집혀 동일한 속도로 움직임
방향을 바꾸는 데에 1 만큼의 시간이 소요됨
구슬의 초기 위치와 방향이 주어졌을 때, T초가 지난 이후에 해당 구슬의 위치를 출력
*/
// 입력: 첫 줄에 두 정수 N과 T가 공백으로 구분
// 두 번째 줄에 구슬의 초기 정보를 나타내는 R, C, D가 공백으로 구분되어 주어짐
// R과 C는 정수로, 초기 구슬이 R행 C열에 놓여 있음을 나타냄
// D는 4 개의 문자(U, D, R, L) 중 하나(위, 아래, 오른쪽, 왼쪽)
// 조건
// N (2 - 50)
// T (1 - 100)
// R, C (1 - N)
// D (U, D, R, L)
// 출력: 첫 줄에 T초 후 구슬이 위치한 격자 칸의 행 번호와 열 번호를 공백으로 구분하여 출력
// TL: 1000 ms, ML: 80 MiB

#include <iostream>

#define DIR_NUM 4
#define MAX_N 50

using namespace std;

// int Matrix[MAX_N + 1][MAX_N + 1];
int dr[DIR_NUM] = {0, -1, 1, 0}, dc[DIR_NUM] = {1, 0, 0, -1};

bool InRange (int r, int c, int n)
{
    return (1 <= r && r <= n && 1 <= c && c <= n);
}

int ctoi (char dir)
{
    if (dir == 'R') return 0;
    else if (dir == 'U') return 1;
    else if (dir == 'D') return 2;
    else return 3;
}

int turn (int dir)
{
    return 3 - dir;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t, r, c, dir;
    char d;

    cin >> n >> t >> r >> c >> d;

    dir = ctoi(d);

    while(t--)
    {
        if (!InRange(r + dr[dir], c + dc[dir], n)) dir = turn(dir);
        else
        {
            r += dr[dir];
            c += dc[dir];
        }
    }

    cout << r << " " << c;

    return 0;
}