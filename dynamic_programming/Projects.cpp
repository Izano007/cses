#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
#define rep(i, x, n) for (int i = x; i < n; i++)
#define All(a) (a).begin(), (a).end()
#define pb push_back
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void solve()
{
    int n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(3));
    for (int i = 0; i < n; i++)
        cin >> a[i][1] >> a[i][0] >> a[i][2];
    sort(All(a));
    vector<ll> dp(n);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = a[i][2];
        int lo = -1, hi = i - 1;
        while (lo < hi)
        {
            int mid = (lo + hi + 1) / 2;
            if (a[mid][0] < a[i][1])
                lo = mid;
            else
                hi = mid - 1;
        }
        if (lo != -1)
            dp[i] += dp[lo];
        ans = max(ans, dp[i]);
        dp[i] = ans;
    }
    cout << ans << '\n';
}

int main()
{
    fastio;
    solve();
    return 0;
}