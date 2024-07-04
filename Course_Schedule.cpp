#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int n, unordered_map<int, vector<int>> &mp)
{
    vector<int> ans;
    vector<int> indegree(n + 1, 0); 
    for (const auto &p : mp)
    {
        for (const auto &node : p.second)
        {
            indegree[node]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    { 
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int top = q.front();
        ans.push_back(top);
        q.pop();
        for (const auto &neighbor : mp[top])
        {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }
    if (ans.size() == n)
        return ans;
    return {};
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
    }
    vector<int> ans = findOrder(n, mp);
    if (ans.size() == 0)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl; 
    }
    return 0;
}
