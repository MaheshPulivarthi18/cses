#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ans = 0;
    int i = 0, j = 0;
    set<int> s;
    int maxLength = 0;

    while (i < n && j < n)
    {
        if (s.find(v[j]) == s.end())
        {
            s.insert(v[j]);
            j++;
            maxLength = max(maxLength, j - i);
        }
        else
        {
            s.erase(v[i]);
            i++;
        }
    }

    cout << maxLength;
    return 0;
}
