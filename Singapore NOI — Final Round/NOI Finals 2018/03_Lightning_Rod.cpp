#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e7 + 5;
int a[maxn], b[maxn];
int n;

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = x + y;
        b[i] = x - y;
    }

    for (int i = 1; i < n; i++)
    {
        a[i] = max(a[i - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        b[i] = min(b[i + 1], b[i]);
    }

    int ans = 0;

    for (int j = 0; j < n; j++)
    {
        bool f = false;
        if (j > 0)
        {
            if (a[j] <= a[j - 1])
            {
                f = true;
            }
        }

        if (j + 1 <= n - 1)
        {
            if (b[j + 1] <= b[j])
            {
                f = true;
            }
        }
        if (!f)
        {
            ans++;
        }
    }

    cout << ans << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}