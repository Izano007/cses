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
    int target;
    cin >> target;
    vector<int> dp(target + 1);
    dp[0] = 1;
    for (int i = 1; i <= target; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i >= j)
                dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }
    cout << dp[target] << endl;
}

int main()
{
    fastio;
    solve();
    return 0;
}