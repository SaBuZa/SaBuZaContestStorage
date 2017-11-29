#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N,M;
int s,t;
struct myEdge{
    int u,v;
    ll w;
    myEdge(){}
    myEdge(int _u,int _v,ll _w):u(_u),v(_v),w(_w){}
    bool operator <(const myEdge &ot) const{
        return w > ot.w;
    }
};

int path[100005];
ll dist[100005];

vector <myEdge> adj[100005];
priority_queue <myEdge> pq;

ll dijkstra(int s, int t){
    for (auto cur : adj[s]){
        pq.push(cur);
    }
    memset(dist,-1,sizeof dist);
    dist[s] = 0;
    path[s] = -1;
    while (!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if (dist[cur.v]!=-1) continue;
        dist[cur.v] = cur.w;
        path[cur.v] = cur.u;
        for (auto x : adj[cur.v]){
            pq.push(myEdge(x.u,x.v,x.w + dist[cur.v]));
        }
    }
    return dist[t];
}

int main(){
    scanf ("%d%d",&N,&M);
    for (int i=1;i<=M;i++){
        int u,v;
        ll w;
        scanf ("%d%d%lld",&u,&v,&w);
        adj[u].push_back(myEdge(u,v,w));
        adj[v].push_back(myEdge(v,u,w));
    }
    s = 1, t = N;
    //scanf ("%d%d",&s,&t);
    //printf ("%lld\n",dijkstra(s,t));
    dijkstra(s,t);
    if (dist[t]!=-1){
        int cp = N;
        stack<int> ans;
        while (path[cp]!=-1){
            ans.push(cp);
            cp = path[cp];
        }
        ans.push(s);
        while (!ans.empty()){
            printf ("%d ",ans.top());
            ans.pop();
        }
    }else{
        printf ("-1\n");
    }
return 0;
}
