#include <iostream>
#include <string>
using namespace std;

int month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string days[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

int elapsed_day(int mon, int day)
{
    int ed = 0;
    for (int i = 1; i < mon; i++)
        ed += month[i];
    ed += day;
    return ed;
}

int whatdow(string dday)
{
    int re = -1;
    for (int i = 0; i < 7; i++)
        if (days[i] == dday)
            re = i;
    return re;
}

int main() {
    int m1, d1, m2, d2, e1, e2, result, reminder;
    string dow;
    
    cin >> m1 >> d1 >> m2 >> d2;
    cin >> dow;
    e1 = elapsed_day(m1, d1);
    e2 = elapsed_day(m2, d2);
    result = e2 - e1;
    reminder = result % 7;
    result /= 7;
    if (whatdow(dow) <= reminder) result++;
    if (dow == "Mon") result++;
    cout << result;

    return 0;
}