#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int m1, d1, m2, d2, e3;
    int e1 = 0, e2 = 0;
    vector<int> md = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int dday = 1;
    vector<string> dow = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    // Please write your code here.
    cin >> m1 >> d1 >> m2 >> d2;
    for (int i = 1; i < m1; i++)
        e1 += md[i];
    e1 += d1;
    for (int i = 1; i < m2; i++)
        e2 += md[i];
    e2 += d2;
    e3 = e2 - e1;
    dday += e3;
    dday %= 7;
    if (dday < 0) dday += 7;
    cout << dow[dday];
    return 0;
}