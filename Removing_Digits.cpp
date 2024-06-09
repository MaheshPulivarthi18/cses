#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    vector<int> dp(t + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= t; i++)
    {
        string s = to_string(i);
        for (int j = 0; j < s.length(); j++)
        {
            dp[i] = min(dp[i], dp[i - (s[j] - '0')] + 1);
        }
    }
    cout << dp[t];
    return 0;
}