#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k;

ll fairy(vector<ll> big, vector<ll> small)
{
    ll l = 0, r = n - 1;
    ll ck = k;
    while (ck > 0 && l < n && r >= 0)
    {
        if (big[l] >= small[r])
        {
            break;
        }
        swap(big[l], small[r]);
        ck--;
        l++;
        r--;
    }

    sort(big.begin(), big.end());
    sort(small.begin(), small.end());

    return big[n - 1] + small[n - 1];
}

void solve()
{
    cin >> n >> k;

    vector<ll> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = min(fairy(a, b), fairy(b, a));
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}