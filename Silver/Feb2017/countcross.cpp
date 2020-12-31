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

void setIO(string name = "countcross") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int length = 199;
ll n, k, r;
ll board[length][length];
bool visited[length][length];
ll cnt = 0;
ll rcodes[length / 2 + 1][length / 2 + 1];

void dfs(ll x, ll y, ll px, ll py) {
    if (x < 0 || x >= 2 * n || y < 0 || y >= 2 * n || visited[x][y] || board[(x + px) / 2][(y + py) / 2])
        return;
    visited[x][y] = true;
    rcodes[x / 2][y / 2] = cnt;
    vector<ll> dir = { 0, 2, 0, -2, 0 };
    rep(i, 0, 4) {
        ll dx = x + dir[i];
        ll dy = y + dir[i + 1];
        dfs(dx, dy, x, y);
    }
}

int main()
{
    setIO();
    cin >> n >> k >> r;
    rep(i, 0, r) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1; --y1; --x2; --y2;
        board[x1 + x2][y1 + y2] = 1;
    }
    for (ll i = 0; i < 2 * n; i += 2) {
        for (ll j = 0; j < 2 * n; j += 2) {
            if (!visited[i][j]) {
                ++cnt;
                dfs(i, j, i, j);
            }
        }
    }
    vector<pair<ll, ll>> cows;
    rep(i, 0, r) {
        ll x, y; cin >> x >> y;
        cows.push_back({ x - 1, y - 1 });
    }
    ll ans = 0;
    rep(i, 0, k) {
        rep(j, i + 1, k) {
            if (rcodes[cows[i].first][cows[i].second] != rcodes[cows[j].first][cows[j].second])
                ++ans;
        }
    }
    cout << ans << endl;
}
