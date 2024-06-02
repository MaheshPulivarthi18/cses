#include <bits/stdc++.h>
using namespace std;
int dfs(int index, map<int, vector<int>> &mp, vector<int> &dp)
{
    if (dp[index] != -1)
    {
        return dp[index];
    }
    int ct = 0;
    for (auto child : mp[index])
    {
        ct += 1 + dfs(child, mp, dp);
    }
    dp[index] = ct;

    return ct;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    vector<int> ans(t, 0);
    map<int, vector<int>> mp;
    for (int i = 0; i < t - 1; i++)
    {
        int x;
        cin >> x;
        mp[x].push_back(i + 2);
    }
    vector<int> dp(t + 1, -1);
    for (int i = 1; i <= t; i++)
    {
        if (mp[i].empty())
        {
            ans[i - 1] = 0;
        }
        else
        {
            ans[i - 1] = dfs(i, mp, dp);
        }
    }
    for (int i = 0; i < t; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
