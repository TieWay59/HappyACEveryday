#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include <map>

#define  _debug(x) cerr<<#x << " = " << x<<endl
using namespace std;

typedef long long ll;
//typedef _int128 lll;
const int MOD = 0;
const double eps = 1e-3;
const int MAXN = 100000 + 59;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f;

/* @author: tieway59
 * @notice:
 * - Calculate  seconds from epoch of unix (1970/1/1 0:0:0 UTC+0).
 * - yue = [1,12] (tm_mon = [0,11])
 * - nian = [1970,...] (cant calculate earlier than 1970)
 * - China time zone UTC+8, so try (1970,1,1,0,8,0).
 */
template<typename var = ll>
var epTime(int nian = 1970, int yue = 1, int ri = 1, int shi = 8, int fen = 0, int miao = 0) {
    static const time_t rawtime = time(nullptr);

    struct tm *contime = localtime(&rawtime);

    contime->tm_year = nian - 1900;
    contime->tm_mon = yue - 1;
    contime->tm_mday = ri;
    contime->tm_hour = shi;
    contime->tm_min = fen;
    contime->tm_sec = miao;

    time_t rettime = mktime(contime);
//    printf("%s\n", asctime(contime));   //debug
    return (var) rettime;
}


ll val[MAXN];
ll

int n, m, h, r, t, s;
char str[5];

int main() {

    map<const char *, int> mp;
    mp["Jan"] = 1;
    mp["Feb"] = 2;
    mp["Mar"] = 3;
    mp["Apr"] = 4;
    mp["May"] = 5;
    mp["Jun"] = 6;
    mp["Jul"] = 7;
    mp["Aug"] = 8;
    mp["Sep"] = 9;
    mp["Oct"] = 10;
    mp["Nov"] = 11;
    mp["Dec"] = 12;

    while (scanf("%d%d", &n, &m) != EOF && n + m) {
        ll start = epTime(2000, 0, 0, 0) / 3600;
        for (int i = 1, nian, yue, ri, shi; i <= n; ++i) {
            scanf("%s %d %d %d %lld", str, &ri, &nian, &shi, rg + i);
            yue = mp[str];
            tg[i] = epTime(nian, yue, ri, shi) / 3600ll;
        }

        scanf("%d%d", &s, &t);

        for (int i = 1; i <= m; ++i) {

        }

    }

    return 0;
}
/*

3 1 4
H 3 2
G 10 5
C 1 5

 */