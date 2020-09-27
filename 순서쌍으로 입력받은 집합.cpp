#include <stdio.h>
#include <stdlib.h>

int main(){
	int set[51]={0};
	int isEmpty[50] = {0};
	int input, input2;
	int cnt = 1;
	while(1){
		scanf("%d,%d",&input,&input2);
		if (input == 100 || input2 == 100){
			break;
		}
		if (set[input] == 0 && set[input2] == 0){
			set[input] = cnt;
			set[input2] = cnt;
			cnt++;
		} 
		else if (set[input] != 0 && set[input2] == 0){
			set[input2] = set[input];
		}
		else if (set[input] == 0 && set[input2] != 0){
			set[input] = set[input2];
		}
		else if (set[input] != 0 && set[input2] != 0){
			if (set[input] < set[input2]){
				int small = set[input];
				int big = set[input2];
				for (int i = 0; i < 51; i++){
					if (set[i] == big){
						set[i] = small;
					}
				}
			}
			else if (set[input2] < set[input]){
				int small = set[input2];
				int big = set[input];
				for (int i = 0; i < 51; i++){
					if (set[i] == big){
						set[i] = small;
					}
				}
			}
		}
	}

	for (int i = 1; i <cnt; i++){
		for (int j = 0; j < 51; j++){
			if (set[j] == i){
				isEmpty[i] = 1;
			}
		}
	}
	
	int count = 1;
	for (int i = 1; i < cnt; i++){
		if (isEmpty[i] != 1){
			continue;
		}
		printf("class%d: ", count);
		count++;
		for (int j = 0; j < 51; j++){
			if (set[j] == i){
				printf("%d ", j);
			}
		}
		printf("\n");
	}	
	
	return 0;
}

