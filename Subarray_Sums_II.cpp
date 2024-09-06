#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long m, n;
    cin >> m >> n;
    vector<long long> v(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }
    map<long long, long long> mp;
    long long sum = 0;
    long long ct = 0;
    mp[0] = 1;
    for (int i = 0; i < m; i++)
    {
        sum += v[i];
        if (mp.find(sum - n) != mp.end())
        {
            ct += mp[sum - n];
        }

        mp[sum]++;
    }
    cout << ct << endl;
    return 0;
}
