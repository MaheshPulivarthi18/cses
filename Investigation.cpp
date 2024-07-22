#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<pair<int, int>>> graph;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    vector<int> count(n + 1, 0), flight_min(n + 1, INT_MAX), flight_max(n + 1, 0);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[1] = 0;
    count[1] = 1;
    flight_min[1] = 0;
    flight_max[1] = 0;

    pq.push({0, 1});

    const int MOD = 1e9 + 7;

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto &[v, w] : graph[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                count[v] = count[u];
                flight_min[v] = flight_min[u] + 1;
                flight_max[v] = flight_max[u] + 1;
                pq.push({dist[v], v});
            }
            else if (dist[u] + w == dist[v])
            {
                count[v] = (count[v] + count[u]) % MOD;
                flight_min[v] = min(flight_min[v], flight_min[u] + 1);
                flight_max[v] = max(flight_max[v], flight_max[u] + 1);
            }
        }
    }

    if (dist[n] == LLONG_MAX)
        cout << -1 << endl;
    else
    {
        cout << dist[n] << " ";
        cout << count[n] << " ";
        cout << flight_min[n] << " ";
        cout << flight_max[n] << endl;
    }

    return 0;
}
