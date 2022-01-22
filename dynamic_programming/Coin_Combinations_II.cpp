#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

void solve()
{
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> dp(target + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int tar = 1; tar <= target; tar++)
        {
            if (tar >= a[i])
                dp[tar] = (dp[tar - a[i]] + dp[tar]) % MOD;
        }
    }
    cout << dp[target] << endl;
}

int main()
{
    solve();
    return 0;
}