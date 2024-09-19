#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    map<long long, int> mp; 
    int i = 0, j = 0;       
    long long ct = 0;       
    while (j < n)
    {
        mp[nums[j]]++;
        while (mp.size() > k)
        {
            mp[nums[i]]--;
            if (mp[nums[i]] == 0)
            {
                mp.erase(nums[i]);
            }
            i++;
        }
        ct += (j - i + 1);
        j++;
    }
    cout << ct << endl;
    return 0;
}
