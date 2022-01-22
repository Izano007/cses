#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
#define rep(i, x, n) for (int i = x; i < n; i++)
#define pb push_back
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int target = (n * (n + 1)) / 2;
    if (target % 2 != 0)
    {
        cout << 0 << endl;
        return;
    }
    target /= 2;
    vector<ll> dp(target + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = target; j >= 1; j--)
        {
            if (j >= i)
                dp[j] = (dp[j - i] + dp[j]) % MOD;
        }
    }
    cout << (dp[target] * (MOD + 1) / 2) % MOD << endl;
}

int main()
{
    fastio;
    solve();
    return 0;
}