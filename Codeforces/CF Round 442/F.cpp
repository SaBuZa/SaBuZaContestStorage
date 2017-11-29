// NOT SOLVED YET
// CURRENT PERFORMANCE (IN PAPER) : O(Q * sqrt(N) * lg(N))
// 1) For each i, Map hashing to pickup quick sum table matching with current i
// 2) Use Mo's to do Query ? (WTH WITH TLE)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll,int> cnt,cntsave;
ll qs[100005],cntsum[100005];
int L[100005],R[100005];
int a[100005],t[100005];
int n,k;
int curl = 0;
int smans = 0;
vector<pair<int,int> > QL;
int main(){
    scanf ("%d%d",&n,&k);
    for (int i=1;i<=n;i++){
        scanf ("%d",&t[i]);
    }
    qs[0] = 0;
    for (int i=1;i<=n;i++){
        scanf ("%d",&a[i]);
        if (t[i]==2){
            a[i] = -a[i];
        }
        qs[i] = qs[i-1] + a[i];
    }
    /*
    cnt[0] ++;
    for (int i=1;i<=n;i++){
        cnt[qs[i]]++;
        cntsave[i] = cnt[qs[i] - k];
        cntsum[i] = cntsum[i-1] + cntsave[i];
        printf ("%d ",cntsave[i]);
    }
    */
    int q;
    scanf ("%d",&q);
    for (int i=1;i<=q;i++){
        scanf ("%d%d",&L[i],&R[i]);
        QL.push_back({L[i],R[i]});
        //printf ("%lld\n",cntsum[R[i]] - cntsum[L[i]-1]);
    }
    sort(QL.begin(),QL.end());
    cnt[0] ++;
    for (int i=0;i<QL.size();i++){
        cnt[qs[i]]++;
        while (curl < QL[i].first-1){
            smans -= cnt[qs[curl] - k];
            cnt[qs[curl]]--;
            curl++;
        }
        smans += cnt[qs[i] - k];
        printf ("%d %d %d %d %lld\n",curl,QL[i].first-1,i,smans,qs[i]-k);
        printf ("%d\n",smans);
    }
    return 0;
}