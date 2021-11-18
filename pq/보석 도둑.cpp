#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
int N, K;
ll ans;
pair<ll,ll> dia[300005];
int bag[300005];
priority_queue<ll> dia_pq;	// 최대 힙 
// 가격이 높은 것 부터 

int main() {
	scanf("%d%d",&N,&K);
	
	for (int i = 0; i < N; i++){
		scanf("%lld%lld",&dia[i].first,&dia[i].second);
	}
	
	for (int i = 0; i < K; i++){
		scanf("%lld",&bag[i]);
	}
	
	sort(dia,dia+N);
	sort(bag,bag+K);
	
	int jcnt = 0;
	for (int i = 0; i < K; i++){
		while(jcnt < N && dia[jcnt].first <= bag[i]){
			dia_pq.push(dia[jcnt].second);
			jcnt++;
		}
		if (!dia_pq.empty()){
			ans += dia_pq.top();
			dia_pq.pop();
		}
	}	
	printf("%lld",ans);
	return 0;
}
