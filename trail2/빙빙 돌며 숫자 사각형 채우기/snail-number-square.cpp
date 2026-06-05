// dx dy 테크닉 심화 - 빙빙 돌며 숫자 사각형 채우기(달팽이 모양 채우기)
/*
N X M 크기의 직사각형에 수 1부터 순서대로 증가시키며 채우기
왼쪽 위 모서리에서 시작해서, 오른쪽, 아래쪽, 왼쪽, 위쪽 순서로 더 이상 채울 곳이 없을 때까지
회전하는 모양으로 채우기
N은 행, M은 열
*/
// 입력: N과 M이 공백을 사이에 두고 주어짐
// 조건
// N, M (1 - 100)
// 출력: 수들로 채워진 완성된 형태의 N X M 크기의 사각형을 출력(수 사이 공백으로 구분)
// 제한: Time Limit: 1000 ms, Memory Limit: 80 MiB

#include <iostream>

#define MAX_N 100
#define MAX_M 100
#define DIR_NUM 4

using namespace std;

int Matrix[MAX_N][MAX_M];
int dr[DIR_NUM] = {0, 1, 0, -1}, dc[DIR_NUM] = {1, 0, -1, 0};

bool InRange (int n, int m, int N, int M)
{
    return (0 <= n && n < N && 0 <= m && m < M);
}

int Turn (int dir)
{
    return (dir + 1) % 4;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 0, M = 0, x = 0, y = 0, dir = 0;
    cin >> N >> M;

    Matrix[x][y] = 1;

    for (int i = 2; i <= N * M; i++)
    {
        int nx, ny;
        nx = x + dr[dir];
        ny = y + dc[dir];
        if (!InRange(nx, ny, N, M) || Matrix[nx][ny] != 0) dir =  Turn(dir);
        x = x + dr[dir];
        y = y + dc[dir];
        Matrix[x][y] = i;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << Matrix[i][j];
            if (j != MAX_M - 1) cout << " ";
        }
        if (i != MAX_N - 1) cout << '\n';
    }

    return 0;
}