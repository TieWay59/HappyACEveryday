
#include <bits/stdc++.h>

#define  _debug(x) cerr<<#x << " = " << x<<endl
using namespace std;

typedef long long ll;
//typedef _int128 lll;
const int MOD = -1;
const double eps = 1e-3;
const int MAXN = 1000 + 59;
const int MAXM = 2e4 + 59;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f;


int kase;
int low, hih;

const double delta = 1e-15;
char str[25];

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

//    input.reset(new InputFile(stdin, false));
//    input.reset(new InputFile());
//    output.reset(new OutputFile());

    while (scanf("%d%d", &low, &hih) && low && hih) { ;
        double ans = 0;
        for (int i = low; i <= hih; ++i) {
            ans += pow(i, -2.0 / 3.0);
        }
        ans = ans / 3.0F * delta;
        sprintf(str, "%.5E\n", ans);
        char s1[22];
        int exp;
        sscanf(str, "%[^E]%*c%*c%d", s1, &exp);
        printf("%sE-%03d\n", s1, exp);
    }
    return 0;
}
/*
1 100
10000 20000
0 0

 */