#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
    cin >> s;
    vector<string> v;
    
    v.push_back("Danil");
    v.push_back(string("Olya"));
    v.push_back(string("Slava"));
    v.push_back(string("Ann"));
    v.push_back(string("Nikita"));
    
    int ck = 0;
    for (auto x : v){
        auto lf = s.find(x);
        auto rf = s.rfind(x);
        if (lf!=s.npos){
            ck++;
            if (rf != lf)
                ck++;
        }
        //cout << s.find(x) << endl;
        //cout << x << endl;
    }
    if (ck>1 || ck==0) printf ("NO\n");
    else printf ("YES\n");
    return 0;
    
}