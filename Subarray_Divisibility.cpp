#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long m;
    cin >> m;
    vector<long long> v(m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }
    long long sum = 0;
    long long ct = 0;
    map<long long, long long> mp;
    mp[0] = 1;
    for (int i = 0; i < m; i++)
    {
        sum += v[i];
        long long mod = ((sum % m) + m) % m;
        if (mp.find(mod) != mp.end())
        {
            ct += mp[mod];
        }

        mp[mod]++;
    }

    cout << ct << endl;

    return 0;
}
