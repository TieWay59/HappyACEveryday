/*
    @Author: TieWay59
    @Date: 2019/11/21 22:49
    @Link: https://codeforc.es/gym/102416/problem/C
    @Tags: idea
*/

#include <bits/stdc++.h>

#define  debug(x)  cerr <<#x << " = "<<x<<endl

#define endl '\n'
#define STOPSYNC ios::sync_with_stdio(false);cin.tie(nullptr)
#define MULTIKASE int Kase=0;cin>>Kase;for(int kase=1;kase<=Kase;kase++)
const int MAXN = 2e5 + 59;
const int MOD = 1e9 + 7;

using namespace std;
typedef long long ll;

int a, d, b;
int x, y;

void solve(int kaseId = -1) {
    cin >> a >> d;
    x = d % a;
    y = d / a;

    int ans = a;
    //debug(x);
    /* for (int i = 1; i <= x; i++) {
         if ((x - 1) / i + 1 <= y) {
             ans = a + i;
             break;
         }
     }*/
    if (x > 0)
        ans = a + (x - 1) / y + 1;
    cout << ans << endl;
}

/*void solves() {
    MULTIKASE {
        solve(kase);
    }
}*/

int main() {
    STOPSYNC;
//    solves();
    solve();
    return 0;
}
/*

 */