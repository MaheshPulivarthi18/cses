#include <bits/stdc++.h>
using namespace std;
int knapSack(int W, vector<int> wt, vector<int> val, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n;
    cin >> m >> n;
    vector<int> wt(m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> wt[i];
    }
    vector<int> val(m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> val[i];
    }
    cout << knapSack(n, wt, val, m);
    return 0;
}
