using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define rep(i, a, b) for(ll i = a; i < b; ++i)

using pi = pair<int, int>;
#define f first
#define s second

void setIO(string name = "cowdance") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

ll n, t;
vector<ll> times;

bool check(ll k) {
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll curr = 0;
    rep(i, 0, n) {
        if (pq.size() == k) {
            curr = pq.top();
            pq.pop();
        }
        pq.push(curr + times[i]);
        if (curr + times[i] > t) return false;
    }
    return true;
}

int main() {
    setIO();
    cin >> n >> t;
    times.resize(n);
    rep(i, 0, n)
        cin >> times[i];
    ll l = 1, r = n;
    if (check(l)) {
        cout << 1 << endl;
        return 0;
    }
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << r << endl;
}
