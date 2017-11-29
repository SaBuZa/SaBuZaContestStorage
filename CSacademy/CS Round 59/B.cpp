#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
int G1,G2,P1,P2;

int bsearch(int l,int r,int w1){
    int ret =0;
    while (l<=r){
        int mid = (l+r)/2;
        int tmp = (100*w1 + 100*mid)/G2;
        if (tmp < P2){
            l = mid + 1;
        }else if (tmp > P2){
            r = mid - 1;

        }else{
            ret = mid;
            l = mid + 1;
        }
    }
    return ret;
}

int main(){
    int ans = 0;
    scanf ("%d%d%d%d",&G1,&P1,&G2,&P2);
    for (int i=0;i<=G1;i++){
        if ((100*i)/G1 == P1){
            int tmp = bsearch(0,G2 - G1,i);
            ans = max(ans,tmp);
        }
    }
    printf ("%d\n",ans);
    return 0;
    
}