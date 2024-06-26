#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    vector<bool> visited(m + 1, false);
    vector<int> parent(m + 1, -1);

    visited[1] = true;
    bool found = false;

    while (!q.empty() && !found)
    {
        int top = q.front();
        q.pop();
        for (int neighbor : mp[top])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                parent[neighbor] = top;
                q.push(neighbor);
                if (neighbor == m)
                {
                    found = true;
                    break;
                }
            }
        }
    }

    if (found)
    {
        vector<int> path;
        for (int at = m; at != -1; at = parent[at])
        {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl; 
        for (int node : path)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE"<< endl;
    }

    return 0;
}
