#include <iostream>

#define MAX_STUDENT 100

int Student_List[MAX_STUDENT+1];

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K, Fine = -1;
    cin >> N >> M >> K;

    while(M--)
    {
        int punishment;
        cin >> punishment;
        Student_List[punishment]++;
        if (Student_List[punishment] >= K)
        {
            Fine = punishment;
            break;
        }
    }

    cout << Fine;

    return 0;
}