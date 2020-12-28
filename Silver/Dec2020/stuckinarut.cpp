#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;

#define pb push_back
#define all(x) begin(x), end(x)
#define f first
#define s second

ll n;
vector<ll> vals;
vector<bool> works;
vector<pair<bool, ll>> stopped;
vector<ll> dir;
vector<pair<pair<ll, ll>, pair<pair<ll, ll>, pair<ll, ll>>>> isecs;
vector<pair<ll, ll>> coords;
map<ll, ll> blame;

int main() {
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        char d; cin >> d;
        ll x, y; cin >> x >> y;
        if (d == 'E') {
            dir.push_back(0);
        }
        else {
            dir.push_back(1);
        }
        vals.push_back(0);
        stopped.push_back({ false, -1 });
        coords.push_back({ x, y });
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (i != j && dir[i] != dir[j]) {
                ll ix = 0, iy = 0;
                ll x1 = coords[i].first, x2 = coords[j].first;
                ll y1 = coords[i].second, y2 = coords[j].second;
                if (dir[i] == 0) {
                    if (x1 <= x2 && y1 >= y2) {
                        ix = x2; iy = y1;
                        if (x2 - x1 != y1 - y2) {
                            ll time = 0;
                            ll cow = 0;
                            if (x2 - x1 > y1 - y2) {
                                cow = i;
                                time = x2 - x1;
                            }
                            else {
                                cow = j;
                                time = y1 - y2;
                            }
                            isecs.push_back({ {time, cow}, { {ix, iy}, {i, j} } });
                            works.push_back(false);
                        }
                    }
                }
            }
        }
    }
    sort(all(isecs));
    for (ll i = 0; i < isecs.size(); ++i) {
        ll cow = isecs[i].first.second;
        ll time = isecs[i].first.first;
        ll fcow = isecs[i].second.second.first;
        ll scow = isecs[i].second.second.second;
        ll ix = isecs[i].second.first.first;
        ll iy = isecs[i].second.first.second;
        if (cow == fcow && !stopped[fcow].first) {
            if (!stopped[scow].first || stopped[scow].second > iy - coords[scow].second) {
                blame[fcow] = scow;
                stopped[fcow].first = true;
                stopped[fcow].second = time;
            }
        }
        else if (cow == scow && !stopped[scow].first) {
            if (!stopped[fcow].first || stopped[fcow].second > ix - coords[fcow].first) {
                blame[scow] = fcow;
                stopped[scow].first = true;
                stopped[scow].second = time;
            }
        }
    }
    for (auto it = blame.begin(); it != blame.end(); ++it) {
        ll cow = it->second;
        while (blame.count(cow) == 1) {
            vals[cow]++;
            cow = blame[cow];
        }
        vals[cow]++;
    }
    for (ll i = 0; i < vals.size(); ++i) {
        cout << vals[i] << endl;
    }
}
