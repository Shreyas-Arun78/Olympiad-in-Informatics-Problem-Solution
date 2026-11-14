
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> a(n);
    for (auto &s : a) cin >> s;

    vector<pair<int,int>> cur, nxt;

    cur.push_back({0, 0});

    string ans = "";
    ans += a[0][0];

    for (int d = 0; d < 2 * n - 2; d++) {

        char mn = 'Z' + 1;

        nxt.clear();

        // Find the minimum character among next cells
        for (auto [x, y] : cur) {

            if (x + 1 < n)
                mn = min(mn, a[x + 1][y]);

            if (y + 1 < n)
                mn = min(mn, a[x][y + 1]);
        }

        // Keep only positions having the minimum character
        for (auto [x, y] : cur) {

            if (x + 1 < n && a[x + 1][y] == mn)
                nxt.push_back({x + 1, y});

            if (y + 1 < n && a[x][y + 1] == mn)
                nxt.push_back({x, y + 1});
        }

        // Remove duplicate positions
        sort(nxt.begin(), nxt.end());
        nxt.erase(unique(nxt.begin(), nxt.end()), nxt.end());

        ans += mn;
        cur.swap(nxt);
    }

    cout << ans << '\n';
}
