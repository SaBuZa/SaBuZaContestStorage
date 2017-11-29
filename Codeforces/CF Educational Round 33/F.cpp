#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int curnode=0,smtidx=0,curver=0;
int r,n,m;
bool vst[64*MAXN];
int lc[64*MAXN],rc[64*MAXN],st[64*MAXN];
int rver[1000007],qver[1000007];
int lvl[MAXN],a[MAXN];
int in[MAXN],out[MAXN];
vector<int> lvlList[MAXN],adj[MAXN];

void euler(int idx,int _lvl){
    in[idx] = ++curnode;
    //printf ("%d =====> %d\n",idx,_lvl);
    vst[idx] = true;
    lvl[idx] = _lvl;
    lvlList[_lvl].push_back(idx);
    for (auto u : adj[idx]){
        if (!vst[u]){
            euler(u,_lvl+1);
        }
    }
    out[idx] = ++curnode;
}

int build(int l,int r){
    int idx = ++smtidx;
    st[idx] = INFINITY;
    if (l==r){
        return idx;
    }
    int mid = (l+r)/2;
    lc[idx] = build(l,mid);
    rc[idx] = build(mid+1,r);
    return idx;
}

int update(int idx,int l,int r,int pos, int val){
    int nidx = ++smtidx;
    if (l == r){
        st[nidx] = val;
        return nidx;
    }
    int mid = (l + r) /2;
    
    if (pos <= mid){
        lc[nidx] = update(lc[idx],l,mid,pos,val);
        rc[nidx] = rc[idx];
    }else{
        lc[nidx] = lc[idx];
        rc[nidx] = update(rc[idx],mid+1,r,pos,val);
    }
    st[nidx] = min(st[lc[nidx]],st[rc[nidx]]);
    return nidx;
}

int query(int idx,int l,int r,int a,int b){
    if (r < a || l > b){
        return INFINITY;
    }
    if (l >= a && r <= b){
        return st[idx];
    }
    int mid = (l+r)/2;
    return min(query(lc[idx],l,mid,a,b),query(rc[idx],mid+1,r,a,b));
}

int main(){
    memset(st,-1,sizeof st);
    int last = 0;
    scanf ("%d%d",&n,&r);
    for (int i=1;i<=n;i++)
        scanf ("%d",&a[i]);
    for (int i=1;i<=n-1;i++){
        int x,y;
        scanf ("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    rver[0] = build(1,2*n);
    //printf ("==== %d %d\n",rver[0],smtidx);
    euler(r,1);
    for (int i=1;i<=n;i++){
        for (auto cur : lvlList[i]){
            int myver = ++ curver;
            //printf ("lvl : %d -----> %d\n",i,cur);
            //printf ("mai a %d\n",myver);
            rver[myver] = update(rver[myver-1],1,2*n,in[cur],a[cur]);
            //printf ("u: %d %d => %d %d\n",cur,i,myver,rver[myver]);
        }
        qver[i] = rver[curver];
        //printf ("%d : %d %d\n",i,qver[i],rver[qver[i]]);
    }

    scanf ("%d",&m);
    for (int i=1;i<=m;i++){
        int p,q;
        scanf ("%d%d",&p,&q);
        int x = ((p + last)%n + 1);
        int k = ((q + last)%n);
        //printf ("\n%d %d %d\n",qver[lvl[x]]+k,x,k);
        last = query(qver[min(n,lvl[x]+k)],1,2*n,in[x],out[x]);
        printf ("%d\n",last);
    }
    return 0;
}