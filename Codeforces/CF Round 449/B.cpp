#include <bits/stdc++.h>
using namespace std;

long long k,p;
long long ans = 0;
char myNum[1005];
long long sm[100005];
int sz = 0;
queue<string> q;
vector <string > ml;

void inibuild(){
    int i=0;
    while (ml.size() <= 100000){
        string cur = ml[i];
        int hsz = cur.size()/2;
        string rev = cur.substr(0,hsz);
        reverse(rev.begin(),rev.end());
        string mys = cur.substr(0,hsz) + "00" + rev;
        ml.push_back(mys);
        hsz = mys.size()/2;
        for (char ch = '1' ; ch <= '9' ; ch++){
            mys[hsz] = mys[hsz-1] = ch;
            ml.push_back(mys);
        }
        i++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    memset(sm,0,sizeof sm);
    ml.push_back("11");
    ml.push_back("22");
    ml.push_back("33");
    ml.push_back("44");
    ml.push_back("55");
    ml.push_back("66");
    ml.push_back("77");
    ml.push_back("88");
    ml.push_back("99");
    inibuild();

    cin >> k >> p;
    for (int i=1;i<=100000;i++){
        stringstream vs(ml[i-1]);
        long long tmp = 0;
        vs >> tmp;
        
        sm[i] = sm[i-1] + (tmp%p);
        sm[i] %= p;
    }
    cout << sm[k] << endl;
    return 0;
}