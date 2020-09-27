#include <stdio.h>
#include <math.h>

int main(){
	int N;
	int flag = 0;
	int cnt = 0;
	int prime[2000]={0};
	int num[2000]={0};
	scanf("%d", &N);
	int time = N;
	for (int i = 2; i < N; i++){
		flag = 0;
		for (int j = 2; j <= sqrt(i); j++){
			if(i % j == 0){
				flag = 1;
				break;
			}
		}
		if (flag != 1){
			prime[cnt] = i;
			cnt++;
		}
	}
	for (int i = 0; i < cnt; i++){
		if (N % prime[i] == 0){
			while(N % prime[i] == 0){
				N = N / prime[i];
				num[i]++;
			}
		}
	}

	for(int i = 0; i < cnt; i++){
		for (int j = 0; j < num[i]; j++){
			printf("%d*", prime[i]);
		}
	}
	printf("\b ");
	return 0;
}

