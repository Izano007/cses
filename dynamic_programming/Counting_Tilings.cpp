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

vector<vector<ll>> dp;
int n, m;
const int MOD = 1e9 + 7;

void recur(int x, int y, int mask, int next_mask)
{
    if (x == n)
        return;
    if (y >= m)
        dp[x + 1][next_mask] = (dp[x + 1][next_mask] + dp[x][mask]) % MOD;
    else
    {
        int my_mask = 1 << y;
        if (mask & my_mask)
            recur(x, y + 1, mask, next_mask);
        else
        {
            recur(x, y + 1, mask, next_mask | my_mask);
            if (y + 1 < m && !(mask & my_mask) && !(mask & (my_mask << 1)))
                recur(x, y + 2, mask, next_mask);
        }
    }
}

void solve()
{
    cin >> n >> m;
    if (n < m)
        swap(n, m);
    dp = vector<vector<ll>>(n + 1, vector<ll>(1 << m));
    dp[0][0] = 1LL;
    rep(x, 0, n + 1)
    {
        rep(mask, 0, 1 << m)
        {
            recur(x, 0, mask, 0);
        }
    }
    cout << dp[n][0] << '\n';
}

int main()
{
    fastio;
    solve();
    return 0;
}