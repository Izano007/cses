#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const int MOD = 1e9 + 7;
const int MAX_N = 1e6 + 1;

int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    vector<vector<ll>> dp(MAX_N, vector<ll>(2, 1));
    for (int i = 1; i < MAX_N; i++)
    {
        dp[i][0] = (4 * dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i - 1][0] + 2 * dp[i - 1][1]) % MOD;
    }
    while (t--)
    {
        int n;
        cin >> n;
        cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << endl;
    }
    return 0;
}