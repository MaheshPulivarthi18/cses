#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        int u = x;
        int v = y;
        int weight = z;
        mp[u].push_back({v, weight});
        mp[v].push_back({u, weight});
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int,pair<int,int>>>> pq;
    pq.push({0, {1, -1}});
    vector<bool> vis(n + 1, false);
    long long  sum = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        int weight = it.first;
        int node = it.second.first;
        int parent = it.second.second;
        pq.pop();
        if (vis[node])
            continue;
        vis[node] = true;
        sum += weight;
        for (auto &p : mp[node])
        {
            int adjNode = p.first;
            int adjWeight = p.second;
            if (!vis[adjNode])
            {
                pq.push({adjWeight, {adjNode, node}});
            }
        }
    }
    bool flag=true;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cout<<"IMPOSSIBLE"<<endl;
            flag=false;
            break;
        }
    }
    if(flag){
    cout << sum << endl;
    }
    return 0;
}