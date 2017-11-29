#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
int N;
int a[MAXN],fp[MAXN],cnt[MAXN];
char s[1005];
int main(){
    scanf ("%d",&N);
    scanf ("%s",s);
    for (int i=0;s[i];i++){
        cnt[s[i]] ++;
        fp[s[i]] = i;
    }
    int ans = -1;
    for (int i='a';i<='z';i++){
        if (cnt[i]==1){
            if (fp[i] < ans || ans == -1) 
                ans = fp[i];
        }
    }
    if (ans == -1){
        printf ("-1\n");
    }else{
        printf ("%c\n",s[ans]);
    }
    return 0;
    
}