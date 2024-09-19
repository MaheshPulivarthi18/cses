#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<long long> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    long long low = *max_element(v.begin(), v.end());     
    long long high = accumulate(v.begin(), v.end(), 0LL);
    long long ans = high;                                 
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long sum = 0;
        int ct = 1; 
        for (int i = 0; i < n; i++)
        {
            if (sum + v[i] > mid)
            {
                ct++;       
                sum = v[i]; 
            }
            else
            {
                sum += v[i]; 
            }
        }
        if (ct <= k)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1; 
        }
    }

    cout << ans << endl;
    return 0;
}
