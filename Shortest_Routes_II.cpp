#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> dis(n + 1, vector<long long>(n + 1, LLONG_MAX));
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b], (long long)c);
        dis[b][a] = min(dis[a][b], (long long)c);
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i][i] = 0;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] < LLONG_MAX && dis[k][j] < LLONG_MAX)
                {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << (dis[a][b] < LLONG_MAX ? dis[a][b] : -1) << endl;
    }
    return 0;
}
