#include<stdio.h>
int num[15];
int N = 1;
int visit[15];
int cnt = 0;
void print(){
	for (int i = 0; i < 6; i++){
		printf("%d ",visit[i]);
	}
	printf("\n");
}

void dfs(int now, int level){
	if (level == 6){
		cnt++;
		print();
		return;
	}
	for (int i = now; i < N; i++){
		visit[level] = num[i];
		dfs(i+1, level+1);
	}
	return;
} 

int main(){
	while(N != 0){
		scanf("%d", &N);
		for (int i = 0; i < N; i++){
			scanf("%d", &num[i]);
		}
		dfs(0,0);
		printf("\n");		
	}
	
   	return 0;
}
