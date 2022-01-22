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

ll dp[20][10][2][2];

ll recur(int cur, string &s, int prev, bool in_zeros, bool type)
{
    int n = s.length();
    if (cur == n)
        return 1LL;
    if (dp[cur][prev][in_zeros][type] != -1)
        return dp[cur][prev][in_zeros][type];
    int hi = type ? s[cur] - '0' : 9;
    ll ans = 0;
    for (int i = 0; i <= hi; i++)
    {
        if (!in_zeros && prev == i)
            continue;
        ans += recur(cur + 1, s, i, in_zeros && (i == 0), type && (i == hi));
    }
    return dp[cur][prev][in_zeros][type] = ans;
}

void solve()
{
    ll S, T;
    cin >> S >> T;
    string s = to_string(S - 1);
    string t = to_string(T);
    memset(dp, -1, sizeof(dp));
    ll ans1 = recur(0, s, 0, 1, 1);
    memset(dp, -1, sizeof(dp));
    ll ans2 = recur(0, t, 0, 1, 1);
    cout << ans2 - ans1 << '\n';
}

int main()
{
    fastio;
    solve();
    return 0;
}