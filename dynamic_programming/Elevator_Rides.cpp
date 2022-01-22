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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<pii> dp(1 << n);
    dp[0] = {1, 0};
    for (int mask = 1; mask < (1 << n); mask++)
    {
        dp[mask] = {n + 1, 0};
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                auto option = dp[mask ^ (1 << i)];
                if (option.second + a[i] <= x)
                {
                    option.second += a[i];
                }
                else
                {
                    option.first++;
                    option.second = a[i];
                }
                dp[mask] = min(dp[mask], option);
            }
        }
    }
    cout << dp[(1 << n) - 1].first << '\n';
}

int main()
{
    fastio;
    solve();
    return 0;
}