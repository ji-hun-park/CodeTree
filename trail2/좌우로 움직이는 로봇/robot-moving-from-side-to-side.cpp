#include <iostream>

#define MAX_COUNT 50'000
#define MAX_RANGE 2'000'000

int A_Move[MAX_RANGE + 1], B_Move[MAX_RANGE + 1];

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, AC = 0, BC = 0;
    cin >> N >> M;

    while(N--)
    {
        int t;
        char d;
        cin >> t >> d;
        while(t--)
        {
            AC++;
            if (d == 'R')
            {
                A_Move[AC] = A_Move[AC - 1] + 1;
            }
            else
            {
                A_Move[AC] = A_Move[AC - 1] - 1;
            }
        }
    }

    for (int i = AC + 1 ; i <= MAX_RANGE; i++)
    {
        A_Move[i] = A_Move[i - 1];
    }

    while(M--)
    {
        int t;
        char d;
        cin >> t >> d;
        while(t--)
        {
            BC++;
            if (d == 'R')
            {
                B_Move[BC] = B_Move[BC - 1] + 1;
            }
            else
            {
                B_Move[BC] = B_Move[BC - 1] - 1;
            }
        }
    }

    for (int i = BC + 1 ; i <= MAX_RANGE; i++)
    {
        B_Move[i] = B_Move[i - 1];
    }

    int cnt = 0;

    for (int i = 1; i <= MAX_RANGE; i++)
    {
        if (A_Move[i - 1] != B_Move[i - 1])
        {
            if (A_Move[i] == B_Move[i]) cnt++;
        }
    }

    cout << cnt;

    return 0;
}