// essentially just working backwards. learned to remember not to make expensive copies (ie copying a vector takes O(n) time).

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

void setIO(string name = "cereal") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main()
{
    setIO();
    ll n, m; cin >> n >> m;
    vector<pair<ll, ll>> fs(n);
    rep(i, 0, n) {
        ll a, b; cin >> a >> b;
        --a; --b;
        fs[i].first = a;
        fs[i].second = b;
    }
    vector<pair<ll, ll>> nrps(m);
    vector<ll> sum(n + 1);
    rep(i, 0, n) {
        sum[i + 1] = sum[i];
        ll curr = fs[n - (i + 1)].first;
        ll ci = n - (i + 1);
        while (nrps[curr].first && ci < nrps[curr].second) {
            ll c = nrps[curr].second;
            nrps[curr].second = ci;
            if (curr == fs[c].first) {
                curr = fs[c].second;
                ci = c;
            }
        }
        if (nrps[curr].first == 0) {
            nrps[curr].first = 1;
            nrps[curr].second = ci;
            ++sum[i + 1];
        }
    }
    rep(i, 0, n) {
        cout << sum[n - i] << endl;
    }
}
