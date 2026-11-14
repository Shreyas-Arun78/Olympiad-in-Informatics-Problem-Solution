#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end());
    int i = 0, j = n - 1;
    ll sum = 0;
    while (i < j)
    {
        ll l = v[i].first, r = v[j].first;
        sum = l + r;
        if (sum == x)
        {
            cout << min(v[i].second, v[j].second) << ' ' << max(v[i].second, v[j].second) << '\n';
            exit(0);
        }
        else if (sum > x)
        {
            sum -= r;
            j--;
        }
        else if (sum < x)
        {
            sum -= l;
            i++;
        }
    }
    cout << "IMPOSSIBLE\n";
}