#include <bits/stdc++.h>
using namespace std;

int  L[1000005],alive[1000005];

int main(){
    int n;
    scanf ("%d",&n);
    for (int i=1;i<=n;i++){
        scanf ("%d",&L[i]);
        alive[i] = 1;
    }
    int pow = 0,ans=n;
    for (int i=n;i>=1;i--){
        if (pow>0){
            alive[i] = 0;
            ans--;
        }
        pow--;
        pow = max(pow, L[i]);
    }
    printf ("%d\n",ans);
return 0;
}
