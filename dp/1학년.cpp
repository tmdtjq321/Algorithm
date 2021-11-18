#include <stdio.h>
using namespace std;
typedef long long ll;
int N;
ll dp[102][22];
int arr[102];

void dynamic(int depth){
	if (depth == N-2){
		return;
	}
	for (int i = 0; i <= 20; i++){
		if (dp[depth][i] != 0){
			if (0 <= i+arr[depth+1] && i+arr[depth+1] <= 20){
				dp[depth+1][i+arr[depth+1]] += dp[depth][i];
			}
			if (0 <= i-arr[depth+1] && i-arr[depth+1] <= 20){
				dp[depth+1][i-arr[depth+1]] += dp[depth][i];
			}
		}
	}
	dynamic(depth+1);
}


int main(){
	scanf("%d",&N);
	for (int i = 0; i < N; i++){
		scanf("%d",&arr[i]);
	}
	dp[0][arr[0]] = 1;
	dynamic(0);
	printf("%lld\n",dp[N-2][arr[N-1]]);
	
	return 0;
}
