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

void setIO(string name = "socdist") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

ll n, m;
vector<pair<ll, ll>> locs;

bool check(ll d) {
    ll lastloc = locs[0].first;
    ll lastp = 0;
    rep(i, 1, n) {
        if (lastloc + d <= locs[lastp].second)
            lastloc += d;
        else {
            ll nextpos = lastloc + d;
            while (lastp < m - 1 && locs[lastp + 1].second < nextpos) {
                ++lastp;
                if (lastp == m - 1)
                    return false;
            }
            if (lastp == m - 1)
                return false;
            lastp++;
            lastloc = max(locs[lastp].first, nextpos);
        }
    }
    return true;
}

int main() {
    setIO();
    cin >> n >> m;
    locs.resize(m);
    rep(i, 0, m) {
        ll a, b; cin >> a >> b;
        locs[i].first = a;
        locs[i].second = b;
    }
    sort(all(locs));
    ll l = 0, r = 1;
    while (check(r)) r *= 2;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
}
