// find all possible totals we can create using efficient recursion with memory. keep track of min # of moves.
// loop through 2x2 array, check if moves <= k, if so update ans.

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

void setIO(string name = "pails") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int sz = 201;

ll x, y, k, m;
ll check[sz][sz];
bool found[sz][sz];

void move1(ll a, ll b, ll moves);
void move2(ll a, ll b, ll moves);
void move3(ll a, ll b, ll moves);

void move1(ll a, ll b, ll moves) {
    if (!found[x][b] || check[x][b] > moves + 1) {
        found[x][b] = true;
        check[x][b] = moves + 1;
        move1(x, b, moves + 1);
        move2(x, b, moves + 1);
        move3(x, b, moves + 1);
    }
    if (!found[a][y] || check[a][y] > moves + 1) {
        found[a][y] = true;
        check[a][y] = moves + 1;
        move1(a, y, moves + 1);
        move2(a, y, moves + 1);
        move3(a, y, moves + 1);
    }
}

void move2(ll a, ll b, ll moves) {
    if (!found[0][b] || check[0][b] > moves + 1) {
        found[0][b] = true;
        check[0][b] = moves + 1;
        move1(0, b, moves + 1);
        move2(0, b, moves + 1);
        move3(0, b, moves + 1);
    }
    if (!found[a][0] || check[a][0] > moves + 1) {
        found[a][0] = true;
        check[a][0] = moves + 1;
        move1(a, 0, moves + 1);
        move2(a, 0, moves + 1);
        move3(a, 0, moves + 1);
    }
}

void move3(ll a, ll b, ll moves) {
    ll m1 = max(0LL, a - (y - b));
    ll m2 = max(b - (x - a), 0LL);
    if (!found[m1][b + a - m1] || check[m1][b + a - m1] > moves + 1) {
        found[m1][b + a - m1] = true;
        check[m1][b + a - m1] = moves + 1;
        move1(m1, b + a - m1, moves + 1);
        move2(m1, b + a - m1, moves + 1);
        move3(m1, b + a - m1, moves + 1);
    }
    if (!found[a + b - m2][m2] || check[a + b - m2][m2] > moves + 1) {
        found[a + b - m2][m2] = true;
        check[a + b - m2][m2] = moves + 1;
        move1(a + b - m2, m2, moves + 1);
        move2(a + b - m2, m2, moves + 1);
        move3(a + b - m2, m2, moves + 1);
    }
}

int main()
{
    setIO();
    cin >> x >> y >> k >> m;
    move1(0, 0, 0);
    move2(0, 0, 0);
    move3(0, 0, 0);
    ll ans = m;
    rep(i, 0, 201) {
        rep(j, 0, 201) {
            if (found[i][j] && check[i][j] <= k) {
                ans = min(ans, abs(m - (i + j)));
            }
        }
    }
    cout << ans << endl;
}
