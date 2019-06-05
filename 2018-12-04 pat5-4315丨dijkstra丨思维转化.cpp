#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> par;
const int MAXN = 215;
const int INF = 0x3f3f3f3f;
int n, k;

string iton[MAXN], st, ed;
map<string, int> ntoi;
int happ[MAXN];             //happiness of city i;
int cost[MAXN][MAXN];       //cost from i to j;
vector<int> g[MAXN];         //adj-list
int trace[MAXN], top_trace;  //save the answer
int ds[MAXN];               //min distance cost of city i
int hp[MAXN];               //max happiness of city i while ds
int ct[MAXN];               //number of visited cities when in city i
int df[MAXN];               //number of different ways to get city i while ds
int pre[MAXN];              //last city visited before city i for the optimal way
bool vis[MAXN];             //whether city i is visited


void dijkstra(int u) {
    priority_queue <par, vector<par>, greater<par>> Q;
    memset(ds, INF, sizeof ds);

    ds[0] = 0;
    df[0] = 1;
    //for(int i=0;i<n;i++)
    Q.push({0, 0});
    while (!Q.empty()) {
        u = Q.top().second;
        Q.pop();
        if (vis[u])continue;
        vis[u] = true;

        for (int v:g[u]) {
            if (vis[v])continue;
            //printf("%d\n",cost[u][v]);
            int altv = ds[u] + cost[u][v];
            int alth = hp[u] + happ[v];
            int altc = ct[u] + 1;

            if (altv < ds[v]) {
                df[v] = df[u];
                ds[v] = altv;
                hp[v] = alth;
                ct[v] = altc;
                pre[v] = u;
                Q.push({altv, v});
            } else if (altv == ds[v]) {
                df[v] += df[u];
                if (alth > hp[v]) {
                    hp[v] = alth;
                    ct[v] = altc;
                    pre[v] = u;
                } else if (alth == hp[v]) {
                    if (altc < ct[v]) {
                        hp[v] = alth;
                        ct[v] = altc;
                        pre[v] = u;
                    }
                }
            }
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k >> st;//0~n-1;
    ed = "ROM";

    iton[0] = st;
    ntoi[st] = 0;
    for (int i = 1; i < n; i++) {
        cin >> iton[i] >> happ[i];
        //cout<<iton[i]<<happ[i]<<endl;
        ntoi[iton[i]] = i;
    }

    string s1, s2;
    for (int i = 1, u, v, c; i <= k; i++) {
        cin >> s1 >> s2 >> c;
        u = ntoi[s1];
        v = ntoi[s2];
        cost[u][v] = c;
        cost[v][u] = c;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    dijkstra(0);
    int ied = ntoi[ed];
    while (ied) {
        trace[++top_trace] = ied;
        ied = pre[ied];
    }

    ied = ntoi[ed];
    cout << df[ied] << ' ' << ds[ied] << ' ' << hp[ied] << ' ' << hp[ied] / ct[ied] << endl;
    cout << st;
    for (int i = top_trace; i > 0; i--) {
        cout << "->" << iton[trace[i]];
    }
    cout << endl;
    return 0;
}
/*
6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1
*/
