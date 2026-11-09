#include <bits/stdc++.h>
using namespace std;
 
int facto(int n)
{
    if (n <= 1)
        return 1;
    return n * facto(n - 1);
}
 
void solve()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int fact = 1;
    for (int i = 0; i < 26; i++)
    {
        int cnt = count(s.begin(), s.end(), 'a' + i);
        if (cnt != 0)
            fact *= facto(cnt);
    }
 
    cout << facto(s.size()) / fact << '\n';
    do
    {
        cout << s << '\n';
    } while (next_permutation(s.begin(), s.end()));
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}