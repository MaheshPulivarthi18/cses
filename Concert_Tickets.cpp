#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    multiset<int> ms;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ms.insert(x);
    }

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        auto it = ms.upper_bound(x);
        if (it == ms.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            --it;
            cout << *it << endl;
            ms.erase(it);
        }
    }

    return 0;
}
