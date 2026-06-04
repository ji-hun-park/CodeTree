// dx, dy 기술 - 문자에 따른 명령2
/*
(0, 0)에서 북쪽을 향한 상태로 시작
N개의 명령에 따라 총 N번 움직임
명령 L이 주어지면 왼쪽으로 90도 방향 전환
명령 R이 주어지면 오른쪽으로 90도 방향 전환
명령 F가 주어지면 바라보고 있는 방향으로 한 칸 이동
최종 위치를 출력
*/
// 입력: 문자(L, R, F)로 이루어진 문자열 하나
// 명령의 길이(1 - 100000)
// Time Limit: 1000 ms, Memory Limit: 80 MiB

#include <iostream>
#include <string>

#define DIRECTION 4

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x = 0, y = 0, dir = 0;
    int dx[DIRECTION] = {0, 1, 0, -1}, dy[DIRECTION] = {1, 0, -1, 0}; // 북부터 시계방향
    string command;

    cin >> command;

    for (int i = 0; i < command.length(); i++)
    {
        if (command[i] == 'R') dir = (dir + 1) % 4;
        else if (command[i] == 'L') dir = (dir - 1 + 4) % 4;
        else
        {
            x += dx[dir];
            y += dy[dir];
        }
    }

    cout << x << " " << y;

    return 0;
}