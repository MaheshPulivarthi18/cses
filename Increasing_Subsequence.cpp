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
    vector<int> dp;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
        if (it == dp.end())
        {
            dp.push_back(nums[i]);
        }
        else
        {
            *it = nums[i];
        }
        int s = dp.size();
        ans = max(ans, s);
    }
    cout << ans << endl;
    return 0;
}