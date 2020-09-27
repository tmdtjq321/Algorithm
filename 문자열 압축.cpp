#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getCount(char arr[], int s, int e){	// s는'('의 인덱스 e는 ')'인덱스  
	int t = 1;
	int sum = 0;
	for (int i = e-1; i > s; i--, t *= 10){
		sum += (arr[i] - '0') * t;
	}
	return sum;
}
int main(){
	char N;
	char input[1000]; 
	char rep[1000];
	int num[1000] = {0};
	int cnt = 1;
		int now = 0;
	int start_index, end_index;
	printf("압축, 해제 ");
	scanf("%c", &N);
	if (N == 'C'){
		printf("압축할 문자열 : ");
		scanf("%s", input);
		printf("압축된 문자열 : ");
		for (int i = 0; i < strlen(input); i++){
			if (input[i] == input[i+1]){
				cnt++;
			}
			if (input[i] != input[i+1] && cnt < 4){
				for (int j = 0; j < cnt; j++){
					printf("%c", input[i]);
				}
				cnt = 1;
			}
			else if (input[i] != input[i+1] && cnt > 3){
				printf("(%d)%c",cnt,input[i]);
				cnt = 1;
			}
		}
	}
	else if (N == 'U'){
		printf("압축풀 문자열 : ");
		scanf("%s", input);
		printf("압축푼 문자열 : ");
		for (int i = 0; i < strlen(input); i++){
			if (input[i] == '('){
				int start = i;
				while(input[i] != ')'){
					i++;
				}
				int end = i;
				rep[now] = input[i+1];
				num[now] = getCount(input, start, end);
				now++;
			}
			else{
				if(input[i-1] != ')'){
					rep[now] = input[i];
					num[now] = 1;
					now++;
				}
			}
		}
		for(int i = 0; i < now; i++){
			for (int j = 0; j < num[i]; j++){
				printf("%c",rep[i]);
			}
		}
	}
		
	return 0;
}

