// dx dy 기술 - 되돌아오기 2
/*
좌표평면 위 (0, 0)에서 북쪽을 향한 상태에서 움직이는 것을 시작
N개의 명령에 따라 총 N번 움직임
명령 L이 주어지면 왼쪽으로 90도 방향 전환, 명령 R이 주어지면 오른쪽으로 90도 방향 전환을 함
명령 F가 주어지면 바라보고 있는 방향으로 한 칸 이동
1초에 한 칸씩 움직이며, 회전에도 1초의 시간이 걸림
몇 초 뒤에 처음응로 다시 (0, 0)에 돌아오게 되는지 판단하는 프로그램 작성
*/
// 입력: 첫 번째 줄에 문자 L, R, F로만 이루어진 문자열 형태의 명령이 주어짐
// 조건:
// 명령의 길이 (1 - 100'000)
// 명령 = {L, R, F}
// 첫 명령은 항상 F로 주어짐
// 출력: 첫 번째 줄에 다시 시작점으로 되돌아오는 데 걸리는 시간 출력
// 만약 N번 이동했는데 시작점으로 돌아오지 못하면 -1을 출력
// 제한: TL: 1000 ms / ML: 80 MiB

#include <iostream>
#include <string>

#define DIR_NUM 4

using namespace std;

int x = 0, y = 0, dir = 0;
int dx[DIR_NUM] = {0, 1, 0, -1}, dy[DIR_NUM] = {1, 0, -1, 0};

int Command_Run (string command)
{
    int cnt = 0;
    bool flag = false;

    for (int n = 0; n < (int)command.size(); n++)
    {
        cnt++;
        if (command[n] == 'F')
        {
            x += dx[dir];
            y += dy[dir];
            if (x == 0 && y == 0)
            {
                flag = true;
                break;
            }
        }
        else if (command[n] == 'R')
        {
            dir = (dir + 1) % 4;
        }
        else if (command[n] == 'L')
        {
            dir = (dir + 3) % 4;
        }
    }
    if (!flag) cnt = -1;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string command;

    cin >> command;

    cout << Command_Run(command);

    return 0;
}