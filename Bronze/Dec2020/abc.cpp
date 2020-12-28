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

int main()
{
    vector<ll> nums;
    for (int i = 0; i < 7; ++i) {
        ll num;
        cin >> num;
        nums.push_back(num);
    }
    sort(all(nums));
    ll sum = nums[6];
    vector<ll> abc(3);
    abc[0] = nums[6] - nums[5];
    abc[1] = nums[6] - nums[4];
    abc[2] = nums[6] - (abc[0] + abc[1]);
    sort(all(abc));
    cout << abc[0] << " " << abc[1] << " " << abc[2];
}
