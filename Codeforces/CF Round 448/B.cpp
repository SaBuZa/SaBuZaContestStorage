#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

typedef long long ll;

ll a[MAXN];
int n,x,k;
ll kx;
vector <ll> v;

int main(){
    scanf ("%d%d%d",&n,&x,&k);
    for (int i=1;i<=n;i++){
        scanf ("%lld",&a[i]);
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    ll ans = 0;
    for (int i=0;i<n;i++){
        ll base = (v[i]/x)*x;
        ll kx = (ll)k*(ll)x;
        vector<ll>::iterator lb,ub;
        if ((v[i]%x) != 0){
            if (k==0){
                lb = lower_bound(v.begin(),v.end(),v[i]);
                ub = upper_bound(v.begin(),v.end(),base+x-1);
            }else{
                lb = lower_bound(v.begin(),v.end(),base+kx);
                ub = upper_bound(v.begin(),v.end(),base+kx+x-1);
            }
        }else{
            if (k==0){
                continue;
            }else{
                lb = lower_bound(v.begin(),v.end(),base+kx-x);
                ub = upper_bound(v.begin(),v.end(),base+kx-1);
                //printf ("%d %d\n",lb,ub);
            }
        }
        ans += ub - lb;
    }
    printf ("%lld\n",ans);
    return 0;
    
}