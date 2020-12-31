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

void setIO(string name = "where") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

ll n;
char board[20][20];
ll cx1 = 0, cx2 = 0, cy1 = 0, cy2 = 0;
bool visited[20][20];

void dfs(ll i, ll j) {
    if (i < cx1 || i > cx2 || j < cy1 || j > cy2 || visited[i][j])
        return;
    visited[i][j] = true;
    vector<ll> dir = { 0, 1, 0, -1, 0 };
    rep(k, 0, 4) {
        ll dx = i + dir[k];
        ll dy = j + dir[k + 1];
        if (board[dx][dy] == board[i][j]) dfs(dx, dy);
    }
}

bool check(ll x1, ll y1, ll x2, ll y2) {
    cx1 = x1; cx2 = x2; cy1 = y1; cy2 = y2;
    rep(i, x1, x2 + 1) {
        rep(j, y1, y2 + 1)
            visited[i][j] = false;
    }
    map<char, ll> mp;
    rep(i, x1, x2 + 1) {
        rep(j, y1, y2 + 1) {
            if (!visited[i][j]) {
                mp[board[i][j]]++;
                if (mp.size() > 2)
                    return false;
                dfs(i, j);
            }
        }
    }
    if (mp.size() != 2) return false;
    if ((mp.begin()->second == 1 && mp.rbegin()->second > 1)
        || (mp.begin()->second > 1 && mp.rbegin()->second == 1)) {
        return true;
    }
    return false;
}

int main()
{
    setIO();
    cin >> n;
    vector<pair<pair<ll, ll>, pair<ll, ll>>> sols;
    rep(i, 0, n) {
        rep(j, 0, n)
            cin >> board[i][j];
    }
    rep(i, 0, n) {
        rep(j, 0, n) {
            rep(k, i, n) {
                rep(l, j, n) {
                    if (check(i, j, k, l)) {
                        vector<pair<pair<ll, ll>, pair<ll, ll>>> nsols;
                        bool canpush = true;
                        rep(m, 0, sols.size()) {
                            ll sx1 = sols[m].first.first;
                            ll sy1 = sols[m].first.second;
                            ll sx2 = sols[m].second.first;
                            ll sy2 = sols[m].second.second;
                            if (sx1 >= i && sy1 >= j && sx2 <= k && sy2 <= l) goto next;
                            if (sx1 <= i && sy1 <= j && sx2 >= k && sy2 >= l) {
                                canpush = false;
                                nsols.push_back({ {sx1, sy1}, {sx2, sy2 } });
                            }
                            else
                                nsols.push_back({ {sx1, sy1}, {sx2, sy2 } });
                        next:;
                        }
                        if (canpush) nsols.push_back({ {i, j}, {k, l} });
                        sols = nsols;
                    }
                }
            }
        }
    }
    cout << sols.size() << endl;
}
