/*
 *  https://codeforc.es/problemset/problem/750/E
 *
 */
#include <bits/stdc++.h>
//#include <stdio.h>
//#include <algorithm>

#define  _debug(x) cerr<<#x<<" = "<<x<<endl
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 59;
const int MAXM = 2e6 + 59;
const ll MOD = 998244353;
const ll INF = 1e6;



class Matrix {
public:
    int r{},c{};
    vector<vector<int> > mat;
    Matrix(): r(5), c(5){}

    void init(int _r,int _c){
        mat.reserve(_r);
        mat.resize(_r);
        for(auto &v:mat){
            v.resize(_c);
            v.resize(_c,0);
        }
    }

    int operator()(const  int &_r,const  int &_c) const{

        return this->mat[_r][_c];
    }
    void operator()(const  int &_r,const  int &_c,const  int &v){
        //_debug(this->mat.size());
        this->mat[_r][_c]=v;
    }

    Matrix operator*(const  Matrix &rht){
        if(c!=rht.r||rht.mat[0].empty()||this->mat.empty()){
            cerr<<"error"<<endl;
            exit(0);
        }
        int n=c;
        Matrix &lft=*this;
        Matrix ret;
        ret.init(5,5);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int t=INF;
                for (int k = 0; k < n; ++k) {
                    t=min(t,lft(i,k)+rht(k,j));
                }
                ret(i,j,t);
            }
        }
        return ret;
    }
};

int n,q;
string s;



Matrix a[10],tmp,ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    tmp.mat={{0,INF,INF,INF,INF},{INF,0,INF,INF,INF},{INF,INF,0,INF,INF},{INF,INF,INF,0,INF},{INF,INF,INF,INF,0}};
    a[3].mat={{0,INF,INF,INF,INF},{INF,0,INF,INF,INF},{INF,INF,0,INF,INF},{INF,INF,INF,0,INF},{INF,INF,INF,INF,0}};
    a[2].mat={{1,0,INF,INF,INF},{INF,0,INF,INF,INF},{INF,INF,0,INF,INF},{INF,INF,INF,0,INF},{INF,INF,INF,INF,0}};
    a[0].mat={{0,INF,INF,INF,INF},{INF,1,0,INF,INF},{INF,INF,0,INF,INF},{INF,INF,INF,0,INF},{INF,INF,INF,INF,0}};
    a[1].mat={{0,INF,INF,INF,INF},{INF,0,INF,INF,INF},{INF,INF,1,0,INF},{INF,INF,INF,0,INF},{INF,INF,INF,INF,0}};
    a[7].mat={{0,INF,INF,INF,INF},{INF,0,INF,INF,INF},{INF,INF,0,INF,INF},{ INF,INF,INF,1,0},{INF,INF,INF,INF,0}};
    a[6].mat={{0,INF,INF,INF,INF},{INF,0,INF,INF,INF},{INF,INF,0,INF,INF},{INF,INF,INF,0,INF},{INF,INF,INF,INF,1}};
    a[4]=a[5]=a[8]=a[9]=a[3];

    //20166766
//    tmp=tmp*a[2]*a[0]*a[1]*a[6]*a[6]*a[7]*a[6]*a[6];
    /*tmp=tmp*a[2]*a[0]*a[1]*a[6]*a[6]*a[7]*a[6];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<tmp(i,j)<<"\t\t";
        }
        cout<<endl;
    }*/


    cin>>n>> q>> s;

    for(auto c:s){
        int i=c-'0';
    }

    return 0;
}

/*


 */
