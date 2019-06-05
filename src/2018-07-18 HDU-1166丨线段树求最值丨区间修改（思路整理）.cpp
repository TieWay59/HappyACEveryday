#include<bits/stdc++.h>
using namespace std;
const int N = 50000*4;
int a[N],tree[N],add[N],L,R;
int Ti,T,n;
char op[15];
/*
线段树算法逻辑

build
清空延迟标记
如果是叶子节点
    读入元素
如果不是叶子节点
    build左
    build右
    计算节点值

pushdown
左右节点值+=add
左右节点延迟标记+=add
当前节点延迟标记=0；


query
如果节点区间在询问区间外
    返回不正确信息
如果……在……内
    直接返回节点数值
pushdown下传延迟标记
向左query
向右query


update_sg
当前区间在外 return；
当前区间在内 修改节点值与标记return；
当前区间有交集
    下传标记，左右继续更新，重新计算节点值；

*/
int build(int root,int l,int r){
    add[root]=0;
    if(l==r){
        tree[root]=a[l];
    } else {
        int m=(l+r)/2;
        build(root*2,l,m);
        build(root*2+1,m+1,r);
        tree[root]=tree[root*2]+tree[root*2+1];
    }
}

void PushDown(int root,int l,int r){
    tree[root*2]+=add[root]*(r-l+1);
    add[root*2]+=add[root];
    tree[root*2+1]+=add[root]*(r-l+1);
    add[root*2+1]+=add[root];
    add[root]=0;
}

int query(int root,int l,int r)
{
    if(r<L||R<l)return 0;
    else if(L<=l&&r<=R)return tree[root];

    PushDown(root,l,r);
    int m=(l+r)/2;
    return query(root*2,l,m)+query(root*2+1,m+1,r);
    //这里就直接左右开弓，而不去细分了，因为这上面已经有return0
    //这样看起来更简洁一些。
}

void update(int root,int l,int r,int v)
{
    if(r<L||R<l)return ;
    else if(L<=l&&r<=R){
        add[root]+=v;
        tree[root]+=v;
        return ;
    }

    PushDown(root,l,r);
    int m=(l+r)/2;
    update(root*2,l,m,v);
    update(root*2+1,m+1,r,v);
    //同理为了简洁，这里不去细分m和LR的关系，因为上方有return；
    tree[root]=tree[root*2]+tree[root*2+1];
}


int main(){

    Ti=1;
    scanf("%d",&T);
    while(Ti<=T)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        build(1,1,n);

        int x,y;
        printf("Case %d:\n",Ti++);
        while(scanf("%s",op)!=EOF){

            if(strcmp(op,"Query")==0) {
                scanf("%d%d",&L,&R);
                printf("%d\n",query(1,1,n));
            } else if(strcmp(op,"Add")==0) {
                scanf("%d%d",&L,&x);R=L;
                update(1,1,n,x);
            } else if(strcmp(op,"Sub")==0) {
                scanf("%d%d",&L,&x);R=L;
                update(1,1,n,-x);
            } else {
                break;
            }
        }
    }
    return 0;
}
/*
1
10
1 2 3 4 5 6 7 8 9 10
Query 1 3
Add 3 6
Query 2 7
Sub 10 2
Add 6 3
Query 3 10
End

*/
