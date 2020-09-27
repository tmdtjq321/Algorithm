#include <stdio.h>

int arr[9][9];
int N;
int ans = 0;

bool safe(int x, int y){
  return x>=0 && y>=0 && x<N && y<N;
}
bool chk(int x, int y){
  for(int i=0;i<N;i++)
    if(arr[x][i] || arr[i][y]) return false;
  for(int i=0;i<N;i++){
    if(safe(x+i,y+i) && arr[x+i][y+i]) return false;
    if(safe(x-i,y-i) && arr[x-i][y-i]) return false;
    if(safe(x-i,y+i) && arr[x-i][y+i]) return false;
    if(safe(x+i,y-i) && arr[x+i][y-i]) return false;
  }
  return true;
}

void print(){
	printf("\n");
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
void dfs(int r){
	bool can;
	if (r == N){
		ans++;
		return;
	}
	for (int c = 0; c < N; c++){	// 통과한다는 것은 해당 행에 퀸을 놓을 수 없다는 것 
		can = chk(r,c);
		if(can){
			printf("in %d %d\n", r, c);
			arr[r][c] = 1;
			print();
			dfs(r+1);
			printf("refresh %d %d\n",r,c);
			arr[r][c] = 0;
			print();
		}
		if (r == 0){
			arr[r][c] = 0;
		}
	}
	return;
}

int main(){
	scanf("%d", &N);
	int c = 0;
	int cnt = 0;
	int r = 1;
	dfs(0);
	printf("%d",ans);
   	return 0;
}
