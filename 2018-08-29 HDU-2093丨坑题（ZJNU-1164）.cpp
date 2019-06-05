/*http://acm.zjnu.edu.cn/CLanguage/showproblem?problem_id=1164
坑题，记一下。
不给输入范围，坑中之坑。
*/
#include<bits/stdc++.h>

using namespace std;
int n, m;

struct node {
    char name[15];
    int time, num;

    bool operator<(node const &x) const {
        if (num != x.num)return num > x.num;
        else if (time != x.time)return time < x.time;
        return strcmp(name, x.name) < 0;
    }
} a[1005];

int main() {
    scanf("%d%d", &n, &m);
    int cnt = 0;
    while (scanf("%s", a[++cnt].name) != EOF) {
        node &t = a[cnt];//puts(t.name);
        t.num = t.time = 0;
        for (int i = 1, cnt = 0, v, c; i <= n; i++) {
            scanf("%d", &v);
            if (v <= 0)continue;
            t.num++;
            t.time += v;
            c = getchar();
            if (c == '(') {
                scanf("%d)", &v);//右括号是点睛之笔
                t.time += v * m;
            }
        }
    }
    cnt--;
    sort(a + 1, a + 1 + cnt);
    for (int i = 1; i <= cnt; i++)
        printf("%-10s %2d %4d\n", a[i].name, a[i].num, a[i].time);
    //由于空格和数组大小的问题被卡了好几回。
    return 0;
}

/*
8 20
Smith      -1    -16    8    0    0    120    39    0
Smibb      -1    -16    8    0    0    120    39    0
Josephus  72(3)    126    10    -3    0    47    21(2)    -2
Bush      0    -1    -8    0    0    0    0    0
Alice      -2    67(2)    13    -1    0    133    79(1)    -1
Bob      0    0    57(5)    0    0    168    -7    0
*/
