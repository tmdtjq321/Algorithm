#include<stdio.h>
int n, k;
int coin[105];
int dp[10005];

int main()
{	
	scanf("%d%d",&n,&k);
	dp[0] = 1;
	for (int i = 0; i < n; i++){	
		scanf("%d",&coin[i]);
		int num = coin[i];
		for(int j = 1; j <=k; j++){
			if (j-num >= 0){
				dp[j] += dp[j-num];
			}
		}
	}
 
	printf("%d",dp[k]);
	return 0;
}
