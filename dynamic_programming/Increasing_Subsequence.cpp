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
    int n, L = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> M(n + 1, -1), P(n, -1);
    for (int i = 0; i < n; i++)
    {
        int lo = 1, hi = L;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (a[M[mid]] < a[i])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        int newL = lo;
        P[i] = M[newL - 1];
        M[newL] = i;
        if (newL > L)
            L = newL;
    }
    cout << L << '\n';
}

int main()
{
    fastio;
    solve();
    return 0;
}