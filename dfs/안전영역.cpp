#include<stdio.h>
int N;
int map[100][100];
int res[100][100];
int dx[]= {1,-1,0,0}, dy[] = {0,0,1,-1};
int max = 0;

bool isin(int x, int y){
	return x >= 0 && y >= 0 && x < N && y < N;
}

void print(){
	printf("\n");
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}
}

void dfs(int x, int y, int c){
	res[x][y] = c;
	for (int i = 0; i < 4; i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (isin(tx,ty) && res[tx][ty] == 1){
			dfs(tx,ty,c);
		}
	}
	return;
}

void safe_zone(int h){
	int c = 1;
	for (int i = 0; i < N; i++){	// h보다 높은 잠기지않은지대를 1로 
		for (int j = 0; j < N; j++){
			if (map[i][j] > h){
				res[i][j] = 1;
			}
		}
	}
	printf("%d이하",h);
	print();
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (res[i][j] == 1){
				c++;
				dfs(i,j,c);
			}
		}
	}
	if (max < c){
		max = c;
	} 
	printf("result\n");
	print();
}

int main(){
	scanf("%d",&N);
	int max_num = 0;	// 제일 높은 지대 
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%d",&map[i][j]);	
			if (max_num < map[i][j]){
				max_num = map[i][j];
			}	
		}
	}
	
	for (int i = 0; i < max_num + 1; i++){
		safe_zone(i);
		for (int j = 0; j < N; j++){
			for (int k = 0; k < N; k++){
				res[j][k] = 0;
			}
		}
	}
	printf("%d",max-1);
	
   	return 0;
}

