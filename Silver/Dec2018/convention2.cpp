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

void setIO(string name = "convention2") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

struct cow {
    ll a, t, p;
};

struct cmpPriority {
    bool operator()(cow const& x, cow const& y) {
        return x.p > y.p;
    }
};

bool cmpTime(const cow& x, const cow& y) {
    return x.a < y.a;
}

int main() {
    setIO();
    ll n; cin >> n;
    vector<cow> vpl(n);
    map<ll, vector<cow>> mp;
    priority_queue<cow, vector<cow>, cmpPriority> pq;
    rep(i, 0, n) {
        cow c; cin >> c.a >> c.t;
        c.p = i;
        vpl[i] = c;
        mp[c.a].push_back(c);
    }
    sort(all(vpl), cmpTime);
    ll ans = 0;
    ll lt = 0;
    lt = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (lt >= it->second[0].a) {
            for (cow c : it->second) {
                pq.push(c);
            }
        }
        else {
            while (pq.size() && lt < it->second[0].a) {
                if (pq.top().a >= lt) {
                    lt = pq.top().a + pq.top().t;
                }
                else if (pq.top().a < lt) {
                    ans = max(ans, lt - pq.top().a);
                    lt += pq.top().t;
                }
                pq.pop();
            }
            for (cow c : it->second) {
                pq.push(c);
            }
        }
    }
    cout << ans << endl;
}
