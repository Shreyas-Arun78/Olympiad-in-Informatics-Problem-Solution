#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve()
{
   ll n , m;
   cin>>n>>m;
   vector<vector<pair<ll,ll>>>v(n);
   while(m--)
   {  
      ll a, b , w;
      cin>>a>>b>>w,--a,--b;
      v[a].push_back({b,w});
      
   }
   vector<bool>visited(n,false);
   vector<ll>dist(n,LLONG_MAX);
   dist[0] = 0;
   priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
   pq.push({0,0});
   while(!pq.empty())
   {
      ll node = pq.top().second;
      pq.pop();
      if(visited[node])continue;
      visited[node] = true;
      for(auto &i:v[node])
      {
         if(!visited[i.first] && dist[i.first]>dist[node]+i.second)
         {
            dist[i.first] = dist[node]+i.second;
            pq.push({dist[i.first],i.first});
         }
      }
   }
   for(auto &i:dist)
   {
      cout<<i<<' ';
   }
   return;
}
 
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   solve();
   return 0;
}