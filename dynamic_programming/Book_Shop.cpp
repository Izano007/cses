#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const int MOD = 1e9 + 7;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> h(n), s(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    vector<int> dp(x + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = x; j >= 1; j--)
        {
            if (j >= h[i])
                dp[j] = max(dp[j - h[i]] + s[i], dp[j]);
        }
    }
    cout << dp[x] << endl;
}

int main()
{
    fastio;
    solve();
    return 0;
}