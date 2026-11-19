#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    vector<ll> comp = v;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = lower_bound(comp.begin(), comp.end(), v[i])-comp.begin();
    }

    vector<pair<ll, ll>> st;
    vector<bool> active(comp.size(), false);
    for (int i = 0; i < n; i++)
    {
        ll col = a[i];
        if (active[col])
        {
            ll cnt = 1;
            while (!st.empty() && st.back().first != col)
            {
                cnt += st.back().second;
                active[st.back().first] = false;
                st.pop_back();
            }
            st.back().second += cnt;
        }
        else
        {
            st.push_back({col,1});
            active[col] = true;
        }
    }
    for(auto  &i:st)
    {
        for(int j =0;j<i.second;j++)
        {
            cout<<comp[i.first]<<'\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}