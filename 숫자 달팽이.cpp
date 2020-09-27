#include <stdio.h>
#include <stdlib.h>

int roll_clock(int arr[][10], int cnt, int N, int x, int y){
	int limit = N * N;
	for (int i = 1; i < N; i++){ // - >
		if (arr[y][i] == 0){
			arr[y][i] = cnt;
			if (cnt == limit){ 
				return 0;
			}
			cnt++;
			x++;
		}
	}
	for (int i = 1; i < N; i++){	// ก้ 
		if (arr[i][x] == 0){
			arr[i][x] = cnt;
			if (cnt == limit){
				return 0;
			}
			cnt++;
			y++;
		}
	}
	for (int i = N-2; i >= 0; i--){ // < -
		if (arr[y][i] == 0){
			arr[y][i] = cnt;
			if (cnt == limit){
				return 0;
			}
			cnt++;
			x--;
		}
	}
	for (int i = N-2; i >=0; i--){	// ก่ 
		if (arr[i][x] == 0){
			arr[i][x] = cnt;
			if (cnt == limit){
				return 0;
			}
			cnt++; 
			y--;
		}
	}
	if (cnt < limit + 1){
		roll_clock(arr, cnt, N, x, y);	
	}
	return cnt;
}

int roll_declock(int arr[][10], int cnt, int N, int x, int y){
	int limit = N * N;
	for (int i = 1; i < N; i++){ // ก้
		if (arr[i][x] == 0){
			arr[i][x] = cnt;
			if (cnt == limit){
				return 0;
			}
			cnt++;
			y++;
		}
	}
	for (int i = 1; i < N; i++){ // - >
		if (arr[y][i] == 0){
			arr[y][i] = cnt;
			if (cnt == limit){
				return 0;
			}
			cnt++;
			x++;
		}
	}
	for (int i = N-2; i >=0; i--){	// ก่ 
		if (arr[i][x] == 0){
			arr[i][x] = cnt;
			if (cnt == limit){
				return 0;
			}
			cnt++;
			y--;
		}
	}
	for (int i = N-2; i >= 0; i--){ // < -
		if (arr[y][i] == 0){
			arr[y][i] = cnt;
			if (cnt == limit){
				return 0;
			}
			cnt++;
			x--;
		}
	}
	if (cnt < limit + 1){
		roll_declock(arr, cnt, N, x, y);	
	}
}

int main(){
	int N;
	int cnt = 1;
	int x = 0, y = 0;
	int limit;
	printf("Input N = ? ");
	scanf("%d", &N);
	if (N == 0){
		exit(1);
	}
	else{
		if (N > 9){
			printf("Input N = ? ");
			scanf("%d", &N);
		}
	}
	int arr[10][10] = {0};
	arr[0][0] = cnt;
	cnt++;
	limit = N * N;
	if (N % 2 != 0){
		roll_clock(arr, cnt, N, x, y);	
	}
	else{
		roll_declock(arr, cnt, N, x, y);
	}
	printf("\n");
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%d	", arr[i][j]); 
		}
		printf("\n");
	}
}

