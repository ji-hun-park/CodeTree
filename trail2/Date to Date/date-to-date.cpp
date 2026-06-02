#include <iostream>
using namespace std;

int main() {
    int month1, day1, month2, day2;
    int elapsed_days1 = 0, elapsed_days2 = 0;
    int result;

    int num_of_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Please write your code here.
    cin >> month1 >> day1 >> month2 >> day2;
    for (int i = month1 - 1; i > 0; i--)
    {
        elapsed_days1 += num_of_days[i];
    }
    elapsed_days1 += day1;
    for (int i = month2 - 1; i > 0; i--)
    {
        elapsed_days2 += num_of_days[i];
    }
    elapsed_days2 += day2;
    result = elapsed_days2 - elapsed_days1;
    result += 1;
    cout << result;
    return 0;
}