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

void update(int idx,int l,int r,int a,int b){
    if (lazy[idx]){
        st[idx] ^= lazy[idx];
        sm[idx] = (r - l + 1) - sm[idx];
        if (l != r){
            lazy[idx*2+1] ^= 1;
            lazy[idx*2] ^= 1;
        } 
        lazy[idx] = 0;
    }
    if (r < a || l > b){
        return;
    }
    if (l >= a && r <= b){
        st[idx] ^= 1;
        sm[idx] = (r - l + 1) - sm[idx];
        if (l != r){
            lazy[idx*2] ^= 1;
            lazy[idx*2+1] ^= 1;
        }
        return;
    }
    int mid = (l+r)/2;
    update(idx*2,l,mid,a,b);
    update(idx*2+1,mid+1,r,a,b);
    sm[idx] = sm[idx*2] + sm[idx*2+1];
}

int query(int idx,int l,int r,int a,int b){
    if (lazy[idx]){
        st[idx] ^= lazy[idx];
        sm[idx] = (r - l + 1) - sm[idx];
        if (l != r){
            lazy[idx*2+1] ^= 1;
            lazy[idx*2] ^= 1;
        }
        lazy[idx] = 0;
    }
    if (r < a || l > b){
        return 0;
    }
    if (l >= a && r <= b){
        return sm[idx];
    }
    int mid = (l+r)/2;
    return query(idx*2,l,mid,a,b) + query(idx*2+1,mid+1,r,a,b);
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