#include <bits/stdc++.h>
using namespace std;

int n,m;

#define MAXN 100005

int p[MAXN],par[MAXN],sz[MAXN],mn[MAXN],c[MAXN];
long long ans = 0;
bool painted[MAXN];

void initialize(){
    memset(painted,0,sizeof painted);
	for (int i=1;i<MAXN;i++){
		par[i] = i;
		sz[i] = 1;
		mn[i] = c[i];
	}
}

int getSet(int i){
	if (par[i] != i)
		par[i] = getSet(par[i]);
	return par[i];
}

void unify(int a,int b){
	a = getSet(a);
	b = getSet(b);
	if (a==b) return;
	if (sz[b] > sz[a]) swap(a,b);
	par[b] = a;
	sz[a] += sz[b];
    mn[a] = min(mn[a],mn[b]);
}

bool isUnion(int a,int b){
	return getSet(a) == getSet(b);
}

int main(){
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf ("%d",&c[i]);
    initialize();
    for (int i=1;i<=m;i++){
        int x,y;
        scanf ("%d%d",&x,&y);
        unify(x,y);
    }
    for (int i=1;i<=n;i++){
        int u = getSet(i);
        if (!painted[u]){
            painted[u] = true;
            ans += mn[u];
        }
    }
    printf ("%lld\n",ans);
return 0;
}
