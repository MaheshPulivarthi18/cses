#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, vector<int>> &mp, vector<bool> &vis)
{
    vis[node] = true;
    for (int neighbor : mp[node])
    {
        if (!vis[neighbor])
        {
            dfs(neighbor, mp, vis);
        }
    }
}

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

    int components = 0;
    vector<bool> vis(n + 1, false);
    vector<int> componentRepresentatives;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, mp, vis);
            components++;
            componentRepresentatives.push_back(i);
        }
    }

    cout << components - 1 << endl;
    for (int i = 1; i < componentRepresentatives.size(); i++)
    {
        cout << componentRepresentatives[i - 1] << " " << componentRepresentatives[i] << endl;
    }

    return 0;
}
