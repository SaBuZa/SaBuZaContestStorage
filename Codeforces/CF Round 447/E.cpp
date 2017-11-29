#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;

vector <pair<int,ll> > adj[1000005];
struct myEdge{
    int u,v;
    ll w;
    myEdge(){}
    myEdge(int _u,int _v,ll _w):u(_u),v(_v),w(_w){}
};

int main(){
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=m;i++){
        int u,v;
        ll w;
        scanf ("%d%d%lld",&u,&v,&w);
        adj[u].push_back({v,w});
    }
    /*
    ALGO
        1) SCC
        2) CALC SUM W IN EACH NODE v
        3) SUM ON TREE
    */
    scanf ("%d",&s);
return 0;
}
