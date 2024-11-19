// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct tupleMine
{
    tupleMine(int row, int col) : row(row), col(col) {}
    int row;
    int col;
};

int x[] = {-1, 0, 1, 0};
int y[] = {0, 1, 0, -1};

void buildMatrix(vector<vector<int>> &path, int actValue, tupleMine position)
{
    int pathValue = path[position.row][position.col];
    if (actValue < pathValue)
    {
        path[position.row][position.col] = actValue;
        /*tupleMine up(position.row - 1, position.col);
        tupleMine right();
        tupleMine down();
        tupleMine left();*/

        for (int i = 0; i < 4; i++)
        {
            int dx = position.row + x[i];
            int dy = position.col + y[i];

            if (dx > -1 && dy > -1 && dx < path.size() && dy < path[0].size() && path[dx][dy] != -2)
            {
                tupleMine newTuple(dx, dy);
                buildMatrix(path, actValue + 1, newTuple);
            }
        }
    }
}

int main()
{
    int rows = 0;
    int cols = 0;
    tupleMine joesPos(0, 0);
    vector<tupleMine> fires;

    cin >> rows >> cols;
    vector<vector<int>> path(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        string insert = ".";
        cin >> insert;
        for (int j = 0; j < cols; j++)
        {
            char val = insert[j];
            if (val == '#')
            {
                path[i][j] = -2;
            }
            else if (val == 'J')
            {
                path[i][j] = 100;
                joesPos.row = i;
                joesPos.col = j;
            }
            else if (val == 'F')
            {
                path[i][j] = 100;
                tupleMine newFire(i, j);
                fires.push_back(newFire);
            }
            else
            {
                path[i][j] = 100;
            }
        }
    }

    for (int i = 0; i < fires.size(); i++)
    {
        buildMatrix(path, 0, fires[i]);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << path[i][j] << " ";
        cout << "\n";
    }

    return 0;
}