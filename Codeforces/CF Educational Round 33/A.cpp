#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int A[MAXN];
int n;
int c[5];

int main(){
    scanf ("%d",&n);
    memset(c,0,sizeof c);
    c[3] = 1;
    bool chk = true;
    for (int i=1;i<=n;i++){
        scanf ("%d",&A[i]);
        if (c[A[i]]){
            chk = false;
        }
        int tmp1,tmp2;
        tmp1 = A[i];
        for (int j=1;j<=3;j++)
            if (c[j])
                tmp2 = j;
        memset(c,0,sizeof c);
        for (int j=1;j<=3;j++)
            if (j != tmp1 && j != tmp2)
                c[j] = true;
    }
    if (chk){
        printf ("YES\n");

    }else{
        printf ("NO\n");
    }
return 0;
}
