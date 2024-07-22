#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &adj, vector<int> &dp, int node, int n)
{
    if (node == n)
    {
        return 1;
    }
    if (dp[node] != -1)
    {
        return dp[node];
    }
    int ans = 0;
    for (int i = 0; i < adj[node].size(); i++)
    {
        ans =(ans+dfs(adj, dp, adj[node][i], n))%1000000007;
    }
    return dp[node] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> n >> m;
    vector<int> dp(n + 1, -1);
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    long long ans = dfs(adj, dp, 1, n);
    cout << ans << endl;

    return 0;
}
