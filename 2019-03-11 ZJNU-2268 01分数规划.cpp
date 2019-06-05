#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 257;
const ll INF = 0x3f3f3f3f;
int n, W;
int ans;
int w[MAXN], t[MAXN];
ll dp[1007];

bool check(ll v) {
    dp[0] = 0;
    for (int i = 1; i <= W; i++)
        dp[i] = -INF;
    for (int i = 1; i <= n; i++)
        for (int k, j = W; j >= 0; j--)
            k = min(j + w[i], W),
                    dp[k] = max(dp[j] + t[i] - v * w[i], dp[k]);
    if (dp[W] >= 0)return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> t[i];
        t[i] *= 1000;
    }
    ll mid, l = 0, r = 250005;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}
/*

    ios::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
*/
