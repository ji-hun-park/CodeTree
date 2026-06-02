#include <iostream>
#include <string>
using namespace std;

int main() {
    int ten = 0;
    string bin;
    cin >> bin;
    for (int i = 0; i < (int)bin.size(); i++)
    {
        ten = ten * 2 + (bin[i] - '0');
    }
    cout << ten;
    return 0;
}