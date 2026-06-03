#include <iostream>
#include <algorithm>

#define MAX_N 1000

using namespace std;

int max_con = 0, cnt = 0;
int num_array[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, T;
    cin >> N >> T;

    for (int i = 0; i < N; i++)
    {
        cin >> num_array[i];
    }

    for_each(num_array, &num_array[N], [T](int num){
        if (T < num)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        max_con = max(max_con, cnt);
    });

    cout << max_con;

    return 0;
}