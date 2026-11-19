using ll = long long;
struct seg_tree
{
    ll n;
    vector<ll> tree;
    seg_tree(ll n)
    {
        this->n = n;
        tree.resize(4 * n);
    }
    void build(ll node, ll l, ll r, vector<ll> &v)
    {
        if (l == r)
        {
            tree[node] = v[l];
            return;
        }
        ll mid = (l + r) / 2;
        build((node << 1) + 1, l, mid, v);
        build((node << 1) + 2, mid + 1, r, v);
        tree[node] = tree[(node << 1) + 1] + tree[(node << 1) + 2];
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr)
    {
        if (ql > r || qr < l)
        {
            return 0;
        }
        if (ql <= l && qr >= r)
        {
            return tree[node];
        }
        ll mid = (l + r) / 2;
        ll left_child = query((node << 1) + 1, l, mid, ql, qr);
        ll right_child = query((node << 1) + 2, mid + 1, r, ql, qr);
        return left_child + right_child;
    }
    void update(ll node, ll l, ll r, ll pos, ll val)
    {
        if (l == r)
        {
            tree[node] = val;
            return;
        }
        ll mid = (l + r) / 2;
        if (pos <= mid)
        {
            update((node << 1) + 1, l, mid, pos, val);
        }
        else
        {
            update((node << 1) + 2, mid + 1, r, pos, val);
        }
        tree[node] = tree[(node << 1) + 1] + tree[(node << 1) + 2];
    }
};
