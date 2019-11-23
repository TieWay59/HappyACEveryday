/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝ 
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝  
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2019/11/23 16:18
  *  @Link: https://codeforces.com/gym/102423/problem/J
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
const int MAXN = 2e5 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;

int nextPos[MAXN];
int linkPos[MAXN];
int cntNum[MAXN];
int canCover[MAXN];
int a[MAXN];
int n, k;

int ans[MAXN], ans_top;

struct node {
    int pos, cov, val;

    bool operator<(const node &rht) {
        if (cov == rht.cov) return val > rht.val;
        return cov < rht.cov;
    }
};

void solve(int kaseId = -1) {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = n; i >= 1; --i) {
        linkPos[i] = nextPos[a[i]];
        nextPos[a[i]] = i;
        canCover[i] = canCover[i + 1];
        if (0 == cntNum[a[i]]) {
            canCover[i]++;
        }
        cntNum[a[i]]++;
    }

    priority_queue<node> que;

    for (int i = 1, p, curPos = 0; i <= k;) {

        p = nextPos[i];

        while (p < curPos) {
            p = linkPos[p];
        }

        que.emplace(p, canCover[p], i);

        while (!que.empty() && que.top().cov >= k - ans_top) {
            ans[++ans_top] = que.top().val;
            que.pop();
            curPos = que.top().pos;
        }
    }

    while (!que.empty() && ans_top < k) {


    }

}

void solves() {
    MULTIKASE {
        solve(kase);
    }
}

int main() {
    STOPSYNC;
    solve();
    return 0;
}
/*







10 5
 5
 4
 3
 2
 1
 4
 1
 1
 5
 5

 */