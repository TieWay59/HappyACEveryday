/*
实际上，O(n^4)的KM算法表现不俗，使用O(n^3)并不会很大的提高KM的运行效率
需要在O(1)的时间找到任意一条边，使用邻接矩阵存储更为方便
*/
#include <cstring>
#include <cstdio>

const int N = 105;
const int INF = 0x3f3f3f3f;
int match[N], slack[N];
int potentialX[N], potentialY[N];
int weight[N][N];
bool visX[N], visY[N];
int n, size_X, size_Y, ans;
//-----
struct Room {
    int a[5];
} r1[N], r2[N];



//-----

bool FindPath(int u) {
    int tempDelta;

    visX[u] = true;
    for (int v = 0; v < size_Y; ++v) {
        if (visY[v]) continue;
        tempDelta = potentialX[u] + potentialY[v] - weight[u][v];
        if (tempDelta == 0) {//(u,v)在相等子图中
            visY[v] = true;
            if (match[v] == -1 || FindPath(match[v])) {
                match[v] = u;
                return true;
            }
        } else if (slack[v] > tempDelta)
            slack[v] = tempDelta;//(u,v)不在相等子图中且y不在交错树中
    }
    return false;
}

void Kuhn_Munkres() {
    for (int x = 0; x < size_X; ++x) {
        for (int j = 0; j < size_Y; ++j)
            slack[j] = INF;
        //这里不要忘了，每次换新的x结点都要初始化slack

        while (true) {
            memset(visX, false, sizeof(visX));
            memset(visY, false, sizeof(visY));
            //这两个初始化必须放在这里,因此每次findpath()都要更新
            if (FindPath(x)) break;
            else {
                int delta = INF;
                for (int j = 0; j < size_Y; ++j)
                    //因为dfs(x)失败了所以x一定在交错树中，y不在交错树中，第二类边
                    if (!visY[j] && delta > slack[j])
                        delta = slack[j];

                for (int i = 0; i < size_X; ++i)
                    if (visX[i]) potentialX[i] -= delta;
                for (int j = 0; j < size_Y; ++j) {
                    if (visY[j]) potentialY[j] += delta;
                    else slack[j] -= delta;

                    //修改顶标后，要把所有的slack值都减去delta
                    //这是因为lx[i] 减小了delta
                    //slack[j] = min(potentialX[i] + potentialY[j] -w[i][j]) --j不属于交错树--也需要减少delta，第二类边
                }
            }
        }
    }
}

void KM_Solve() {
    //初始化XY集合的期望和配对
    memset(match, -1, sizeof(match));
    memset(potentialY, 0, sizeof(potentialY));
    for (int i = 0; i < size_X; ++i) {
        potentialX[i] = -INF;
        for (int j = 0; j < size_Y; ++j)
            if (potentialX[i] < weight[i][j])
                potentialX[i] = weight[i][j];
    }
    Kuhn_Munkres();
}

/*
简单地说，KM算法解决的问题是：集合X与集合Y元素根据多元的边权相互匹配，
在促使配对尽可能多的前提下，求相关的最值。（有可能是同一个集合不同属性进行匹配）
*/


int check(int ii, int jj) {
    int ans = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (r1[ii].a[i] == r2[jj].a[j])
                ans++;

    return ans;
}


int main() {
    //主函数需要解决：XY集合的大小，权值weight，以及具体要求什么
    //本题（HDU-2255）模版是裸求 最佳匹配的最大总体权值的
    //（如果求是求匹配对数，就计数即可）
    //（如果求最小，就用负数加权，再负数取答案）

    scanf("%d", &n);
    size_X = size_Y = n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
            scanf("%d", &r1[i].a[j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
            scanf("%d", &r2[i].a[j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            weight[i][j] = check(i, j);

    KM_Solve();

    int ans = 0;
    for (int i = 0; i < size_Y; ++i)
        if (match[i] != -1)
            ans += weight[match[i]][i];
    printf("%d\n", 4 * n - ans);
    return 0;
}
/*
参考文章：
http://www.cnblogs.com/wenruo/p/5264235.html
https://www.cnblogs.com/jackge/archive/2013/05/03/3057028.html
https://blog.csdn.net/sixdaycoder/article/details/47720471
https://en.wikipedia.org/wiki/Hungarian_algorithm
*/

/*
2
1 2 3 4
5 6 7 8
4 6 7 8
1 2 3 2
*/
