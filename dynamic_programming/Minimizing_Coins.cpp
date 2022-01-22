#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const int MAX = 2e9 + 7;

void solve()
{
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> dp(target + 1, MAX);
    dp[0] = 0;
    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - a[j] >= 0)
                dp[i] = min(dp[i - a[j]] + 1, dp[i]);
        }
    }
    cout << ((dp[target] >= MAX) ? -1 : dp[target]) << endl;
}

int main()
{
    fastio;
    solve();
    return 0;
}