#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int sum = accumulate(nums.begin(), nums.end(), 0);
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j >= nums[i - 1])
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int count = 0;
    for (int j = 1; j <= sum; j++)
    {
        if (dp[n][j])
        {
            count++;
        }
    }
    cout << count << endl;
    for (int j = 1; j <= sum; j++)
    {
        if (dp[n][j])
        {
            cout << j << " ";
        }
    }
    cout << endl;

    return 0;
}
