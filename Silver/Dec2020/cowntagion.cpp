#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;

#define pb push_back
#define all(x) begin(x), end(x)
#define f first
#define s second

vector<vector<ll>> roads;
vector<ll> cows;
set<ll> infected;
ll ans = 0;

void recurse(ll i, ll last) {
    if (i != 0) {
        ans += ceil(log2(roads[i].size()));
    }
    else {
        ans += ceil(log2(roads[i].size() + 1));
    }
    for (ll j = 0; j < roads[i].size(); ++j) {
        if (roads[i][j] != last) {
            cows[roads[i][j]] = 1;
            ++ans;
            recurse(roads[i][j], i);
        }
    }
}

int main() {
    ll n; cin >> n;
    for (ll i = 0; i < n; ++i) {
        roads.push_back({});
        cows.push_back(0);
    }
    cows[0] = 1;
    infected.insert(0);
    for (ll i = 0; i < n - 1; ++i) {
        ll a, b; cin >> a >> b;
        --a; --b;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }
    recurse(0, 0);
    cout << ans << endl;
}
