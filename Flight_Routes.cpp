#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<vector<int>> dist(n + 1);
    vector<int> count(n + 1, 0);

    pq.push({0, 1}); // {cost, node}
    while (!pq.empty())
    {
        auto [cost, u] = pq.top();
        pq.pop();

        if (count[u] >= k)
            continue;
        count[u]++;
        dist[u].push_back(cost);

        if (u == n && count[u] == k)
            break;

        for (auto &[v, w] : adj[u])
        {
            if (count[v] < k)
            {
                pq.push({cost + w, v});
            }
        }
    }

    sort(dist[n].begin(), dist[n].end());
    for (int i = 0; i < k; i++)
    {
        cout << dist[n][i] << " ";
    }
    cout << "\n";

    return 0;
}
