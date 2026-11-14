#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e18;

void solve()
{
   ll n,x;cin>>n>>x;
   vector<ll>v(n);
   for(auto &i:v)cin>>i;
   vector<pair<ll,ll>>dp(1<<n,{inf,inf});
   dp[0] = {1,0};
   for(int mask = 0;mask<(1<<n);mask++)
   {
    auto [ride,w] = dp[mask];
    if(ride==inf)continue;
    for(int i=0;i<n;i++)
    {
        if(mask&(1<<i))continue;

        int new_mask = mask | (1<<i);
        pair<ll,ll>hell;
        if(w+v[i]<=x)
        {
            hell = {ride,w+v[i]};
        }
        else
        {
            hell = {ride+1,v[i]};
        }
        dp[new_mask] = min(dp[new_mask],hell);
    }
   }
   cout<<dp[(1<<n)-1].first<<'\n';
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int t=1;
   //cin>>t;
   while(t--){
   solve();}
   return 0;
}