// begin by doing coordinate compression. then, store 2d prefix sum ps where ps[i][j] counts the number of cows
// with coordinates in the box (2 * i, 2 * j). then simply loop through all possible values i and j and calculate
// the number of cows within the given boxes. take the minimum ans out of all of these.

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for(ll i = a; i < b; ++i)
#define rsz(x, n) x.resize(n)

using pi = pair<int, int>;
#define f first
#define s second

void setIO(string name = "balancing") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    return a.second < b.second;
}

int main()
{
    setIO();
    ll n;
    cin >> n;
    vector<pair<ll, ll>> coords(n);
    vector<vector<ll>> c(n);
    vector<vector<ll>> ps(n + 1);
    rep(i, 0, n) {
        rsz(c[i], n);
        rsz(ps[i], n + 1);
        cin >> coords[i].first >> coords[i].second;
    }
    rsz(ps[n], n + 1);
    sort(all(coords));
    rep(i, 0, n) {
        coords[i].first = 2 * i + 1;
    }
    sort(all(coords), cmp);
    rep(i, 0, n) {
        coords[i].second = 2 * i + 1;
    }
    sort(all(coords));
    rep(i, 0, n) {
        ll x = coords[i].first, y = coords[i].second;
        c[x / 2][y / 2] = 1;
    }
    rep(i, 1, n + 1) {
        rep(j, 1, n + 1) {
            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + c[i - 1][j - 1];
        }
    }
    ll ans = n;
    rep(i, 1, n + 1) {
        rep(j, 1, n + 1) {
            ll a = ps[i][j];
            ll b = ps[i][n] - a;
            ll c = ps[n][j] - a;
            ll d = ps[n][n] - b - c - a;
            ans = min(ans, max(max(a, b), max(c, d)));
        }
    }
    cout << ans;
}
