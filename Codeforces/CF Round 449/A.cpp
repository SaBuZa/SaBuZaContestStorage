#include <bits/stdc++.h>
using namespace std;

int n,m;
//int a[MAXN];
string s;

int main(){
    //scanf ("%d",&n,&m);
    //scanf ("%s",&s[1]);
    cin >> n >> m;
    cin >> s;    
    for (int i=1;i<=m;i++){
        int l,r;
        char c1,c2;
        cin >> l >> r >> c1 >> c2;
        l--;r--;
        for (int j=l;j<=r;j++){
            if (s[j] == c1)
                s[j] = c2;
        }
    }    
    cout << s << endl;

    return 0;
}