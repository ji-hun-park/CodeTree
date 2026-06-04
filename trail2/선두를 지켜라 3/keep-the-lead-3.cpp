// 배열 기록 - 선두를 지켜라3
/* A와 B가 동일한 시작점에서 같은 방향으로 출발
도중에 방향 바뀌는 경우 없음
A와 B가 각각 N, M번에 걸쳐 주어지는 특정 속도(v)로 특정 시간(t)만큼 이동
매 시간마다 선두인 사람 조합 명예의 전당에 등록
명예의 전당 조합이 바뀐 횟수 출력
A와 B의 총 이동 시간은 항상 동일하다고 가정
*/
// N, M (1 - 1000)
// v, t (1 - 1000)
// TL: 1000 ms ML: 80 MiB

#include <iostream>
#include <algorithm>

#define A 1
#define B 2
#define MAX_RANGE 1'000'000

using namespace std;

int Time_Table_A[MAX_RANGE + 1], Time_Table_B[MAX_RANGE + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, cnt = 0;
    cin >> N >> M;

    while(N--)
    {
        int v, t;
        cin >> v >> t;

        while(t--)
        {
            cnt++;
            Time_Table_A[cnt] = Time_Table_A[cnt - 1] + v;
        }
    }

    cnt = 0;

    while(M--)
    {
        int v, t;
        cin >> v >> t;

        while(t--)
        {
            cnt++;
            Time_Table_B[cnt] = Time_Table_B[cnt - 1] + v;
        }
    }

    cnt = 0;

    int before_honor = 0, current_honer = 0;

    for (int i = 1; i <= MAX_RANGE; i++)
    {
        if (Time_Table_A[i] > Time_Table_B[i])
        {
            current_honer = A;
        }
        else if (Time_Table_A[i] < Time_Table_B[i])
        {
            current_honer = B;
        }
        else
        {
            current_honer = A + B;
        }

        if (before_honor != 0 && before_honor != current_honer) cnt++;
        before_honor = current_honer;
    }

    cout << cnt;

    return 0;
}