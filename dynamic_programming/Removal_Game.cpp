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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    ll sum = accumulate(All(a), 0LL);
    vector<vector<ll>> dp(n, vector<ll>(n));
    rep(i, 0, n) dp[i][i] = (ll)a[i];
    for (int l = n - 2; l >= 0; l--)
    {
        rep(r, l + 1, n)
        {
            dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
        }
    }
    cout << (sum + dp[0][n - 1]) / 2 << '\n';
}

int main()
{
    fastio;
    solve();
    return 0;
}