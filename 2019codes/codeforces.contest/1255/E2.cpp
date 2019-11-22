#include <bits/stdc++.h>

#define  debug(x)  cerr <<#x << " = "<<x<<'\n'
using namespace std;
typedef long long ll;

const ll MAXN = 1e6 + 59;
int kase, n;
ll a[MAXN];
ll b[MAXN];
ll cnt;
ll fector[MAXN], num;
ll stk[MAXN], top;
ll pre[MAXN];

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    //cin>>n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        //cin>>a[i];
        scanf("%lld", a + i);
        cnt += a[i];
    }

    //debug(cnt);

    if (cnt == 1) {
        puts("-1");
        //cout<<-1<<'\n';
        return 0;
    }

    for (ll i = 2; i * i <= cnt; i++) {
        if (cnt % i == 0) {
            fector[++num] = i;
            while (cnt % i == 0) {
                cnt /= i;
            }
        }
    }

    if (cnt > 1) {
        fector[++num] = cnt;
    }

    //debug(num);

    ll ans = 0x3f3f3f3f3f3f3f3f;
    for (ll fi = 1, f, tmp; fi <= num; fi++) {

        f = fector[fi];

        //debug(fi);
        //debug(f);

        tmp = 0;
        top = 0;
        for (int i = 1; i <= n + 1; i++) {
            b[i] = a[i];
            if (b[i] > 0) {

                stk[++top] = i;
                pre[top] = pre[top - 1] + b[i];

                if (pre[top] >= f) {

                    ll d = -1;
                    for (ll k = 1; k <= top; k++) {

                        //	debug(pre[k]);

                        if (pre[k] > f / 2) {
                            d = stk[k];
                            break;
                        }
                    }
                    //debug(d);

                    ll res = pre[top] - f;
                    int resid = stk[top];
                    b[resid] -= res;

                    while (top) {

                        tmp += b[stk[top]] * abs(d - stk[top]);
                        top--;
                    }

                    if (res % f > 0) {
                        b[resid] = res % f;
                        stk[++top] = resid;
                        pre[top] = pre[top - 1] + b[resid];
                    }
                    //	debug(tmp);
                }
            }
            if (tmp > ans) {
                top = 0;
                break;
            }
        }
        //debug(tmp);
        ans = min(ans, tmp);
    }
    printf("%lld\n", ans);
    //cout<<ans<<'\n';
    return 0;
}

/*
 
 */
