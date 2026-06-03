#include <iostream>
#include <algorithm>

#define MAX_N 1000

int lastnum = 0, cnt = 0, ans = 0;
int num_array[MAX_N];

using namespace std;

void increase(int num)
{
    if (num > lastnum)
    {
        cnt++;
    }
    else
    {
        cnt = 1;
    }
    ans = max(cnt, ans);
    lastnum = num;
}

int main() {
    // Please write your code here.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num_array[i];
    }

    for_each(num_array, &num_array[N], increase);
    
    cout << ans;

    return 0;
}