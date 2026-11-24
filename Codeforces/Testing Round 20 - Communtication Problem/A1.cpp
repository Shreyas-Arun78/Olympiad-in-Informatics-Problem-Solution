// problem link - https://codeforces.com/contest/2168/problem/A1
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string s;
    cin >> s;
    if (s == "first")
    {
        int n;
        cin >> n;
        string encode = "";
        while (n--)
        {
            ll x;
            cin >> x;
            encode += 'a' + (x - 1);
        }
        cout << encode << '\n';
    }
    else
    {
        string decode;
        cin>>decode;
        cout<<decode.size()<<'\n';
        for(auto &ch:decode)
        {
            cout<<ch-'a'+1<<' ';
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