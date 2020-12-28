#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)

using pi = pair<int, int>;
#define f first
#define s second

void setIO(string name = "lifeguards") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO();
    ll n; cin >> n;
    unordered_map<ll, pair<ll, ll>> lm;
    vector<ll> alone;
    vector<pair<pair<ll, ll>, ll>> vl;
    for (ll i = 0; i < n; ++i) {
        ll x, y; cin >> x >> y;
        lm[i] = { x, y };
        alone.push_back(0);
        vl.push_back({ {x, i}, 0 });
        vl.push_back({ {y, i}, 1 });
    }
    sort(all(vl));
    set<pair<ll, ll>> curr;
    ll total = 0;
    ll last = vl[0].first.first;
    ll a = vl[0].first.first;
    curr.insert({ vl[0].first.second, vl[0].first.first });
    for (ll i = 1; i < vl.size(); ++i) {
        if (vl[i].second == 0) {
            if (a != -1) {
                alone[(*curr.begin()).first] = vl[i].first.first - a;
                a = -1;
            }
            curr.insert({ vl[i].first.second, vl[i].first.first });
            if (curr.size() == 1) {
                a = vl[i].first.first;
                last = a;
            }
        }
        else {
            if (a != -1) {
                alone[vl[i].first.second] = vl[i].first.first - a;
                a = -1;
                total += vl[i].first.first - last;
            }
            curr.erase({ vl[i].first.second, lm[vl[i].first.second].first });
            if (curr.size() == 1) {
                a = vl[i].first.first;
            }
        }
    }
    sort(all(alone));
    cout << total - alone[0] << endl;
}
