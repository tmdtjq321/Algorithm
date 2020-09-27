#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int M, N;
	char now;
	int* arr;
	printf("M, N? ");
	while(1){
		fflush(stdin);
		scanf("%d %d", &M, &N);
		if (M == 0 && N == 0){
			exit(1);
		} 
		if (M == 0 || N == 0){
			printf("�ٽ� �Է����ּ���\n");
			continue;
		}
		else if (M >= 100 || N >= 100){
			printf("�ٽ� �Է����ּ���\n");
			continue;
		}
		else if (M == N){
			printf("�ٽ� �Է����ּ���\n");
			continue;
		}
		if (M == 1){
			M = 2;
		}	
		arr = (int *)malloc(sizeof(int) * (N + 1));
	
		int flag;
		for (int i = M; i <= N ; i++){
			flag = 0;
			for (int j = 2; j <= sqrt(i); j++){
				if (i % j == 0){
					flag = 1;
					break;
				}
			}
			if (flag != 1){
				arr[i] = 1;
			}
		}
		int cnt = 0;
		for (int i = 0; i <= N; i++){
			if (arr[i] == 1){
				printf("%d ", i);
				cnt++;
			}
			if (cnt == 5){
				printf("\n");
				cnt = 0;
			}
		}
		free(arr);

		printf("\n����ұ��?(Y/N)");
		fflush(stdin);
		scanf("%c", &now);
		if (now == 'N'){
			break;
		}
	}
	return 0;
}

