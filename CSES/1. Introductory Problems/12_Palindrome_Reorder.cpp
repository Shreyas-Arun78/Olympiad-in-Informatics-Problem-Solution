/**
 * author : Shreyas Arun :)
 **/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve()
{
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (auto &i : s)
    {
        cnt[i - 65]++;
    }
    ll cal = 0;
    for (auto &i : cnt)
    {
        cal += (i & 1);
    }
    if (cal > 1)
    {
        cout << "NO SOLUTION\n";
        return;
    }
    char ch = ' ';
    string k = "";
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i]&1)
        {
            ch = 'A' + i;
            // continue;
        }
        cnt[i] >>= 1;
        while (cnt[i]--)
        {
            k += 'A' + i;
        }
    }
    string l = k;
    if (ch != ' ')
    {
        k += ch;
    }
    reverse(l.begin(), l.end());
    k += l;
    cout << k << '\n';
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}