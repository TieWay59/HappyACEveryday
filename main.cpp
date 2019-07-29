

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
#define rep(x, a, b) for(register int x=a;x<=b;x++)
#define _dbg(x) cout<<x<<'\n';
#define T(x) int T;scanf("%d",&T);rep(x,1,T)

const int N = 2e5 + 5;
ll a[N];
pli ls[N];
int ans[N], ind[N];

//template <typename _Tp> inline _Tp read(_Tp&x){
//    char c11=getchar(),ob=0;x=0;
//    while(c11^'-'&&!isdigit(c11))c11=getchar();if(c11=='-')c11=getchar(),ob=1;
//    while(isdigit(c11))x=x*10+c11-'0',c11=getchar();if(ob)x=-x;return x;
//}


#define val first
#define num second

pll tree[N << 2];

#define lson rt<<1
#define rson rt<<1|1

void build(int rt, int l, int r) {
    if (l == r) {
        tree[rt].num = 0;
        tree[rt].val = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    tree[rt].num = tree[rt].val = 0;
}

void update(int rt, int l, int r, int x) {
    if (l == r) {
        tree[rt].num++;
        tree[rt].val += ls[x].first;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)update(lson, l, mid, x);
    else update(rson, mid + 1, r, x);
    tree[rt].num = tree[lson].num + tree[rson].num;
    tree[rt].val = tree[lson].val + tree[rson].val;
}

ll k;

ll query(int rt, int l, int r, int x, ll v) {
    if (l == r) {
        ll tp = min(v / ls[l].first, tree[rt].num);
        k += tp;
        return tp * ls[l].first;
    } else if (tree[rt].val <= v) {
        k += tree[rt].num;
        return tree[rt].val;
    }
    int mid = (l + r) >> 1;
    ll ret = query(lson, l, mid, x, v);
    if (ret == tree[lson].val)ret += query(rson, mid + 1, r, x, v - ret);
    return ret;
}

int main() {
    T(ca) {
        int n;
        ll m;
        n = IO.nI();
        m = IO.nI();
        rep(i, 1, n) {
//            read(a[i]);
            a[i] = IO.nll();
            ls[i].first = a[i];
            ls[i].second = i;
        }
        sort(ls + 1, ls + 1 + n);
        rep(i, 1, n) {
            ind[ls[i].second] = i;
        }
        build(1, 1, n);
        rep(i, 1, n) {
            k = 0;
            ll tp = query(1, 1, n, ind[i], m - a[i]);
            printf("%d ", 1ll * i - 1ll - k);
            update(1, 1, n, ind[i]);
        }
        printf("\n");
    }
    return 0;
}



