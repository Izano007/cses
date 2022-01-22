#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
#define All(a) a.begin(), a.end()
#define rep(i, x, n) for (int i = x; i < n; i++)
#define pb push_back
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const int MOD = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<vector<ll>> dp(n, vector<ll>(m + 1));
    rep(i, 0, n) cin >> a[i];
    if (a[0] == 0)
    {
        fill(begin(dp[0]), end(dp[0]), 1LL);
    }
    else
        dp[0][a[0]] = 1LL;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (j > 1)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                if (j < m)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
        else
        {
            dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i]]) % MOD;
            if (a[i] > 1)
                dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i] - 1]) % MOD;
            if (a[i] < m)
                dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i] + 1]) % MOD;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (ans + dp[n - 1][i]) % MOD;
    cout << ans << '\n';
}

int main()
{
    fastio;
    solve();
    return 0;
}