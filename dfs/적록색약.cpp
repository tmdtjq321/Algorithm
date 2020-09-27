#include<stdio.h>
char picture[105][105];
int ans[105][105];
int N;
int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};


bool isin(int x, int y){
	return x >= 0 && y >= 0 && x < N && y < N;
}

void print(){
	printf("\n");
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
	return;
}

void dfs(int x, int y, int c){
	ans[x][y] = c;
	for (int i = 0; i < 4; i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (isin(tx,ty) && (picture[x][y] == picture[tx][ty]) && ans[tx][ty] == 0){
			dfs(tx,ty,c);
		}
	}
	return;
}

int main(){
	int c = 0;
	scanf("%d",&N);
	for (int i = 0; i < N; i++){
		scanf("%s", picture[i]);
	}
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (picture[i][j] == 'R' && ans[i][j] == 0){
				c++;
				dfs(i,j,c);
			}
			else if (picture[i][j] == 'B' && ans[i][j] == 0){
				c++;
				dfs(i,j,c);
			}
			else if (picture[i][j] == 'G' && ans[i][j] == 0){
				c++;
				dfs(i,j,c);
			}
		}
	}
	print();
	printf("%d ",c);
	c = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			ans[i][j] = 0;
			if (picture[i][j] == 'G'){
				picture[i][j] = 'R';
			}
		}
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (picture[i][j] == 'R' && ans[i][j] == 0){
				c++;
				dfs(i,j,c);
			}
			else if (picture[i][j] == 'B' && ans[i][j] == 0){
				c++;
				dfs(i,j,c);
			}
		}
	}
	printf("%d",c);
	print();
   	return 0;
}
