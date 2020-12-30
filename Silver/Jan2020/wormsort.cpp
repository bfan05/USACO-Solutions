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

void setIO(string name = "wormsort") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

struct wormhole {
    ll a, b, w;
};

ll n, m;
vector<ll> pos;
vector<wormhole> wholes;
vector<vector<ll>> edges;
vector<bool> visited;
bool works = false;
ll curr = -1;
ll cnt = 0;
vector<ll> codes;

bool cmp(const wormhole& x, const wormhole& y) {
    return x.w < y.w;
}

void dfs(ll node) {
    codes[node] = cnt;
    for (ll neighbor : edges[node])
        if (codes[neighbor] == 0) dfs(neighbor);
}

bool check(ll maxw) {
    edges.clear();
    rsz(edges, n);
    rep(i, 0, m) {
        if (wholes[i].w >= maxw) {
            edges[wholes[i].a].push_back(wholes[i].b);
            edges[wholes[i].b].push_back(wholes[i].a);
        }
    }
    codes.clear();
    codes.resize(n, 0);
    cnt = 0;
    rep(i, 0, n) {
        if (codes[i] == 0) {
            ++cnt;
            dfs(i);
        }
    }
    rep(i, 0, n)
        if (codes[i] != codes[pos[i]]) return false;
    return true;
}

int main() {
    setIO();
    cin >> n >> m;
    rsz(pos, n);
    rsz(wholes, m);
    bool tworks = true;
    rep(i, 0, n) {
        cin >> pos[i];
        pos[i]--;
        if (i != pos[i]) tworks = false;
    }
    if (tworks) {
        cout << -1 << endl;
        return 0;
    }
    rep(i, 0, m) {
        wormhole whole;
        ll a, b, w; cin >> a >> b >> w;
        --a; --b;
        whole.a = a; whole.b = b; whole.w = w;
        wholes[i] = whole;
    }
    sort(all(wholes), cmp);
    ll l = 0, r = wholes[m - 1].w + 1;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
}
