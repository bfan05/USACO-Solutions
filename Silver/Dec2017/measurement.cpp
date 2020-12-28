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

void setIO(string name = "measurement") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO();
    ll n, g; cin >> n >> g;
    vector<pair<ll, pair<ll, ll>>> vpl(n);
    multiset<ll> curr;
    rep(i, 0, n) {
        ll t, c, d;
        cin >> t >> c;
        char ch;
        cin >> ch >> d;
        if (ch == '-') {
            d *= -1;
        }
        vpl[i] = { t, {c, d} };
        curr.insert(0);
    }
    sort(all(vpl));
    ll m = 0;
    map<ll, ll> mp;
    ll ans = 0;
    rep(i, 0, n) {
        ll c = vpl[i].second.first;
        ll d = vpl[i].second.second;
        curr.erase(curr.find(mp[c]));
        mp[c] += d;
        curr.insert(mp[c]);
        if (mp[c] > m && curr.count(m) != 0) {
            ++ans;
        }
        else if (mp[c] == m) {
            ++ans;
        }
        else if (mp[c] - d == m) {
            if (curr.count(m) == 0) {
                auto it = curr.upper_bound(mp[c]);
                if (it != curr.end() || curr.count(mp[c]) > 1) {
                    ++ans;
                }
            }
            else {
                ++ans;
            }
        }
        m = *(curr.rbegin());
    }
    cout << ans << endl;
}
