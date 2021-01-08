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

void setIO(string name = "closing") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

ll n, q, c;
vector<ll> root;
vector<ll> height;
vector<vector<ll>> edges;
vector<ll> order;
vector<string> ans;

void init() {
    rsz(root, n);
    rsz(height, n);
    c = 0;
    rep(i, 0, n) {
        root[i] = i;
        height[i] = 0;
    }
}

ll find(ll node) {
    if (root[node] != node)
        root[node] = find(root[node]);
    return root[node];
}

void join(ll a, ll b) {
    ll rootA = find(a);
    ll rootB = find(b);
    if (rootA == rootB) return;
    if (height[rootA] > height[rootB]) {
        root[rootB] = rootA;
        height[rootA] = max(height[rootA], height[rootB] + 1);
    }
    else {
        root[rootA] = rootB;
        height[rootB] = max(height[rootB], height[rootA] + 1);
    }
    --c;
}

int main()
{
    setIO();
    cin >> n >> q;
    rsz(edges, n);
    rep(i, 0, q) {
        ll a, b; cin >> a >> b;
        --a; --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    rep(i, 0, n) {
        ll a; cin >> a;
        --a;
        order.push_back(a);
    }
    reverse(all(order));
    init();
    unordered_set<ll> curr;
    rep(i, 0, n) {
        curr.insert(order[i]);
        ++c;
        for (ll edge : edges[order[i]])
            if (curr.count(edge)) join(edge, order[i]);
        if (c == 1)
            ans.push_back("YES");
        else
            ans.push_back("NO");
    }
    reverse(all(ans));
    rep(i, 0, n)
        cout << ans[i] << endl;
}
