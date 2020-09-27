#include<stdio.h>
typedef long long ll;
int N;
ll dp[100];

int main(){
	scanf("%lld", &N);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < N; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	printf("%lld",dp[N-1]);
   	return 0;
}
