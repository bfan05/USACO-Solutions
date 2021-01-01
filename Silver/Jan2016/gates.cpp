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

void setIO(string name = "gates") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int sz = 2000;

int n;
int board[sz][sz];
int cnt = 0;
int dir[] = { 0, 1, 0, -1, 0 };
int dx;
int dy;

void dfs(int i, int j) {
    if (i < 0 || i >= sz || j < 0 || j >= sz || board[i][j]) return;
    board[i][j] = 1;
    rep(k, 0, 4) {
        dx = i + dir[k];
        dy = j + dir[k + 1];
        dfs(dx, dy);
    }
}

int main()
{
    setIO();
    cin >> n;
    int cx = sz / 2;
    int cy = sz / 2;
    board[cx][cy] = 1;
    rep(i, 0, n) {
        char ch; cin >> ch;
        if (ch == 'N') {
            board[cx][cy + 1] = 1;
            board[cx][cy + 2] = 1;
            cy += 2;
        }
        else if (ch == 'E') {
            board[cx + 1][cy] = 1;
            board[cx + 2][cy] = 1;
            cx += 2;
        }
        else if (ch == 'S') {
            board[cx][cy - 1] = 1;
            board[cx][cy - 2] = 1;
            cy -= 2;
        }
        else {
            board[cx - 1][cy] = 1;
            board[cx - 2][cy] = 1;
            cx -= 2;
        }
    }
    rep(i, 0, sz) {
        rep(j, 0, sz) {
            if (!board[i][j]) {
                ++cnt;
                dfs(i, j);
            }
        }
    }
    cout << cnt - 1 << endl;
}
