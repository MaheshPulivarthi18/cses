#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    vector<int> team(n + 1, -1);
    bool cant = false;
    for (int i = 0; i <= n && !cant; i++)
    {
        if (team[i + 1] == -1 && !cant)
        {
            team[i + 1] = 0;
            queue<int> q;
            q.push(i + 1);
            while (!q.empty() && !cant)
            {
                int x = q.front();
                q.pop();
                for (auto it : mp[x])
                {
                    if (team[it] == -1)
                    {
                        team[it] = 1 - team[x];
                        q.push(it);
                    }
                    else if (team[it] == team[x])
                    {
                        cant = true;
                        break;
                    }
                }
            }
        }
    }
    if (cant)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (int i = 1; i < team.size(); i++)
        {
            cout << team[i] + 1 << " ";
        }
    }
    return 0;
}