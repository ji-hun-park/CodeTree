#include <iostream>
#include <algorithm>

#define MAX_N 1000
#define PLUS 1
#define MINUS -1

using namespace std;

int lastsign = 0, con_num = 0, ans = 0;

int num_array[MAX_N];

void FindMaxCon(int num)
{
    int sign;
    sign = num > 0 ? PLUS : MINUS;
    if (sign != lastsign)
    {
        con_num = 1;
    }
    else
    {
        con_num++;
    }
    lastsign = sign;
    ans = max(ans, con_num);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num_array[i];
    }

    for_each(num_array, &num_array[N], FindMaxCon);

    cout << ans;

    return 0;
}