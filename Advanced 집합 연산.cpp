#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N;
	int input;
	printf("몇개의 집합(n)? ");
	scanf("%d", &N);
	char order[21];
	int set[26][21]={0};
	int result[21] = {0};
	for (int i = 0; i < N; i++){
		printf("집합 %c의 원소? ", 65 + i);
		for (int j = 1; j < 21; j++){
			scanf("%d", &input);
			if (input == -1){
				break;
			}
			set[i][input] = 1;
		}
	}	
	for (int i = 0; i < N; i++){
		printf("%c = { ", 65 + i);
		for (int j = 1; j < 21; j++){
			if (set[i][j] == 1){
				printf("%d ", j);
			}
		}
		printf("}\n");
	}
	int flag = 0;
	printf("연산식? ");
	scanf("%s", order);
	for (int i = 0; i < strlen(order); i++){
		if (order[i] == '+'){
			int num, num2;
			num = (int)order[i-1] - 65;
			num2 = (int)order[i+1] - 65;
			for (int j = 1; j < 21; j++){
				if (set[num][j] == 1){
					result[j] = 1;
				}
				else if (set[num2][j] == 1){
					result[j] = 1;
				}
			}
			flag = 1;
		}
		else if (order[i] == '*'){
			int num, num2;
			num = (int)order[i-1] - 65;
			num2 = (int)order[i+1] - 65;
			if (flag == 0){
				flag = 1;
				for (int j = 1; j < 21; j++){
					if (set[num][j] == 1 && set[num2][j] == 1){
						result[j] = 1;
					}
					else{
						result[j] = 0;
					}
				}
			}
			else{
				for (int j = 1; j < 21; j++){
					if (result[j] == 1 && set[num2][j] == 1){
						result[j] = 1;
					}
					else{
						result[j] = 0;
					}
				}
			}
			
		}
		else if (order[i] == '-'){
			int num, num2;
			num = (int)order[i-1] - 65;
			num2 = (int)order[i+1] - 65;
			if (flag == 0){
				flag = 1;
				for (int j = 1; j < 21; j++){
					if (set[num][j] == 1){
						result[j] = 1;
					}
				}
				for (int j = 1; j < 21; j++){
					if (result[j] == 1 && set[num2][j] == 1){
						result[j] = 0;
					}
				}
			}
			else{
				for (int j = 1; j < 21; j++){
					if (result[j] == 1 && set[num2][j] == 1){
						result[j] = 0;
					}
				}
			}
			
		}
	}
	printf("%s = {", order);
	
	for (int i = 1; i < 21; i++){
		if (result[i] == 1){
			printf("%d,",i);
		}
	}
	printf("\b}\n");
	return 0;
}

