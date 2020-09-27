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
			if(mineral[i][j]==k)	// mineral[i][j] ���� ������ �Ʒ��� �������鼭 k�� ���ٸ� xmin = i���ǰ� Ż�� �������� xmin = -1 
			{					// �̋� xmin�� ���߿� ���ִ� �̳׶��� ���� ���� ���� 
				xmin=i;
				break;
			}
		xmax=R;
		for(;i<R;i++)		// xmin���� �ǾƷ����� ���� �ϴµ�, xmin�� ���� ���� ���̷� �������� xmax�� �̳׶��� ������ �׳��̷� �ʱ�ȭ�ϰ� �ƴϸ� R�� �ʱ�ȭ 
			if(mineral[i][j]==k) xmin=i;
			else if(map[i][j]=='x')
			{
				xmax=i;
				break;
			}

		if(xmin>=0)	// �ش� �̳׶��� ���ٸ� xmin�� -1�̹Ƿ� �ش�̳׶��� ���� �� ���ǹ������� 
		{
			ck[j]=1;	// ���߿� ���ִ� �̳׶��� ��==j 
			if(mn>xmax-xmin-1) mn=xmax-xmin-1;	// mn�� �� �࿡�� ���������� ������ �ּҰ� 
		}
	}

	if(mn)
		for(j=0;j<C;j++)
			if(ck[j])	// ���߿� �� �̳׶��� ���ٸ� ck[j]���� 0�̴ϱ� �����ǹ��� ����ع����� 
				for(i=C-1;i>=0;i--)	// �Ʒ����� ���� 
					if(mineral[i][j]==k)
					{
						map[i][j]='.';
						map[i+mn][j]='x';
					}
	return mn;
}

void dfs(int x, int y, int c){
	if (x == R-1){	// �ٴڿ� ��´ٸ� isgrounded[c]�� ���� 
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
		if (i % 2 == 0){	// ���� 
			for (int j = 0; j < C; j++){
				if (map[R-input][j] == 'x'){	// �̳׶��� ������ �ν������� dfs���� 
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
			for (int i = 2; i <= cnt; i++){		// ������ �߿��� ���߿� �� �̳׶��� �ִٸ� down���� 
				if (isgrounded[i] == 0){
					down(i);
					flush();	// �ٽ� mineral�� �ʱ�ȭ 
				}
			}
			flush();
			cnt = 1;
		}
		else{	// ������ 
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
