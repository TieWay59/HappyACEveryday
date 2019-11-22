#include <bits/stdc++.h>

#define  debug(x)  cerr <<#x << " = "<<x<<endl
using namespace std;
typedef long long ll;

const ll MAXN = 1e5 + 59;
int kase, n;
int a[MAXN];
ll cnt;
ll fector[MAXN], num;
ll stk[MAXN], top;

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

    ll ans = MAXN * MAXN;
    for (ll fi = 1, f, tmp; fi <= num; fi++) {
        f = fector[fi];
        tmp = 0;
        top = 0;
        //debug(f);
        for (int i = 1; i <= n + 1; i++) {
            if (a[i] == 1) {
                stk[++top] = i;
                if (top == f) {
                    ll d = stk[top / 2 + 1];
                    while (top) {
                        tmp += abs(d - stk[top]);
                        top--;
                    }
                    //debug(tmp);
                }
            }
            if (tmp > ans) {
                top = 0;
                break;
            }
        }
        ans = min(ans, tmp);
    }
    printf("%lld\n", ans);
    //cout<<ans<<'\n';
    return 0;
}

/*
 
 */
