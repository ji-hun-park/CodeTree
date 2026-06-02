#include <iostream>
#include <vector>
using namespace std;

#define MAX_RANGE 2001
#define MAX_N 100

int main() {
    int N, point = 1000, count = 0;
    vector<pair<int, char>> list;
    int line[MAX_RANGE] = {0, };
    
    cin >> N;
    list.resize(N);

    for (int i = 0; i < N; i++)
        cin >> list[i].first >> list[i].second;
    
    for (int i = 0; i < N; i++)
    {
        if (list[i].second == 'R')
        {
            for (int j = 0; j < list[i].first; j++)
                line[point++] += 1;
        }
        else
        {
            for (int j = 0; j < list[i].first; j++)
                line[--point] += 1;
        }
    }

    for (int i = 0; i < MAX_RANGE; i++)
        if(line[i] >= 2) count++;

    cout << count;
    return 0;
}