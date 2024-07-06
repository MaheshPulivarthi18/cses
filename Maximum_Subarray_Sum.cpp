#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    long long  maxi = LONG_LONG_MIN;
    long long  sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + v[i];
        if (maxi < sum)
        {
            maxi = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    cout << maxi << "\n";
    return 0;
}
