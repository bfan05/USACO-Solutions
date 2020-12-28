#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)

using pi = pair<int, int>;
#define f first
#define s second

void setIO(string name = "rental") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

bool cmp(const pair<ll, ll>& x, const pair<ll, ll>& y) {
    return x.first > y.first;
}

ll n, m, r;

int main() {
    setIO();
    cin >> n >> m >> r;
    vector<ll> cows;
    // price, quantity
    vector<pair<ll, ll>> milk;
    vector<ll> rent;
    vector<ll> rps;
    ll quant = 0;
    for (ll i = 0; i < n; ++i) {
        ll cow; cin >> cow;
        cows.push_back(cow);
    }
    for (ll i = 0; i < m; ++i) {
        ll q, p; cin >> q >> p;
        milk.push_back({ p, q });
        quant += q;
    }
    for (ll i = 0; i < r; ++i) {
        ll rnt; cin >> rnt;
        rent.push_back(rnt);
    }
    sort(all(cows), greater<ll>());
    sort(all(milk), cmp);
    sort(all(rent), greater<ll>());
    rps.push_back(0);
    for (ll i = 0; i < r; ++i) {
        rps.push_back(rent[i] + rps[i]);
    }
    ll total = rps[min(n, r)];
    // store, gal
    pair<ll, ll> g = { 0, 0 };
    ll last = 0;
    for (ll i = 0; i < n; ++i) {
        ll tot = 0;
        if (g.first < m) {
            ll gbought = 0;
            while (g.first < m && gbought < cows[i]) {
                ll nxt = min(milk[g.first].second - g.second, cows[i] - gbought);
                tot += nxt * milk[g.first].first;
                if (nxt == milk[g.first].second - g.second) {
                    g.first++;
                    g.second = 0;
                }
                else {
                    g.second += cows[i] - gbought;
                }
                gbought += nxt;
            }
            last += tot;
            tot = last;
            tot += rps[min(n - i - 1, r)];
            total = max(tot, total);
        }
    }
    cout << total << endl;
}
