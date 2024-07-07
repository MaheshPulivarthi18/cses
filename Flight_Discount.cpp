#include <bits/stdc++.h>
using namespace std;

vector<long long> solve(unordered_map<int, vector<pair<int, int>>> &mp, int src, int n)
{
    vector<long long> ans(n + 1, LLONG_MAX);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0, src});
    ans[src] = 0; 

    while (!pq.empty())
    {
        int node = pq.top().second;
        long long cost = pq.top().first;
        pq.pop();

        if (ans[node] < cost)
            continue;

        for (auto it : mp[node])
        {
            int next = it.first;
            long long next_cost = it.second; 
            if (ans[next] > ans[node] + next_cost)
            {
                ans[next] = ans[node] + next_cost;
                pq.push({ans[next], next});
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<pair<int, int>>> mp1;
    unordered_map<int, vector<pair<int, int>>> mp2;

    vector<tuple<int, int, int>> edges; 

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        mp1[x].push_back({y, z});
        mp2[y].push_back({x, z});
        edges.push_back({x, y, z}); 
    }

    vector<long long> dis1 = solve(mp1, 1, n);
    vector<long long> dis2 = solve(mp2, n, n);

    long long mini = LLONG_MAX;

    for (const auto &edge : edges)
    {
        int x, y, z;
        tie(x, y, z) = edge;
        if (dis1[x] != LLONG_MAX && dis2[y] != LLONG_MAX)
        {
            mini = min(mini, dis1[x] + dis2[y] + z / 2);
        }
    }

    cout << mini << endl;
    return 0;
}
