#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

int A[MAXN],s[MAXN];
int N;

int main(){
    scanf ("%d",&N);
    for (int i=1;i<=N;i++){
        scanf ("%d",&A[i]);
        s[i] = s[i-1] + A[i];
    }
    int ans = 360;
    for (int i=1;i<=N;i++){
        for (int j = i;j<=N;j++){
            int tmp = s[j] - s[i-1];
            ans = min(ans,abs(360-2*tmp));
        }
    }
    printf ("%d\n",ans);
    return 0;
    
}