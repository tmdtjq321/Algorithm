#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

char map[30][30];
int input[30][30];
int N;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};


bool cmp(int a, int b){
	if (a > b){
		return true;
	}
	return false;
}

bool isin(int x, int y){
	return x >= 0 && y >= 0 && x < N && y < N;
}

void dfs(int x, int y, int c){
	input[x][y] = c;
	for (int i = 0; i < 4; i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (isin(tx,ty) && input[tx][ty] == 1){
			dfs(tx,ty,c);
		}
	}
	return;
}

int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%s",map[i]);
		for (int j = 0; j < N; j++){
			if (map[i][j] == '1'){
				input[i][j] = 1;
			}
		}
	}
	int c = 1;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (input[i][j] == 1){
				dfs(i, j, ++c);
			}	
		}
	}
	printf("\n");
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%3d",input[i][j]);	
		}
		printf("\n");
	}
	int *res = (int *)malloc(sizeof(int) * c - 1);
	for (int i = 0; i < c - 1; i++){
		res[i] = 0;
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (input[i][j] != 0){
				res[input[i][j] - 2]++;
			}
		}
	}
	std::sort(res,res+c-1); 
//	std::sort(res,res+c-1,cmp);  // 역순 정렬  
	printf("%d\n", c - 1);
	for (int i = 0; i < c - 1; i++){
		printf("%d\n",res[i]);
	}
	
   	return 0;
}
