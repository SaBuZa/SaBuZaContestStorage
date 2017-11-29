#include <bits/stdc++.h>
using namespace std;

int n;
bool valid[200005];
vector <int> v;

void precompute(){
    int base = 0;
    for (int len = 1;len<10;len++){
        base |= (1 << (len-1));
        int i = len - 1;
        //for (int i = 0 ; i < len ; i++){
            //printf ("%d\n",base<<i);
            //valid[base << i] = true;
            v.push_back(base<<i);
        //}
    }
}

int main(){
    precompute();
    scanf ("%d",&n);
    for (int i=v.size()-1;i>=0;i--){
        if ((n % v[i]) == 0){
            printf ("%d\n",v[i]);
            return 0;
        }
    }
return 0;
}
