#include <stdio.h>
#include <math.h>

int main(){
//	int prime[1001];
//	for (int i = 0; i < 1001; i++){
//		prime[i] = 1;
//	}
//	prime[0] = prime[1] = 0;
//	for (int i = 2; i < 1001; i++){
//		for (int j = i+i; j < 1001; j += i){
//			prime[j] = 0;
//		}
//	}
//	for (int i = 0; i < 1001; i++){
//		printf("%d = %d\n", i ,prime[i]);
//	}
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
	int count = 0;
	int count_prime = 0;
	int other_flag = 0;
	for (int i = 0; i < cnt; i++){
		if (prime[i + 1] == prime[i] + 2){
			printf("(%d %d) ", prime[i], prime[i + 1]);
			other_flag = 0;
			count++;
		}
	}
	printf("\n");
	for (int i = 0; i < cnt; i++){
		if (prime[i + 1] == prime[i] + 2){
			other_flag = 0;
			int sum;
			sum = prime[i] * prime[i+1] + 4;
			for (int j = 2; j < sqrt(sum); j++){
				if (sum % j == 0){
					other_flag = 1;
					break;
				}
			}
			if (other_flag != 1){
				printf("조건을 만족하는 P와 Q : %d %d\n ",prime[i],prime[i+1]);
				count_prime++;
			}
		}
	}
	printf("\n가까운 소수의 개수 %d\n", count);
	printf("조건을 만족하는 가까운 소수의 개수 %d", count_prime);

	return 0;
}



