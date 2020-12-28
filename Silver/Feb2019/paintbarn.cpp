#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define rep(i, a, b) for(ll i = a; i < b; ++i)

using pi = pair<int, int>;
#define f first
#define s second

void setIO(string name = "paintbarn") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO();
    ll n, k; cin >> n >> k;
    ll d = 1000;
    int ps[1001][1001];
    for (ll i = 0; i <= d; ++i) {
        for (ll j = 0; j <= d; ++j) {
            ps[i][j] = 0;
        }
    }
    for (ll i = 0; i < n; ++i) {
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        ++x1; ++y1;
        for (ll j = x1; j <= x2; ++j) {
            ps[j][y1]++;
        }
        for (ll j = y1; j <= y2; ++j) {
            ps[x1][j]++;
        }
        ps[x1][y1]--;
        for (ll j = y1 + 1; j <= y2 + 1; ++j) {
            if (x2 + 1 <= d && j <= d) {
                ps[x2 + 1][j]--;
            }
        }
        for (ll j = x1 + 1; j <= x2 + 1; ++j) {
            if (y2 + 1 <= d && j <= d) {
                ps[j][y2 + 1]--;
            }
        }
        if (x2 + 1 <= d && y2 + 1 <= d) {
            ps[x2 + 1][y2 + 1]++;
        }
    }
    int matrix[1001][1001];
    for (ll i = 0; i <= d; ++i) {
        for (ll j = 0; j <= d; ++j) {
            matrix[i][j] = 0;
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= d; ++i) {
        for (ll j = 1; j <= d; ++j) {
            matrix[i][j] = matrix[i - 1][j - 1] + ps[i][j];
            if (matrix[i][j] == k) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
}
