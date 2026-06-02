#include <iostream>
#include <vector>
using namespace std;

#define MAX_RANGE 200000

struct Tile
{
    char color = 'X';
    int w = 0, b = 0;
};

int main() {
    int N, W = 0, B = 0, G = 0, cur = 100000;
    vector<Tile> line;
    vector<pair<int, char>> command;

    line.resize(MAX_RANGE + 1);
    cin >> N;
    command.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> command[i].first >> command[i].second;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < command[i].first; j++)
        {
            if (command[i].second == 'L')
            {
                line[cur].w += 1;
                if (line[cur].w >= 2 && line[cur].b >= 2)
                {
                    line[cur].color = 'G';
                }
                else
                {
                    line[cur].color = 'W';
                }
                
                if(j != command[i].first - 1)cur -= 1;
            }
            else if (command[i].second == 'R')
            {
                line[cur].b += 1;
                if (line[cur].w >= 2 && line[cur].b >= 2)
                {
                    line[cur].color = 'G';
                }
                else
                {
                    line[cur].color = 'B';
                }
                if(j != command[i].first - 1)cur += 1;
            }
        }
    }

    for (int i = 0; i <= MAX_RANGE; i++)
    {
        if (line[i].color == 'W')
        {
            W++;
        }
        else if (line[i].color == 'B')
        {
            B++;
        }
        else if (line[i].color == 'G')
        {
            G++;
        }
    }

    cout << W << " " << B << " " << G;

    return 0;
}