// https://nanti.jisuanke.com/t/41097
#include<bits/stdc++.h>
#include <tuple>

#define _debug(x) cerr<<#x<<" = "<<x<<endl
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 59;
//const int N = 2e5 + 59;
//const int MAXM = 4e5 + 59;


/* Author: bnfcc -> tc2000731 -> tieway59
 * Description:
 *  维护下凸包，对于每个x维护f(x)=k*x+b的最大值。
 *  find max value within all f(x) functions.
 * Problems:
 *  https://nanti.jisuanke.com/t/41306
 *  https://nanti.jisuanke.com/t/41097
 *
 */
template<typename var=long long, const int SIZE = MAXN, typename ldb=long double>
struct Hull {
    struct Line {
        var k, b;

        Line() {}

        Line(var k, var b) : k(k), b(b) {}

        var f(var x) { return k * x + b; }
    };

    int cnt;
    vector<Line> con;//

    bool empty() {
        return cnt == 0;
    }

    void init(const int &n) {
        con.clear();
        if (n > con.capacity())con.reserve(n);
        cnt = 0;
    }

    void add(const Line &p) {
        con.emplace_back(p);
        cnt++;
    }

    void pop() {
        cnt--;
        con.pop_back();
    }

    bool chek(const Line &a, const Line &b, const Line &c) {
        ldb ab, ak, bb, bk, cb, ck;
        tie(ab, ak, bb, bk, cb, ck) =
                tie(a.b, a.k, b.b, b.k, c.b, c.k);
        return (ab - bb) / (bk - ak) > (ab - cb) / (ck - ak);
    }

    void insert(const Line &p) {///k从小到大插入
        if (cnt && con[cnt - 1].k == p.k) {
            if (p.b <= con[cnt - 1].b)return;
            else pop();
        }
        while (cnt >= 2 && chek(con[cnt - 2], con[cnt - 1], p))pop();
        add(p);
    }

    var query(var x) {///二分查询，x顺序任意
        int l = 0, r = cnt - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (con[mid].f(x) >= con[mid + 1].f(x))r = mid;
            else l = mid + 1;
        }
        return con[l].f(x);
    }
};

Hull<> hull;

int kase;
ll n, q;
ll to1[MAXN];
ll toi[MAXN];
ll ans[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> kase;
    while (kase--) {
        cin >> n >> q;
        hull.init(n);
        fill(toi, toi + n + 5, 0);
        fill(to1, to1 + n + 5, 0);
        for (int i = 2; i <= n; i++) {
            cin >> to1[i];
        }
        for (int i = 2; i <= n - 1; i++) {
            cin >> toi[i];
        }
        for (int i = n - 1; i >= 2; i--) {
            toi[i] += toi[i + 1];
        }
        for (int i = 2; i <= n; i++) {
            hull.insert({-(n - i + 1), -to1[i] - toi[i]});
        }
        for (ll i = 1, qi; i <= q; i++) {
            cin >> qi;
            ans[i] = hull.query(qi);
        }
        for (int i = 1; i <= q; i++) {
            cout << -ans[i] << " \n"[i == q];
        }
    }
    return 0;
}
/*


 * */