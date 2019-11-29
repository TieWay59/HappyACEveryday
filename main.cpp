/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2019/11/22 21:39
  *  @Link: Accept
  *  @Tags:
  *
  *******************************************************/

#include <bits/stdc++.h>

#ifdef DEBUG
//#define debug(x)  cerr <<#x << " = "<<x<<endl;
#include "libs59/debugers.h"

#else
#define endl '\n'
#define debug(x)  59
#endif

#define STOPSYNC ios::sync_with_stdio(false);cin.tie(nullptr)
#define MULTIKASE int Kase=0;cin>>Kase;for(int kase=1;kase<=Kase;kase++)
typedef long long ll;
const int MAXN = 2e6 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;


const int N = 4e6 + 59;
int a[N], add[N], L, R;
int tree_MIN[N], tree_MAX[N];

char op[15];


/*int build(int root, int l, int r) {
    add[root] = 0;
    if (l == r) {
        tree[root] = a[l];
    } else {
        int m = (l + r) / 2;
        build(root * 2, l, m);
        build(root * 2 + 1, m + 1, r);
        tree[root] = tree[root * 2] + tree[root * 2 + 1];
    }
}*/

void PushDown(int root, int l, int r) {
    tree_MAX[root * 2] += add[root];
    tree_MIN[root * 2] += add[root];
    add[root * 2] += add[root];
    tree_MAX[root * 2 + 1] += add[root];
    tree_MIN[root * 2 + 1] += add[root];
    add[root * 2 + 1] += add[root];
    add[root] = 0;
}

int query_MAX(int root, int l, int r) {
    if (r < L || R < l)return 0;
    else if (L <= l && r <= R)return tree_MAX[root];

    PushDown(root, l, r);
    int m = (l + r) / 2;
    return max(query_MAX(root * 2, l, m),
               query_MAX(root * 2 + 1, m + 1, r));
}

int query_MIN(int root, int l, int r) {
    if (r < L || R < l)return INF;
    else if (L <= l && r <= R)return tree_MIN[root];

    PushDown(root, l, r);
    int m = (l + r) / 2;
    return min(query_MIN(root * 2, l, m),
               query_MIN(root * 2 + 1, m + 1, r));
}

void update(int root, int l, int r, int v) {
    if (r < L || R < l)return;
    else if (L <= l && r <= R) {
        add[root] += v;
        tree_MIN[root] += v;
        tree_MAX[root] += v;
        return;
    }

    PushDown(root, l, r);
    int m = (l + r) / 2;
    update(root * 2, l, m, v);
    update(root * 2 + 1, m + 1, r, v);

    tree_MAX[root] = max(tree_MAX[root * 2], tree_MAX[root * 2 + 1]);
    tree_MIN[root] = min(tree_MIN[root * 2], tree_MIN[root * 2 + 1]);
}


void solve(int kaseId = -1) {


}

void solves() {
    MULTIKASE {
        solve(kase);
    }
}

int n;
char str[MAXN];
char sss[MAXN];

int main() {
    //    STOPSYNC;
    //    solve();
    scanf("%d %s", &n, str + 1);
    //memset(tree_MIN, INF, sizeof tree_MIN);
    //printf("%s\n", str + 1);

    int pos = 1;
    for (int i = 1; i <= n; i++) {
        //        debug(i);
        if (str[i] == 'L') {
            pos = max(pos - 1, 1);
        } else if (str[i] == 'R') {
            pos++;
        } else if (str[i] == '(') {
            if (sss[pos] == ')') {
                L = pos, R = n;
                update(1, 1, n, +1);
            }
            if (sss[pos] != '(') {
                L = pos, R = n;
                sss[pos] = str[i];
                update(1, 1, n, +1);
            }
        } else if (str[i] == ')') {
            if (sss[pos] == '(') {
                L = pos, R = n;
                update(1, 1, n, -1);
            }
            if (sss[pos] != ')') {
                L = pos, R = n;
                sss[pos] = str[i];
                update(1, 1, n, -1);
            }
        } else {
            if (sss[pos] == ')') {
                L = pos, R = n;
                sss[pos] = str[i];
                update(1, 1, n, +1);
            }
            if (sss[pos] == '(') {
                L = pos, R = n;
                sss[pos] = str[i];
                update(1, 1, n, -1);
            }
        }
        L = n, R = n;
        int chekLas = query_MIN(1, 1, n);
        L = 1, R = n;
        //        debug(query_MIN(1, 1, n));
        int chekwhole = query_MIN(1, 1, n);

        if (chekLas != 0 ||
            chekwhole == -1) {
            printf("%d ", -1);
        } else {
            printf("%d ", query_MAX(1, 1, n));
        }
    }


    return 0;
}
/*

 */