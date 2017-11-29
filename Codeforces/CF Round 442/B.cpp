#include <bits/stdc++.h>
using namespace std;
//int ml[5005],mr[5005],cntb[5005];
int main(){
    string s,ss="";
    int ans = 0;
    vector <int> ml,mr,cntb;
    ml.resize(5005,0);
    mr.resize(5005,0);
    cntb.resize(5005,0);
    cin >> s;
    ss += '*';
    for (auto x : s){
        if (x!='a' && x!='b')
            continue;
        ss += x;
    }
    int cura = 0,curb=0;
    for (int i=0; ss[i];i++){
        if (ss[i]=='a'){
            cura++;
        }else if (ss[i]=='b'){
            curb++;
        }
        ml[i] = cura;
        cntb[i] = curb;
    }
    cura = 0;
    for (int i = ss.size();i;i--){
        if (ss[i]=='a'){
            cura++;
        }
        mr[i] = cura;
    }
    for (int i=1;i<ss.size();i++){
        for (int j=i;j<ss.size();j++){
            ans = max(ans, cntb[j] - cntb[i-1] + ml[i-1] + mr[j]);
        }
    }
    printf ("%d\n",ans);
    return 0;

}