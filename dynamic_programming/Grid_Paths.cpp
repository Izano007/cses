#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<string> g(n);
    for (int i = 0; i < n; i++)
        cin >> g[i];
    vector<vector<int>> dp(n, vector<int>(n));
    int idx = 0;
    while (idx < n)
    {
        if (g[idx][0] == '*')
            break;
        else
            dp[idx][0] = 1;
        idx++;
    }
    idx = 0;
    while (idx < n)
    {
        if (g[0][idx] == '*')
            break;
        else
            dp[0][idx] = 1;
        idx++;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (g[i][j] == '*')
                dp[i][j] = 0;
            else
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[n - 1][n - 1] << endl;
}

int main()
{
    solve();
    return 0;
}