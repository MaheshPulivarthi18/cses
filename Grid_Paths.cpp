#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n, '.'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    if (v[0][0] == '*')
    {
        dp[0][0] = 0;
    }
    else
    {
        dp[0][0] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        if (v[i][0] == '*')
        {
            dp[i][0] = 0;
        }
        else
        {
            dp[i][0] = dp[i - 1][0];
        }
    }
    for (int j = 1; j < n; j++)
    {
        if (v[0][j] == '*')
        {
            dp[0][j] = 0;
        }
        else
        {
            dp[0][j] = dp[0][j - 1];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (v[i][j] == '*')
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
            }
        }
    }
    cout << dp[n - 1][n - 1] << "\n";
    return 0;
}
