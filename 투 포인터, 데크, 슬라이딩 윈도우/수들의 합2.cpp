#include<stdio.h>
int N, K, s, e, sum, cnt;
int num[10005];

int main() {
	scanf("%d%d",&N,&K);
	for (int i = 0; i < N; i++){
		scanf("%d",&num[i]);
	}
	sum = num[s];
	while(true){
		if (e >= N){
			break;
		}
		if (sum > K){
			sum -= num[s];
			s++;
		}
		else if (sum < K){
			e++;
			sum += num[e];
		}
		else{
			cnt++;
			e++;
			sum += num[e];
		}
	}
	printf("%d",cnt);
	return 0;
}
