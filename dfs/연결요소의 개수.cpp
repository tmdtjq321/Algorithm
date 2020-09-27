#include<stdio.h>
int N, M;
int map[1005][1005];	// 요소들을 인접행렬로 저장 
int visit[1005];
int cnt = 0; 

void dfs(int x, int count, int start_num){
	if (count != 0 && start_num == x){
		return;
	}
	visit[x] = cnt;
	for (int i = 0; i < N; i++){
		if (map[x][i] == 1 && visit[i] == 0){
			dfs(i,count+1,start_num);
		}
	}
}


int main(){
	scanf("%d%d",&N, &M);
	for (int i = 0; i < M; i++){
		int st, ar;
		scanf("%d%d",&st,&ar);
		map[st-1][ar-1] = 1;
		map[ar-1][st-1] = 1;
	}	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (map[i][j] == 1 && visit[i] == 0 && visit[j] == 0){
				cnt++;
				dfs(i,0,i);
				
			}
		}
	}
	for (int i = 0; i < N; i++){
		if (visit[i] == 0){
			cnt++;
		}
		printf("%d ",visit[i]);
	}
	printf("\n");
	
	printf("%d",cnt);
   	return 0;
}


