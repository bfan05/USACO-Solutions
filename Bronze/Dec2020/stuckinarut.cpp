#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

vector<ll> ans;
ll n;
vector<ll> direc;
vector<pair<ll, ll>> coords;
vector<pair<bool, ll>> stopped;
vector<pair<pair<ll, ll>, pair<pair<ll, ll>, pair<ll, ll>>>> pos;
vector<bool> valid;

int main() {
    setIO();
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        char d; cin >> d;
        ll x, y; cin >> x >> y;
        if (d == 'E')
            direc.push_back(0);
        else
            direc.push_back(1);
        coords.push_back({ x, y });
        stopped.push_back({ false, -1 });
        ans.push_back(0);
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (i != j && direc[i] != direc[j]) {
                ll ix = 0, iy = 0;
                ll x1 = coords[i].first, x2 = coords[j].first;
                ll y1 = coords[i].second, y2 = coords[j].second;
                if (direc[i] == 0) {
                    if (x1 <= x2 && y1 >= y2) {
                        ix = x2; iy = y1;
                        if (x2 - x1 != y1 - y2) {
                            ll time = 0;
                            ll cow = 0;
                            if (x2 - x1 < y1 - y2) {
                                time = y1 - y2;
                                cow = j;
                            }
                            else {
                                time = x2 - x1;
                                cow = i;
                            }
                            // time, cow that stops, intersection coords, the two cows
                            pos.push_back({ {time, cow}, { {ix, iy}, {i, j} } });
                            valid.push_back(false);
                        }
                    }
                }
            }
        }
    }
    sort(all(pos));
    for (ll i = 0; i < pos.size(); ++i) {
        ll time = pos[i].first.first;
        ll cow = pos[i].first.second;
        ll ix = pos[i].second.first.first;
        ll iy = pos[i].second.first.second;
        ll fcow = pos[i].second.second.first;
        ll scow = pos[i].second.second.second;
        if (cow == fcow && !stopped[fcow].first) {
            if (!stopped[scow].first || stopped[scow].second > iy - coords[scow].second) {
                ans[fcow] = time;
                stopped[fcow].first = true;
                stopped[fcow].second = time;
            }
        }
        else if (cow == scow && !stopped[scow].first) {
            if (!stopped[fcow].first || stopped[fcow].second > ix - coords[fcow].first) {
                ans[scow] = time;
                stopped[scow].first = true;
                stopped[scow].second = time;
            }
        }
    }
    for (ll i = 0; i < ans.size(); ++i) {
        if (ans[i] == 0) {
            cout << "Infinity" << endl;
        }
        else {
            cout << ans[i] << endl;
        }
    }
}
