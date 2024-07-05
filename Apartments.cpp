#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> v1(m);
    for (int i = 0; i < m; i++)
        cin >> v1[i];
    sort(v.begin(), v.end());
    sort(v1.begin(), v1.end());
    int i = 0, j = 0;
    int ans = 0;
    while (j < n && i < m)
    {
        int diff = abs(v[j] - v1[i]);
        if (diff <= k)
        {
            ans++;
            i++;
            j++;
        }
        else
        {
            if (v[j] > v1[i])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}