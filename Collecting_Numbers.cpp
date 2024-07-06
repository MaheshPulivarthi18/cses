#include <bits/stdc++.h>
using namespace std;

long solve(vector<int> arr, int N)
{
    long ans = 1;
    vector<long> indices(N + 1);
    for (int i = 0; i < N; i++)
    {
        indices[arr[i]] = i;
    }
    for (int num = 1; num < N; num++)
    {
        if (indices[num + 1] < indices[num])
            ans++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin >> m;
    vector<int> v(m);
    vector<int> ans;
    ans.push_back(0);
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }
    cout << solve(v, m) << endl;
    return 0;
}