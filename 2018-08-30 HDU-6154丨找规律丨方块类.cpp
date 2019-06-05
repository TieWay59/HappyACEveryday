/*http://acm.hdu.edu.cn/showproblem.php?pid=6154
�ҹ����⣬������֪����ô˵�źá�
*/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
const int N = 89444;
double d[N];

int main() {
    d[4] = 2.0;
    d[5] = 2.5;
    d[6] = 4.0;
    d[7] = 5.5;
    for (int i = 8; i < N; i += 4) {
        d[i + 0] = (1.0 * i * i) / 8.0;
        d[i + 1] = d[i + 0] + (i - 2) / 4.0 + 0.0;
        d[i + 2] = d[i + 1] + (i - 2) / 4.0 + 1.0;
        d[i + 3] = d[i + 2] + (i - 2) / 4.0 + 1.0;
    }
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", lower_bound(d, d + N, n) - d);
    }
    return 0;
}
