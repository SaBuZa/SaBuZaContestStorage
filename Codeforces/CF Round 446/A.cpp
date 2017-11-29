#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000005];
int b[1000005];
int main(){
    long long sum = 0;
    scanf ("%d",&n);
    for (int i=1;i<=n;i++){
        scanf ("%d",&a[i]);
        sum += a[i];
    }
    for (int i=1;i<=n;i++){
        scanf ("%d",&b[i]);
    }
    sort(b+1,b+1+n);
    if (sum > b[n] + b[n-1]) printf ("NO\n");
    else printf ("YES\n");

return 0;
}
