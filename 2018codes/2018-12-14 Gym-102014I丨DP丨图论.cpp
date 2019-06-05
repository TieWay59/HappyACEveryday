#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<numeric>

using namespace std;
typedef long long ll;
typedef vector<int> vint;
const int INF = 0x3F3F3F3F;

int main() {
    int n;
    while (cin >> n, n) {
        vint a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans = 0;

        vint p[555];
        for (int x, i = 0; i < n; i++) {
            x = a[i];
            while (~x & 1)x >>= 1;
            p[x].emplace_back(a[i] / x);
        }
        auto calc = [](vint &v) {
            int sum = accumulate(v.begin(), v.end(), 0);
            vint dp(sum + 1, -1);
            dp[0] = 0;
            for (int x:v)
                for (int i = sum / x * x; i > 0; i -= x)
                    if (~dp[i - x])
                        dp[i] = max(dp[i], dp[i - x] + 1);
            //building a tree
            int res = 0;
            for (int i = 1; i <= sum; i <<= 1)
                res = max(res, dp[i]);
            return res;
        };

        for (vint v:p)
            if (!v.empty())
                ans = max(ans, calc(v));
        cout << ans << endl;
    }
    return 0;
}
/*
*/
