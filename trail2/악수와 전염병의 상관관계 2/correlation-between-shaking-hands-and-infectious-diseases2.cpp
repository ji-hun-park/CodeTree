// 감염자를 찾는 문제
/* 악수를 통해 전염시키며, 전염된 자는 추가 전염 가능
모든 악수를 진행한 이후 최종적으로 전염병에 걸린 사람 찾기
전염된 자들끼리 악수도 횟수 차감
t와 x와 y는 중복 없음
*/
// N은 개발자들의 수 (2 - 100)
// K는 악수로 점염시킬 수 있는 횟수 (1 - 250)
// P는 최초 감염자 (1 - N)
// T는 악수 이벤트 발생 횟수 (1 - 250)
// t는 이벤트 발생 시간 (1 - 250)
// x와 y는 악수한 개발자들 (1 - 100)
// 출력은 모든 개발자들 감염 정보 (0은 음성, 1은 양성)
// TM: 1000 ms / ML: 80 MiB

#include <iostream>
#include <algorithm>

#define CAPACITY 100
#define TIME_TABLE 250

using namespace std;

struct developer
{
    bool is_infection = false;
    int infection_count = 0;
};

struct developer developers[CAPACITY + 1];

pair<int, int> tt[TIME_TABLE + 1];

int main() {
    for (int i = 0; i < TIME_TABLE + 1; i++)
    {
        tt[i].first = 500;
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, P, T;
    cin >> N >> K >> P >> T;

    developers[P].is_infection = true;
    developers[P].infection_count = K;

    for (int i = 0; i < T; i++)
    {
        int t, x, y;
        cin >> t >> x >> y;

        tt[t].first = x;
        tt[t].second = y;
    }

    for (int i = 1; i < TIME_TABLE; i++)
    {
        if (tt[i].first == 500) continue;

        int x, y;
        x = tt[i].first;
        y = tt[i].second;

        if (developers[x].is_infection)
        {
            if (developers[x].infection_count)
            {
                developers[x].infection_count--;
                if (!developers[y].is_infection)
                {
                    developers[y].is_infection = true;
                    developers[y].infection_count = K;
                }
                else
                {
                    if (developers[y].infection_count) developers[y].infection_count--;
                }
            }
            else
            {
                if (developers[y].infection_count) developers[y].infection_count--;
            }
        }
        else
        {
            if (developers[y].is_infection)
            {
                if (developers[y].infection_count)
                {
                    developers[y].infection_count--;
                    developers[x].is_infection = true;
                    developers[x].infection_count = K;
                }
            }
        }
    }

    for_each(developers + 1, developers + N + 1, [](const developer& dev){
        int ans = dev.is_infection ? 1 : 0;
        cout << ans;
    });

    return 0;
}