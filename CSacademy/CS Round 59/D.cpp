#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
typedef long long ll;

int N;
ll W, H;
ll L[MAXN];
ll nextWord[MAXN],cycleCntWord[MAXN],wordShift[MAXN];
ll scWord[MAXN], prefSum[MAXN];
ll remW,remH;
ll savedMap[MAXN],savedMapLast[MAXN];
ll curSum,nCy=0;
int curSz;

void removeL(int idx){
	curSz--;
	curSum -= L[idx];
	if (idx==1) nCy--;
}

void addR(int idx){
	curSz++;
	curSum += L[idx];
	if (idx==1) nCy ++;
}

void clearmem(){
	memset(nextWord,0,sizeof nextWord);
	memset(cycleCntWord,0,sizeof cycleCntWord);
	memset(wordShift,0,sizeof wordShift);
	memset(scWord,0,sizeof scWord);
	memset(prefSum,0,sizeof prefSum);
	memset(savedMap,0,sizeof savedMap);
	memset(savedMapLast,0,sizeof savedMapLast);
	nCy = 0;
	curSum = 0;
}

int main(){
	//ios_base::sync_with_stdio(false);
	//cin >> N >> W >> H;
	ll CycleNum=0,preCycle=0,addCycleLen=0,tmpCnt = 0;
	clearmem();
	scanf ("%d%lld%lld",&N,&W,&H);
	for (int i=1;i<=N;i++){
		//cin >> L[i];
		scanf ("%lld",&L[i]);
		prefSum[i] = prefSum[i-1] + L[i];
	}
	remW = W;
	if (prefSum[N] + N - 1 <= W ){
		tmpCnt++;
		remW = W - (prefSum[N] + N - 1);
		cout << "wut " << remW << endl;
		addCycleLen = prefSum[N] + N;
		CycleNum = remW / addCycleLen;
		remW %= addCycleLen;
		tmpCnt += CycleNum;
		preCycle = tmpCnt;
		remW--;
	}
	cout << "Pre " << preCycle << endl;
	int j = 1;

	for (int i=1;i<=N;i++){
//		cout << curSum << " " << curSz << " " << remW << endl;
		while (curSum + curSz + L[j] <= remW){
			addR(j);
			j++;
			if (j>N){
				j %= N;	
			}
		}
		nextWord[i] = j;
		scWord[i] = nCy;
		removeL(i);
	}
	//if (W>=L[1]) scWord[1]++;
	for (int i=1;i<=N;i++){
		scWord[i] += preCycle;
		//cout << "scWord[" << i << "] : " << scWord[i] << endl;
	}
	
	int curWord = 1;
	ll mySum = 0;
	ll ans=0;
	remH = H;
	for (int i=1;i<=H;i++){
	//	cout << "i : " << i << " -> " << curWord << "SUM : " << mySum <<  endl;
		if (savedMapLast[curWord] > 0){
			ll cyCost = mySum - savedMap[curWord];
			ll cyLen = savedMapLast[curWord] - remH;
			//remH = H - i;
			ll cyNum = remH / cyLen;
			mySum += cyCost * cyNum;
			remH %= cyLen;
			if (N==100000){
				//cout << cyLen << " " << remH  << endl;							
			}
			break;
		}
		savedMap[curWord] = mySum;
		savedMapLast[curWord] = remH;
		mySum += scWord[curWord];
		curWord = nextWord[curWord];		
		remH--;
	}
//	cout << "O : " << mySum << endl;
	while (remH){
		mySum += scWord[curWord];
		curWord = nextWord[curWord];
		remH--;
	}
	cout << "<test>\n" << endl;
	printf ("%lld\n",mySum);
	//cout << mySum << endl;
	return 0;

}
