#include <iostream>

#define MAX_TIME 1000000

int A_Move[MAX_TIME+1], B_Move[MAX_TIME+1];

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, AP = 0, BP = 0;

    cin >> N >> M;

    while(N--)
    {
        int v, t;
        cin >> v >> t;
        while(t--)
        {
            AP++;
            A_Move[AP] = A_Move[AP-1] + v;
        }
    }

    for (int i = AP+1; i <= MAX_TIME; i++)
    {
        A_Move[i] = A_Move[i-1];
    }

    while(M--)
    {
        int v, t;
        cin >> v >> t;
        while(t--)
        {
            BP++;
            B_Move[BP] = B_Move[BP-1] + v;
        }
    }

    for (int i = BP+1; i <= MAX_TIME; i++)
    {
        B_Move[i] = B_Move[i-1];
    }

    int cnt = 0;
    char LF = 'C', CF;

    for (int i = 1; i <= MAX_TIME; i++)
    {
        if (A_Move[i] > B_Move[i])
        {
            CF = 'A';
        }
        else if (A_Move[i] < B_Move[i])
        {
            CF = 'B';
        }
        else
        {
            CF = LF;
        }

        if (LF != 'C' && CF != LF) cnt++;
        LF = CF;
    }

    cout << cnt;

    return 0;
}