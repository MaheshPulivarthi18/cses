#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (v[i] + v[j] <= m)
        {
            ans++;
            i++;
            j--;
        }
        else
        {
            ans++;
            j--;
        }
    }
    cout << ans << endl;
    return 0;
}