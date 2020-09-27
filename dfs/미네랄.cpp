#include<stdio.h>
char map[105][105];
int mineral[105][105];
int R,C,N;
int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
int cnt = 1;
int isgrounded[105];

bool isin(int x, int y){
	return x >=0 && y>=0 && x < R && y < C;
}

void print(){
	for(int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}

void flush(){
	for(int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			if (map[i][j] == 'x'){
				mineral[i][j] = 1;
			}
			if (map[i][j] =='.'){
				mineral[i][j] = 0;
			}
			isgrounded[i] = 0;
		}
	}
}

bool down(int k)
{
	int i, j, mn=100, xmax, xmin, ck[100];

	for(j=0;j<C;j++) ck[j]=0;
	
	for(j=0;j<C;j++)
	{
		xmin=-1;
		for(i=0;i<R;i++)
			if(mineral[i][j]==k)	// mineral[i][j] 에서 위에서 아래로 내려오면서 k와 같다면 xmin = i가되고 탈출 못만나면 xmin = -1 
			{					// 이떄 xmin은 공중에 떠있는 미네랄의 가장 높은 높이 
				xmin=i;
				break;
			}
		xmax=R;
		for(;i<R;i++)		// xmin부터 맨아래까지 진행 하는데, xmin은 가장 낮은 높이로 내려오고 xmax는 미네랄을 만나면 그높이로 초기화하고 아니면 R로 초기화 
			if(mineral[i][j]==k) xmin=i;
			else if(map[i][j]=='x')
			{
				xmax=i;
				break;
			}

		if(xmin>=0)	// 해당 미네랄이 없다면 xmin은 -1이므로 해당미네랄이 있을 때 조건문안으로 
		{
			ck[j]=1;	// 공중에 떠있는 미네랄의 열==j 
			if(mn>xmax-xmin-1) mn=xmax-xmin-1;	// mn은 각 행에서 떨어저야할 높이의 최소값 
		}
	}

	if(mn)
		for(j=0;j<C;j++)
			if(ck[j])	// 공중에 뜬 미네랄이 없다면 ck[j]들은 0이니까 이조건문을 통과해버린다 
				for(i=C-1;i>=0;i--)	// 아래부터 진행 
					if(mineral[i][j]==k)
					{
						map[i][j]='.';
						map[i+mn][j]='x';
					}
	return mn;
}

void dfs(int x, int y, int c){
	if (x == R-1){	// 바닥에 닿는다면 isgrounded[c]에 저장 
		isgrounded[c] = c;
	}
	mineral[x][y] = c;
	for (int i = 0; i < 4; i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (isin(tx,ty) && mineral[tx][ty] == 1){
			dfs(tx,ty,c);
		}
	}
	return;
}


int main(){
	scanf("%d%d",&R, &C);
	for(int i = 0; i < R; i++){
		scanf("%s",map[i]);
		for (int j = 0; j < C; j++){
			if (map[i][j] == 'x'){
				mineral[i][j] = 1;
			}
		}
	}
	scanf("%d",&N);
	for (int i = 0; i < N; i++){
		int input;
		scanf("%d",&input);
		if (i % 2 == 0){	// 왼쪽 
			for (int j = 0; j < C; j++){
				if (map[R-input][j] == 'x'){	// 미네랄을 만나면 부숴버리고 dfs진행 
					map[R-input][j] = '.';
					mineral[R-input][j] = 0;
					for (int l = R-1; l >= 0; l--){
						for (int k = 0; k < C; k++){
							if (mineral[l][k] == 1){
								cnt++;
								dfs(l,k,cnt);
							}
						}
					}
					break;
				}
			}
			for (int i = 2; i <= cnt; i++){		// 영역들 중에서 공중에 뜬 미네랄이 있다면 down진행 
				if (isgrounded[i] == 0){
					down(i);
					flush();	// 다시 mineral을 초기화 
				}
			}
			flush();
			cnt = 1;
		}
		else{	// 오른쪽 
			for (int j = C-1; j >= 0; j--){
				if (map[R-input][j] == 'x'){	
					map[R-input][j] = '.';
					mineral[R-input][j] = 0;
					for (int l = R-1; l >= 0; l--){
						for (int k = 0; k < C; k++){
							if (mineral[l][k] == 1){
								cnt++;
								dfs(l,k,cnt);
							}
						}
					}
					break;
				}
			}
			for (int i = 2; i <= cnt; i++){
				if (isgrounded[i] == 0){
					down(i);
					flush();
				}
			}
			flush();
			cnt = 1;
		}
	}
	print();
	
   	return 0;
}
