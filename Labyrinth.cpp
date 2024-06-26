#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<char> directionChars = {'D', 'R', 'U', 'L'};

bool isValid(vector<vector<char>> &grid, vector<vector<bool>> &vis, int x, int y)
{
    return x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] != '#' && !vis[x][y];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    pair<int, int> start, end;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                start = {i, j};
            }
            else if (grid[i][j] == 'B')
            {
                end = {i, j};
            }
        }
    }

    vector<vector<bool>> vis(m, vector<bool>(n, false));
    vector<vector<pair<int, int>>> parent(m, vector<pair<int, int>>(n, {-1, -1}));
    queue<pair<int, int>> q;
    q.push(start);
    vis[start.first][start.second] = true;
    bool found = false;

    while (!q.empty() && !found)
    {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d)
        {
            int newX = x + directions[d].first;
            int newY = y + directions[d].second;

            if (isValid(grid, vis, newX, newY))
            {
                vis[newX][newY] = true;
                parent[newX][newY] = {x, y};

                if (grid[newX][newY] == 'B')
                {
                    found = true;
                    end = {newX, newY};
                    break;
                }

                q.push({newX, newY});
            }
        }
    }

    if (found)
    {
        cout << "YES" << endl;
        string resultPath = "";
        pair<int, int> cur = end;

        while (cur != start)
        {
            auto [px, py] = parent[cur.first][cur.second];
            if (cur.first == px + 1)
                resultPath += 'D';
            else if (cur.first == px - 1)
                resultPath += 'U';
            else if (cur.second == py + 1)
                resultPath += 'R';
            else if (cur.second == py - 1)
                resultPath += 'L';
            cur = {px, py};
        }

        reverse(resultPath.begin(), resultPath.end());
        cout << resultPath.length() << endl;
        cout << resultPath << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
