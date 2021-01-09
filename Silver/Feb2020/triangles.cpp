#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

using vi = vector<int>;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for(ll i = a; i < b; ++i)
#define rsz(x, n) x.resize(n)

using pi = pair<int, int>;
#define f first
#define s second

void setIO(string name = "triangles") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main()
{
    setIO();
    ll n; cin >> n;
    vector<pair<ll, ll>> coords;
    map<ll, vector<ll>> xsame;
    map<ll, vector<ll>> ysame;
    rep(i, 0, n) {
        ll x, y; cin >> x >> y;
        xsame[x].push_back(y);
        ysame[y].push_back(x);
        coords.push_back({ x, y });
    }
    map<pair<ll, ll>, ll> xsums;
    map<pair<ll, ll>, ll> ysums;
    for (auto it = xsame.begin(); it != xsame.end(); ++it) {
        vector<ll> v = it->second;
        ll x = it->first;
        sort(all(v));
        ll sum = 0;
        for (auto num : v)
            sum += num - v[0];
        ysums[{x, v[0]}] = sum;
        rep(i, 1, v.size())
            ysums[{x, v[i]}] = ysums[{x, v[i - 1]}] + (2 * i - v.size()) * (v[i] - v[i - 1]);
    }
    for (auto it = ysame.begin(); it != ysame.end(); ++it) {
        vector<ll> v = it->second;
        ll y = it->first;
        sort(all(v));
        ll sum = 0;
        for (auto num : v)
            sum += num - v[0];
        xsums[{v[0], y}] = sum;
        rep(i, 1, v.size())
            xsums[{v[i], y}] = xsums[{v[i - 1], y}] + (2 * i - v.size()) * (v[i] - v[i - 1]);
    }
    ll ans = 0;
    rep(i, 0, n) {
        ans += xsums[coords[i]] * ysums[coords[i]];
        ans %= MOD;
    }
    cout << ans << endl;
}
