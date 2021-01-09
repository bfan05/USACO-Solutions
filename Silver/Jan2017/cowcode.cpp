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

void setIO(string name = "cowcode") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

string str; 
ll n;
ll sz;
ll a;
ll cnt = 0;

char find(ll x) {
    if (x <= sz)
        return str[x - 1];
    ll b = sz;
    while (b * 2 < x) b *= 2;
    ll diff = x - b;
    --diff;
    if (diff == 0)
        diff = b;
    return find(diff);
}

int main()
{
    setIO();
    cin >> str >> n;
    sz = str.size();
    a = n / sz;
    while (a != 0) {
        ++cnt;
        a /= 2;
    }
    cout << find(n);
}
