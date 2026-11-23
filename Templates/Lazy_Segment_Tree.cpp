#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct lazy_seg_tree
{
    ll n;
    vector<ll> tree, lazy;

    lazy_seg_tree(ll n)
    {
        this->n = n;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void build(ll node, ll l, ll r, vector<ll> &v)
    {
        if (l == r)
        {
            tree[node] = v[l];
            return;
        }

        ll mid = l + (r - l) / 2;

        build((node << 1) + 1, l, mid, v);
        build((node << 1) + 2, mid + 1, r, v);

        tree[node] = tree[(node << 1) + 1] + tree[(node << 1) + 2];
    }

    void push(ll idx, ll l, ll r)
    {
        if (lazy[idx])
        {
            tree[idx] += (r - l + 1) * lazy[idx];
            if (l != r)
            {
                lazy[(idx << 1) + 1] += lazy[idx];
                lazy[(idx << 1) + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }

    void update(ll node, ll l, ll r, ll ql, ll qr, ll val)
    {
        push(node, l, r);

        if (ql > r || qr < l)
        {
            return;
        }
        if (ql <= l && qr >= r)
        {
            lazy[node] += val;
            push(node, l, r);
            return;
        }

        ll mid = l + (r - l) / 2;

        update((node << 1) + 1, l, mid, ql, qr, val);
        update((node << 1) + 2, mid + 1, r, ql, qr, val);

        tree[node] = tree[(node << 1) + 1] + tree[(node << 1) + 2];
    }

    ll query(ll node, ll l, ll r, ll ql, ll qr)
    {
        push(node, l, r);

        if (ql > r || qr < l)
        {
            return 0;
        }
        if (ql <= l && qr >= r)
        {
            return tree[node];
        }

        ll mid = l + (r - l) / 2;

        ll left_child = query((node << 1) + 1, l, mid, ql, qr);
        ll right_child = query((node << 1) + 2, mid + 1, r, ql, qr);

        return left_child + right_child;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;

    vector<ll> v(n);

    for (auto &i : v)
    {
        cin >> i;
    }

    lazy_seg_tree tree(n);

    tree.build(0, 0, n - 1, v);

    while (q--)
    {
        /*

        query type:

        type 1 : 1 l r val   (increment value of elments of range [l,r] equal to val)
        type 2 : 2 l r       (return the sum of range [l,r])

        */

        int t;
        ll l, r;

        cin >> t >> l >> r, --l, --r; // 0-based indexing

        if (t == 1)
        {
            ll val;
            cin >> val;
            tree.update(0, 0, n - 1, l, r, val);
        }
        else if (t == 2)
        {
            ll range_sum = tree.query(0, 0, n - 1, l, r);

            cout << range_sum << '\n';
        }
    }

    return 0;
}