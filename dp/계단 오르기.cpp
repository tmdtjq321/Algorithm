#include<stdio.h>
int N;
int dp[302];
int num[302];

int max(int a, int b){
	return a > b ? a : b;
}

int main(){
	int cnt = 0;
	scanf("%d",&N);
	for (int i = 0; i < N; i++){
		scanf("%d",&num[i]);
	} 
	dp[0] = num[0];
	dp[1] = max(num[0] + num[1],num[1]);
	dp[2] = max(num[2] + num[0],num[2]+num[1]);
	for (int i = 3; i < N; i++){
		dp[i] = max(num[i] + dp[i-2], num[i] + dp[i-3] + num[i-1]);
	}
	printf("%d",dp[N-1]);
   	return 0;
}
