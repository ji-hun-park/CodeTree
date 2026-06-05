// dx dy 테크닉 - 1이 3개 이상 있는 위치
/* 격자 dx, dy 활용
숫자 0과 1로만 이루어진 N X N 행렬이 주어짐
각 칸 중 상하좌우 인접한 칸 중 숫자 1이 적혀 있는 칸의 수가 3개 이상인 곳의 개수를 세기
인접한 곳이 격자를 벗어나는 경우에는 숫자 1이 적혀있지 않은 것으로 간주
*/
// 입력: N이 주어지고 N개 줄에 걸쳐 N개의 숫자가 공백을 사이에 두고 주어짐
// 전부 0과 1로 이루어져 있다고 가정
// N (1 - 100)
// 출력: 인접한 칸에 숫자 1이 3개 이상 적혀있는 서로 다른 칸의 수
// TL: 1000 ms, ML: 80 MiB

#include <iostream>

#define MAX_N 100
#define DIR_NUM 4
#define COUNT 3

using namespace std;

int Matrix[MAX_N+1][MAX_N+1];

bool InRange(int i, int j, int n)
{
    return (0 <= i && i <= n && 0 <= j && j <= n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 0, over3 = 0;
    int di[DIR_NUM] = {0, 1, 0, -1}, dj[DIR_NUM] = {1, 0, -1, 0};

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cin >> Matrix[i][j];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int cnt = 0;
            for (int k = 0; k < DIR_NUM; k++)
            {
                if (InRange(i + di[k], j + dj[k], N))
                {
                    if (Matrix[i + di[k]][j + dj[k]] == 1) cnt++;
                }
            }
            if (cnt >= COUNT) over3++;
        }
    }

    cout << over3;

    return 0;
}