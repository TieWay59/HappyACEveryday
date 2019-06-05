#include<stdio.h>
#include<algorithm>

using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll ans[N];
int n;
int num[N], cnt;

const int mod = 1e9 + 7;

ll fpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

struct Node {
    int b, f;
    ll d;

    bool operator<(const Node &x) const {
        if (b == x.b)return f > x.f;
        return b < x.b;
    }
} e[N];

void update(int x, ll v) {
    while (x < N) {
        ans[x] = max(ans[x], v);
        x += x & -x;
    }
}

ll query(int x) {
    ll res = 0;
    while (x) {
        res = max(ans[x], res);
        x -= x & -x;
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %lld", &e[i].b, &e[i].f, &e[i].d);
        num[++cnt] = e[i].f;
    }
    //num[++cnt]=0;
    sort(num + 1, num + cnt + 1);
    cnt = unique(num + 1, num + 1 + cnt) - num - 1;
    sort(e + 1, e + 1 + n);

    int m = 1;
    for (int i = 2; i <= n; i++) {
        if (e[i].f == e[m].f && e[i].b == e[m].b)
            e[m].d += e[i].d;
        else
            e[++m] = e[i];
    }//ȥ��
    n = m;
    for (int i = 1; i <= n; i++)//��ɢ��f
        e[i].f = lower_bound(num + 1, num + cnt + 1, e[i].f) - num;
    for (int i = 1; i <= n; i++)
        update(e[i].f, query(e[i].f - 1) + e[i].d);
    printf("%lld\n", query(N - 1));//���lld
    return 0;
}
