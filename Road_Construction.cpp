#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> parent, size;
    int componentCount;

    DSU(int n)
    {
        componentCount = n;
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u)
    {
        if (u != parent[u])
        {
            parent[u] = find(parent[u]); 
        }
        return parent[u];
    }

    void unite(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV)
        {
            if (size[rootU] < size[rootV])
            {
                swap(rootU, rootV);
            }
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
            componentCount--;
        }
    }

    int getSize(int u)
    {
        return size[find(u)];
    }

    int getComponentCount()
    {
        return componentCount;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    vector<pair<int, int>> results;
    int largestComponentSize = 1;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        dsu.unite(x, y);
        largestComponentSize = max(largestComponentSize, dsu.getSize(x));
        results.emplace_back(dsu.getComponentCount(), largestComponentSize);
    }

    for (const auto &[count, maxSize] : results)
    {
        cout << count << " " << maxSize << endl;
    }

    return 0;
}
