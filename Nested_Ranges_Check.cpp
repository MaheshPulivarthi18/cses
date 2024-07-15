#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int  n;
    cin >> n;
    vector<pair<long long, long long>> v;
    map<pair<long long , long long >, long long> mp;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        mp[{a, b}] = i;
    }

    vector<int> ans1(n, 0), ans2(n, 0);
    sort(v.begin(), v.end(), cmp);

    long long  rend = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].second <= rend)
        {
            ans1[mp[v[i]]] = 1;
        }
        rend = max(rend, v[i].second);
    }

    long long  lend = 1e9+1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i].second >= lend)
        {
            ans2[mp[v[i]]] =1;
        }
        lend = min(lend, v[i].second);
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans2[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << ans1[i] << " ";
    }

    return 0;
}
