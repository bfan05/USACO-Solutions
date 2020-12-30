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

void setIO(string name = "lightson") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

ll n, m;
map<pair<ll, ll>, vector<pair<ll, ll>>> mp;
vector<vector<ll>> lightson;
vector<vector<bool>> visited;
bool fnew = true;

void dfs(ll i, ll j) {
    if (i < 0 || i >= n || j < 0 || j >= n || !lightson[i][j] || visited[i][j])
        return;
    visited[i][j] = true;
    for (pair<ll, ll> &cd : mp[{ i, j }]) {
        if (!lightson[cd.first][cd.second]) {
            fnew = true;
            lightson[cd.first][cd.second] = 1;
        }
    }
    ll dir[] = { 0, 1, 0, -1, 0 };
    rep(k, 0, 4) {
        ll dx = i + dir[k];
        ll dy = j + dir[k + 1];
        dfs(dx, dy);
    }
}

int main()
{
    setIO();
    cin >> n >> m;
    rsz(lightson, n);
    rsz(visited, n);
    rep(i, 0, m) {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        --a; --b; --c; --d;
        mp[{a, b}].push_back({ c, d });
    }
    rep(i, 0, n) {
        rep(j, 0, n) {
            lightson[i].push_back(0);
            visited[i].push_back(false);
        }
    }
    lightson[0][0] = 1;
    while (fnew) {
        fnew = false;
        visited.clear();
        rsz(visited, n);
        rep(i, 0, n) {
            rep(j, 0, n)
                visited[i].push_back(false);
        }
        dfs(0, 0);
    }
    ll ans = 0;
    rep(i, 0, n) {
        rep(j, 0, n)
            if (lightson[i][j]) ++ans;
    }
    cout << ans << endl;
}
