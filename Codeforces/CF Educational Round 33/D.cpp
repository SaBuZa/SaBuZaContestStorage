#include <bits/stdc++.h>

using namespace std;

int n,d;
int a[100005];
int dp[100005];

int main(){
    bool chk = true;
    scanf ("%d%d",&n,&d);
    for (int i=1;i<=n;i++)
        scanf ("%d",&a[i]);
    for (int i=n;i>=1;i--){
        if (i==n) dp[i] = d - a[i];
        else dp[i] = dp[i+1] - a[i];
        dp[i] = min(dp[i],d);
        /*
        if (dp[i] < 0)
            chk = false;
        */
    }
    int sum = 0,ans=0;
    for (int i=1;i<=n;i++){
        if (sum > dp[i]) chk = false;
        sum += a[i];
        //printf (":: %d\n",sum);
        if (a[i] == 0){
            if (sum < 0) sum = dp[i],ans++;
            if (sum < 0) chk = false;
            continue;
        }
    }
/*
    for (int i=1;i<=n;i++){
        printf ("%d ",dp[i]);
    }
*/
    if (chk)
        printf ("%d\n",ans);
    else 
        printf ("-1\n");

    return 0;
    
}