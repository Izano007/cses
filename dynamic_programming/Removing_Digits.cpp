#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> dp;

int recur(int n)
{
    if (n <= 0)
        return 0;
    if (dp[n] != INT_MAX)
        return dp[n];
    int x = n;
    int ans = INT_MAX;
    while (x != 0)
    {
        if (x % 10 != 0)
            ans = min(1 + recur(n - x % 10), ans);
        x /= 10;
    }
    return dp[n] = ans;
}

void solve()
{
    int n;
    cin >> n;
    dp = vector<int>(n + 1, INT_MAX);
    cout << recur(n) << endl;
}

int main()
{
    solve();
    return 0;
}