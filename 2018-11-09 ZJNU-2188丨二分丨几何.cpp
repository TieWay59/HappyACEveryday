#include<stdio.h>
#include<algorithm>

using namespace std;
struct node {
    int x, y;
} a[105];
int n;

bool chk(int x, int y) {
    for (node t:a)
        if (x * t.y + y * t.x > x * y)
            return false;
    return true;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &a[i].x, &a[i].y);
            mx = max(mx, 2 * max(a[i].x, a[i].y));
        }
        double ans = 1e9 + 7;
        for (int x = 1; x <= mx; x++) {
            int l = 1, r = mx, y;
            if (!chk(x, r))continue;
            while (l <= r) {
                y = (l + r) / 2;
                if (chk(x, y))r = y - 1;
                else l = y + 1;
            }
            y = l;
            ans = min(ans, x * y * 1.0 / 2.0);
        }
        printf("%.1f\n", ans);
    }
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int qx[1005],qy[1005],n;
int ck(int x,int y){
    for(int i=1;i<=n;i++){
        if(x*qy[i]+y*qx[i]>x*y) return 0;
    }
    return 1;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        int maxn=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&qx[i],&qy[i]);
            maxn=max(maxn,2*qx[i]);
            maxn=max(maxn,2*qy[i]);
        }
        double ans=1e9+7;
        for(int x=1;x<=maxn;x++){
            int l=1,r=maxn,y;
            if(!ck(x,r))continue;
            while(l<=r){
                y=(l+r)/2;
                if(ck(x,y))r=y-1;
                else l=y+1;
            }
            y=r+1;
            ans=min(ans,x*y*1.0/2.0);
        }
        printf("%.1f\n",ans);
    }
    return 0;
}
*/
