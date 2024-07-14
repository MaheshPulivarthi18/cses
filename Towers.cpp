#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> cubes(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cubes[i];
    }

    multiset<int> towers;
    for (int i = 0; i < n; i++)
    {
        auto it = towers.upper_bound(cubes[i]);
        if (it != towers.end())
        {
            towers.erase(it);
        }
        towers.insert(cubes[i]);
    }

    cout << towers.size() << endl;
    return 0;
}
