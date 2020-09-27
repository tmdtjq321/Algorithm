#include<stdio.h>
char board[22][22];
int visit[27];
int R, C;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int result = 0;

bool isin(int x, int y){
	return x >= 0 && y >= 0 && x < R && y < C;
}

void dfs(int x, int y, int d){
	if (d > result){
		result = d;
	}

	for (int i = 0; i < 4; i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (isin(tx,ty)){
			int visit_num = board[tx][ty] - 'A';
			if (visit[visit_num] == 0){
				visit[visit_num] = 1;
				dfs(tx,ty,d+1);
				visit[visit_num] = 0;
			}
		}
	}
	return;
}

int main(){
	scanf("%d%d",&R ,&C);
	for (int i = 0; i < R; i++){
		scanf("%s",board[i]);
	}
	visit[board[0][0] - 'A'] = 1;
	dfs(0,0,1);
	printf("%d",result);
   	return 0;
}
