#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "reststops") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO();
    ll l, n, rf, rb; cin >> l >> n >> rf >> rb;
    ll diff = rf - rb;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<pair<ll, ll>> stops;
    for (ll i = 0; i < n; ++i) {
        ll a, b; cin >> a >> b;
        stops.pb({ a, b });
    }
    vector<pair<ll, ll>> rests;
    rests.pb(stops[n - 1]);
    for (ll i = n - 1; i >= 0; --i) {
        if (stops[i].second > rests[rests.size() - 1].second) {
            rests.pb(stops[i]);
        }
    }
    ll last = 0;
    ll ans = 0;
    for (ll i = rests.size() - 1; i >= 0; --i) {
        ll distance = rests[i].first - last;
        ll time = distance * diff;
        ans += time * rests[i].second;
        last = rests[i].first;
    }
    cout << ans << endl;
}
