
#define _debug(x) cerr<<#x<<" = "<<(x)<<endl;fflush(stdout)

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 7e5 + 77;
const int inf = 1e9;

int Kase;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //cin >> Kase;
    //while (Kase--) {
    int n;
    cin >> n;
    vector<ull> a(n);
    map<ull, bool> mp;

    int mxexp = 0;
    ull tmp = inf;
    for (auto &ai:a) {
        cin >> ai;
        mp[ai] = true;
        ull t = ai;
        int exp = 0;
        while (t % 3 == 0llu) {
            t /= 3;
            exp++;
        }
        if (exp > mxexp) {
            tmp = ai;
        } else if (exp == mxexp) {
            tmp = min(tmp, ai);
        }
    }

    cout << tmp;
    while ((tmp % 3 == 0 && mp[tmp / 3]) || mp[tmp * 2]) {
        if (tmp % 3 == 0 && mp[tmp / 3]) {
            tmp /= 3;
        } else {
            tmp *= 2;
        }
        cout << " " << tmp;
    }
    //}
    return 0;
}


/*
2
10000 30000


 */


