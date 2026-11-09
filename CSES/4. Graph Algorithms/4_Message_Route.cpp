#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> v(n);
    while (m--)
    {
        ll a, b;
        cin >> a >> b, --a, --b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<bool>visited(n,false);
    queue<ll>q;
    q.push(0);
    vector<ll>parent(n);
    parent[0] = -1;
    bool flag = false;
    while(!q.empty())
    {
        ll node = q.front();
        visited[node] = true;
        q.pop();
        for(auto &i:v[node])
        {
            if(!visited[i])
            {
                parent[i]= node;
                q.push(i);
                visited[i] = true;
                flag = (i==n-1);
            }
        }
        if(flag)
        {
            break;
        }
 
    }
    if(!visited[n-1])
    {
        cout<<"IMPOSSIBLE\n";
        return;
    }
    
    ll cur = n-1;
    vector<ll>path;
    while(cur!=-1)
    {
        path.push_back(cur+1);
        cur = parent[cur];
 
    }
    reverse(path.begin(),path.end());
    cout<<path.size()<<'\n';
    for(auto &i:path)
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