#include <bits/stdc++.h>
using namespace std;

int n;
int par[200005];
int in[200005],out[200005];
int vst[200005],curnode=0;
vector <int> adj[200005];
int st[1600005];
int q,t[200005];
int lazy[1600005];
int sm[1600005];

void ETT(int idx){
    vst[idx] = true;
    in[idx] = ++curnode;
    for (int u : adj[idx]){
        if (!vst[u]){
            ETT(u);
        }
    }
    out[idx] = ++curnode;
}

void update(int idx){
    while (idx < 400005){
        ft[idx] += 1;
        ft[idx] %= 2; 
        idx += idx & (-idx);
    }
}

int query(int idx){
    int ret = 0;
    while (idx){
        if (ft[idx])

    }

}

int main(){
    scanf ("%d",&n);
    for (int i=2;i<=n;i++){
        int x;
        scanf ("%d",&x);
        par[i] = x;
        adj[x].push_back(i);
    }
    ETT(1);
    for (int i=1;i<=n;i++){
        scanf ("%d",&t[i]);
        if (t[i]){
            update(1,1,2*n,in[i],in[i]);
            update(1,1,2*n,out[i],out[i]);
        }
    }
    scanf ("%d",&q);
    for (int i=1;i<=q;i++){
        char cmd[100];
        int v;
        scanf ("%s",cmd);
        scanf ("%d",&v);
        if (cmd[0] == 'g'){
            printf ("%d\n",query(1,1,2*n,in[v],out[v])/2);
        }else if (cmd[0] == 'p'){
            update(1,1,2*n,in[v],out[v]);
        }
    }

    return 0;
}