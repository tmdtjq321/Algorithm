#include<stdio.h>
#include<algorithm>
using namespace std;
int n, k;
int coin[105];
int dp[10005];
int real_c[105];
int s = 0, e = 0;
int cnt = 0;

int min(int x, int y){
	return x > y ? y : x;
}

int main()
{	
	scanf("%d%d",&n,&k);
	
	for (int i = 1; i <=k; i++){
 		dp[i] = 10005;	
	}
	
	for (int i = 0; i < n; i++){	
		scanf("%d",&coin[i]);
	}
	std::sort(coin,coin+n);
	for (; e < n; e++){		// 중복 제거 
		if (e == 0 || coin[s] != coin[e]){
			s = e;
			real_c[cnt] = coin[e];
			cnt++;
		}
	}
	 
	for (int i = 0; i < cnt; i++){	
		int num = real_c[i];
		for(int j = 1; j <=k; j++){
			if (j-num >= 0){
				dp[j] = min(dp[j], dp[j-num] + 1);
			}
		}
	}
	if (dp[k] == 10005){
		printf("-1");
	}
	else{
		printf("%d",dp[k]);
	}
	
	return 0;
}
// dp[1]이란 동전들로 1을 만드는데 필요한 최소 동전 
// 3 15			3 15
// 1 5 12		2 5 12
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
// 0 0 1 0 2 0 3 0 4 0 5  0  6  0  7  0
// 0 0 1 0 2 1 3 2 4 3 2  4  3  5  4  3
// 0 0 1 0 2 1 3 2 4 3 2  4  1  5  2  3  


