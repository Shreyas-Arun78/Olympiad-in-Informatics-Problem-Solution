#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

struct fenwick
{
   ll n;
   vector<ll> tree;
   fenwick(ll n)
   {
      this->n = n;
      tree.assign(n + 1, 0);
   }
   void update(ll idx, ll val)
   {
      while (idx <= n)
      {
         tree[idx] += val;
         idx += (idx & (-idx));
      }
   }
   ll query(ll idx)
   {
      ll sum = 0;
      while (idx > 0)
      {
         sum += tree[idx];
         idx -= (idx & (-idx));
      }
      return sum;
   }
};

void solve()
{
   ll n;
   cin >> n;
   vector<ll> v(n);
   for (auto &i : v)
      cin >> i;

   vector<ll> vals = v;
   sort(vals.begin(), vals.end());
   vals.erase(unique(vals.begin(), vals.end()), vals.end());
   vector<ll> comp(n);
   for (int i = 0; i < n; i++)
   {
      ll id = lower_bound(vals.begin(), vals.end(), v[i]) - vals.begin();
      comp[i] = id + 1;
   }

   vector<ll> factorial(n, 1);
   ll cal = 1;
   for (int i = 2; i < n; i++)
   {
      cal = (cal * i) % mod;
      factorial[i] = cal;
   }

   fenwick tree(n);
   for (int i = 1; i <= n; i++)
   {
      tree.update(i, 1);
   }
   ll ans = 1;
   for (int i = 0; i < n; i++)
   {
      ll x = tree.query(comp[i] - 1);
      tree.update(comp[i], -1);
      ans = (ans + (x * factorial[n - i - 1]) % mod) % mod;
   }
   cout << ans << '\n';
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   solve();
   return 0;
}