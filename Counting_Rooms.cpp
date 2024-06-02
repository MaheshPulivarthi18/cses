#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>> &grid, int i, int j)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '#')
    {
        return;
    }
    grid[i][j] = '#';
    dfs(grid, i + 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i - 1, j);
    dfs(grid, i, j - 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n, '#'));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    int ct = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '.')
            {
                dfs(grid, i, j);
                ct++;
            }
        }
    }
    cout << ct;
    return 0;
}