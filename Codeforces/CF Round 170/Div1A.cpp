#include <bits/stdc++.h>
using namespace std;

int N,M;
int a[105][105],k[105];
set<int> s[105];
int sz[105],par[105],compNum;

void initialize(){
    for (int i=1;i<=100;i++){
        par[i] = i;
        sz[i] = 1;
    }
    compNum = N;
}

int getSet(int i){
    if (par[i] != i)
        par[i] = getSet(par[i]);
    return par[i];
}

bool unify(int u,int v){
    u = getSet(u);
    v = getSet(v);
    if (sz[u] > sz[v]) swap(u,v);
    if (u == v) return false;
    par[u] = v;
    sz[v] += sz[u];
    compNum--;
    return true;
}

int main(){
    int ans = 0;
    bool chk = 0;
    scanf ("%d%d",&N,&M);
    initialize();
    for (int i=1;i<=N;i++){
        scanf ("%d",&k[i]);
        if (k[i]!=0) chk = true;
        for (int j=1;j<=k[i];j++){
            int x;
            scanf ("%d",&x);
            s[i].insert(x);
            for (int ii = 1 ; ii < i;ii++){
                if (s[ii].find(x)!=s[ii].end()){
                    unify(ii,i);
                    //printf ("||||| %d %d\n",ii,i);
                    break;
                }
            }
        }
    }
//    for (int i=1;i<=N;i++)
//        printf ("%d : %d\n",i,getSet(i));

    printf ("%d\n",compNum-chk);
return 0;
}
