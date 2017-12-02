#include <bits/stdc++.h>
using namespace std;

string f0 = " What are you doing at the end of the world? Are you busy? Will you save us?";
string sa = " What are you doing while sending \"";
string sb = " \"? Are you busy? Will you send \"";
string sc = " \"?";
//string st = " What are you doing while sending \"What are you doing at the end of the world? Are you busy? Will you save us?\"? Are you busy? Will you send \"What are you doing at the end of the world? Are you busy? Will you save us?\"?";
unsigned long long slen[100005];
long long a,b,c;
long long K;
int N;

char sfind(int n, unsigned long long k ){
    if (k > slen[n]) return '.';
    if (n == 0) return f0[k];
    if (k > a && k <= a + slen[n-1]){
        return sfind(n-1, k - a);
    }else if (k > a + slen[n-1] + b && k <= a + 2*slen[n-1] + b){
        return sfind (n-1, k - (a + slen[n-1] + b));
    }else if (k <= a){
        return sa[k];
    }else if (k > a+slen[n-1] && k <= a + b + slen[n-1]){
        return sb[k - (a + slen[n-1])];
    }else if (k > a + b + 2*slen[n-1] && k <= slen[n]){
        return sc[k - (a + 2*slen[n-1]+b)];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    slen[0] = f0.size() - 1;
    a = sa.size() - 1;
    b = sb.size() - 1;
    c = sc.size() - 1;
    for (int i=1;i<=100000;i++){
        if (i < 57)
            slen[i] = a + b + c + 2 *slen[i-1];
        else
            slen[i] = slen[i-1];
    }
    int TC;
    cin >> TC;
    for (int tc = 1 ; tc <= TC; tc++){
        cin >> N >> K;    
        cout << sfind (N,K);
    }
    return 0;

}