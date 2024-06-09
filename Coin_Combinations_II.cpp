
#include <bits/stdc++.h>
using namespace std;
long solve(vector<int> &arr, int n, int T)
{
    vector<long> prev(T + 1, 0);
    for (int i = 0; i <= T; i++)
    {
        if (i % arr[0] == 0)
            prev[i] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {
        vector<long> cur(T + 1, 0);
        for (int target = 0; target <= T; target++)
        {
            long notTaken = prev[target] % 1000000007;

            long taken = 0;
            if (arr[ind] <= target)
                taken = cur[target - arr[ind]] % 1000000007;

            cur[target] = (notTaken + taken)%1000000007;
        }
        prev = cur;
    }

    return prev[T] % 1000000007;
}

int main()
{
    int n;
    cin >> n;
    long long target;
    cin >> target;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << solve(arr, n, target) << endl;
    return 0;
}
