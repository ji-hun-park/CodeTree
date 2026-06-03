#include <iostream>

#define MAX_RANGE 1000000
#define MAX_TIME 1000000

using namespace std;

int A_Move[MAX_TIME+1], B_Move[MAX_TIME+1];

int main() {
    fill_n(A_Move, MAX_TIME+1, MAX_RANGE+1);
    fill_n(B_Move, MAX_TIME+1, MAX_RANGE+1);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, move, A_position = 0, B_position = 0, A_Time = 0, B_Time = 0;
    char direction;
    cin >> N >> M;

    A_Move[0] = A_position;
    B_Move[0] = B_position;

    for (int i = 0; i < N; i++)
    {
        cin >> direction >> move;
        for (int j = 0; j < move; j++)
        {
            A_Time++;
            if (direction == 'L')
            {
                A_Move[A_Time] = --A_position;
            }
            else
            {
                A_Move[A_Time] = ++A_position;
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        cin >> direction >> move;
        for (int j = 0; j < move; j++)
        {
            B_Time++;
            if (direction == 'L')
            {
                B_Move[B_Time] = --B_position;
            }
            else
            {
                B_Move[B_Time] = ++B_position;
            }
        }
    }

    int first_meet = 0;

    for (int i = 1; i <= MAX_TIME; i++)
    {
        if (A_Move[i] != MAX_RANGE+1 && B_Move[i] != MAX_RANGE+1 && A_Move[i] == B_Move[i])
        {
            first_meet = i;
            break;
        }
    }

    if (first_meet == 0) first_meet = -1;
    
    cout << first_meet;

    return 0;
}