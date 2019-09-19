//https://codeforces.com/contest/711/problem/D
#define _debug(x) cerr<<#x<<" = "<<x<<endl

#include <string.h>
#include <algorithm>
#include <iostream>
//#include "mycode/fastpower.h"

using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 7;
const ll MOD = 1e9 + 7;


long long fpow(long long a, long long b, long long m) {
    long long ret = 1;
    while (b) {
        if (b & 1)ret = ret * a % m;
        a = a * a % m;
        b >>= 1;
    }
//    _debug(ret);
    return ret;
}


struct Edge {
    int u, v, nx; // ,w
} e[MAXN << 1];

int head[MAXN], cntEd;

inline void addEdge(int u, int v) {
    e[cntEd] = {u, v, head[u]};
    head[u] = cntEd++;
}

//-----tarjan

int low[MAXN];
int dfn[MAXN], idx;
int stk[MAXN], top;
int scc[MAXN], sccnum;

void tarjan(int u) {
    //if (dfn[u]) return;
    dfn[u] = low[u] = ++idx;

    stk[++top] = u;

    for (int i = head[u]; ~i; i = e[i].nx) {
        int v = e[i].v;

        if (!dfn[v]) {    //如果v结点未访问过
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (!scc[v]) {    //如果还在栈内
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (low[u] == dfn[u]) {    //后代不能找到更浅的点
        sccnum++;
        int x;
        do {
            x = stk[top--];
            scc[x] = sccnum;
        } while (x != u);
    }
}
//---------

int ind[MAXN], oud[MAXN];
int a[MAXN];
int sum[MAXN];
ll ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(head, -1, sizeof head);
    int n;

    cin >> n;
    for (int u = 1, v; u <= n; ++u) {
        cin >> v;
        addEdge(u, v);
        ind[v]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (!dfn[i])
            tarjan(i);
    }
    for (int i = 1; i <= n; ++i) {
        sum[scc[i]]++;
    }
    ans = 1;
    for (int i = 1; i <= sccnum; ++i) {
        if (sum[i] > 1) {
//            _debug(sum[i]);
            ans = ans * (fpow(2, sum[i], MOD) + MOD - 2) % MOD;
        } else {
            ans = ans * 2ll % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}

/*

 4
 2 0
 1 0
 4 0
 3 0

 */