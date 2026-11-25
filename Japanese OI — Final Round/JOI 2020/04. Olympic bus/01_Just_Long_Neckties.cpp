#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = LLONG_MIN;

struct seg_tree
{
    ll n;
    vector<ll> tree;

    seg_tree(ll n)
    {
        this->n = n;
        tree.assign(4 * n, inf);
    }
    void update(ll node, ll l, ll r, ll pos, ll val)
    {
        if (l == r)
        {
            tree[node] = val;
            return;
        }
        ll mid = l + (r - l) / 2;
        if (pos <= mid)
        {
            update((node << 1) + 1, l, mid, pos, val);
        }
        else
        {
            update((node << 1) + 2, mid + 1, r, pos, val);
        }
        tree[node] = max(tree[(node << 1) + 1], tree[(node << 1) + 2]);
    }
};

void solve()
{
    ll n;
    cin >> n;

    vector<pair<ll, int>> a(n + 1);
    vector<ll> b(n);
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    seg_tree tree(n);

    for (int i = 0; i < n; i++)
    {
        tree.update(0, 0, n - 1, i, max(a[i].first - b[i], 0LL));
    }

    vector<pair<ll, ll>> ans;

    ans.push_back({tree.tree[0], a[n].second});

    for (int i = n - 1; i >= 0; i--)
    {
        tree.update(0, 0, n - 1, i, max(a[i + 1].first - b[i], 0LL));
        ans.push_back({tree.tree[0], a[i].second});
    }
    sort(ans.begin(), ans.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b)
         { return a.second < b.second; });

    for (auto &i : ans)
    {
        cout << i.first << ' ';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
