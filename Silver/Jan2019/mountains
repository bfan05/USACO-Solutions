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

void setIO(string name = "mountains") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

bool intersect(int x1, int y1, int x2, int y2) {
    if (x2 >= (x1 - y1) && x2 <= (x1 + y1) && y2 <= (-x2 + y1 + x1) && y2 <= (x2 + y1 - x1)) {
        return true;
    }
    return false;
}

int main() {
    setIO();
    int n; cin >> n;
    vector<pair<int, int>> coords;
    set<int> xcords;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        coords.push_back({ x, y });
        xcords.insert(x);
    }
    sort(all(coords));
    vector<pair<int, int>> visible;
    visible.push_back({ coords[0].first, coords[0].second });
    for (int i = 1; i < n; ++i) {
        vector<pair<int, int>> temp;
        bool works = true;
        int x1 = coords[i].first, y1 = coords[i].second;
        for (int j = 0; j < visible.size(); ++j) {
            int x2 = visible[j].first, y2 = visible[j].second;
            if (!intersect(x1, y1, x2, y2)) {
                temp.push_back({ x2, y2 });
            }
            if (intersect(x2, y2, x1, y1)) {
                works = false;
            }
        }
        if (works) {
            temp.push_back({ x1, y1 });
        }
        visible = temp;
    }
    cout << visible.size() << endl;
}
