#include <bits/stdc++.h>
using namespace std;

int n;
int a[10005];

int main(){
    int g;
    scanf ("%d",&n);
    for (int i=1;i<=n;i++){
        scanf ("%d",&a[i]);
        if (i==1){
            g = a[1];
        }else{
            g = __gcd(g,a[i]);
        }
    }
    /*if (g!=1){
        printf ("-1\n");
        return 0;
    }*/
    int cnt = 0,oc=0,ans=0;
    for (int i=1;i<=n;i++){
        if (a[i]==1){
            oc++;
        }
    }
    if (oc != 0){
        printf ("%d\n",n - oc);
        return 0;
    }
    int tmx = 1000000;
    for (int i=2;i<=n;i++){
        g = a[i];
        for (int j=i-1;j>0;j--){
                //printf ("%d\n",__gcd(a[i],a[j]));
            g = __gcd(g,a[j]);
            if (g==1){
                //if (tmx > i-j) printf ("%d %d\n",i,j);
                tmx = min(tmx,i - j);

            }
        }
    }
    if (tmx >= 1000000){

        printf ("-1\n");
        return 0;
    }
    printf ("%d\n",n+tmx-1);
    return 0;

return 0;
}
