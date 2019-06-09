
#define _debug(x) cerr<<#x<<" = "<<(x)<<endl;fflush(stdout)

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 7e5 + 77;

struct node {
    ll x, k;

    bool operator<(const node &T) const {
        return x < T.x;
    }
};

ll ans, tmp;
ll n, m;
node a[maxn];

inline void addNode(const ll &p, const ll &k) {
    a[m++] = {p, k};
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (ll u, v, i = 0; i < n; ++i) {
        cin >> u >> v;
        //if (u > v)swap(u, v);
        tmp += abs(v - u);

        if (u >= 0 && v >= 0) {//==?
            if (u * 2 < v) {
                addNode(u * 2, -1);
                addNode(v, 2);
                addNode(v * 2 - u * 2, -1);
            }
        } else if (u < 0 && v < 0) {
            if (u * 2 > v) {
                addNode(v * 2 - u * 2, -1);
                addNode(v, 2);
                addNode(u * 2, -1);
            }
        } else {
            addNode(0, -1);
            addNode(v, 2);
            addNode(v * 2, -1);
        }
    }
    sort(a, a + m);
    vector<node> dots;

    for (ll i = 0; i < m; ++i) {
        if (dots.empty() || dots.rbegin()->x != a[i].x) {
            dots.emplace_back(a[i]);
        } else {
            dots.rbegin()->k += a[i].k;
        }
    }

    ans = tmp;
    ll lasK = 0;
    ll curPos;
    ll lasPos = LLONG_MIN;

    for (const auto &dot:dots) {
        curPos = dot.x;
        tmp += lasK * (curPos - lasPos);
        lasPos = curPos;
        lasK += dot.k;
        ans = min(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}

/*
 3
-5 -7
-3 10
-2 7

 //10

 * */


