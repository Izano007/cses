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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    rep(i, 0, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++)
    {
        for (int target = sum; target >= 0; target--)
        {
            if (target + a[i] <= sum && dp[target])
                dp[target + a[i]] = true;
        }
    }
    vector<int> v;
    for (int i = 1; i <= sum; i++)
    {
        if (dp[i])
            v.pb(i);
    }
    cout << (int)v.size() << '\n';
    for (auto X : v)
        cout << X << " ";
    cout << '\n';
}

int main()
{
    fastio;
    solve();
    return 0;
}