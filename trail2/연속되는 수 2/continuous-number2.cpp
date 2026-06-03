#include <iostream>
#include <algorithm>

#define MAX_N 1000

using namespace std;

int lastnum = -1;
int cnt = 0;
int max_con = 0;
int num_seq[MAX_N];

void Max_Con(int num)
{
    if (num != lastnum)
    {
        cnt = 1;
    }
    else
    {
        cnt++;
    }
    if (max_con < cnt) max_con = cnt;
    lastnum = num;
}

int main() {
    // 입출력 속도 향상을 위한 코드
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num_seq[i];
    }

    for_each(num_seq, &num_seq[N], Max_Con);
    cout << max_con;

    return 0;
}