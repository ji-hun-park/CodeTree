#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K, MAX = 0;
    vector<int> list;
    vector<pair<int, int>> com;
    cin >> N >> K;
    list.resize(N);
    com.resize(K);
    for (int i = 0; i < K; i++)
    {
        cin >> com[i].first >> com[i].second;
    }
    for (int i = 0; i < K; i++)
    {
        for (int j = com[i].first - 1; j <= com[i].second - 1; j++)
        {
            list[j]++;
        }
    }
    for (int i = 0; i < N; i++)
        if (list[i] > MAX) MAX = list[i];
    cout << MAX;
    return 0;
}