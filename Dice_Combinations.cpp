#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    vector<int> dp(t + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i >= j)
            {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    cout << dp[t] << '\n';
    return 0;
}
