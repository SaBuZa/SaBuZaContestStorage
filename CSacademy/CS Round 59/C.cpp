#include <bits/stdc++.h>
using namespace std;

#define MAXN 3005

int n;
char a[MAXN][MAXN];
char dp[MAXN][MAXN];
bool mark[MAXN][MAXN];
pair<int,int> path[MAXN][MAXN];
vector <char> ans;
stack <char> st;
int main(){
	memset(mark,0,sizeof mark);
	memset(path,0,sizeof path);
	ans.clear();
	for (int i=0;i<MAXN;i++){
		for (int j=0;j<MAXN;j++){
			dp[i][j] = 'z' + 1;
		}
	}
	scanf ("%d",&n);
	for (int i=1;i<=n;i++){
		scanf ("%s",&a[i][1]);
	}
	mark[1][1] = true;
	for (int i=2;i<=n;i++){
		char tmpmin = 'z' + 1;
		for (int j=1;j<=i;j++){
			if (mark[i-1][j] || mark[i-1][j-1]){
				mark[i][j] = true;
				tmpmin = min(tmpmin,a[i][j]);
			}
		}
		for (int j=1;j<=i;j++){
			if (mark[i][j]){
				if (a[i][j] > tmpmin)
					mark[i][j] = false;
			}
		}
	}
	for (int kk=1;kk<=n;kk++){
		if (mark[n][kk]){
			int i = n,j = kk;
			for (int i=n;i>=1;i--){
				st.push(a[i][j]);
				if (mark[i-1][j]){
					continue;
				}
				if (mark[i-1][j-1]){
					j = j - 1;
					continue;
				}
			}
			break;
		}
	}
	while (!st.empty()){
		printf ("%c",st.top());
		st.pop();
	}
	return 0;

}
