#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, amt;
    cin >> t >> amt;
    vector<int> v(t, 0);

    for (int i = 0; i < t; i++)
    {
        cin >> v[i];
    }

    vector<int> dp(amt + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amt; i++)
    {
        for (int j = 0; j < t; j++)
        {
            if (v[j] <= i && dp[i - v[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], 1 + dp[i - v[j]]);
            }
        }
    }

    if (dp[amt] == INT_MAX)
    {
        cout << "-1\n";
    }
    else
    {
        cout << dp[amt] << '\n';
    }

    return 0;
}
