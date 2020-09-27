#include<stdio.h>
#include<queue>
using namespace std;
char input[12][6];
int res[12][6];
int dx[]= {1,-1,0,0}, dy[] = {0,0,1,-1};
int count = 0;

struct point{
	int x,y;
};


bool isin(int x, int y){
	return x >= 0 && y >= 0 && x < 12 && y < 6;
}

bool chk(char tmp[12][6]){
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 6; j++){
			if (tmp[i][j] != input[i][j]){
				return false;
			} 
		}
	}
	return true;
}

void gravity(){
	for (int i = 0; i < 6; i++){
		for (int j = 10; j >= 0; j--){
			for (int k = 11; k > j; k--){
				if (input[k][i] == '.' && input[j][i] != '.'){
					input[k][i] = input[j][i];
					input[j][i] = '.';
				}
				if (res[k][i] == 0 && res[j][i] != 0){
					res[k][i] = res[j][i];
					res[j][i] = 0;
				}
			}
		}
	}
}

void print(){
	printf("\n");
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 6; j++){
			printf("%c ",input[i][j]);
		}
		printf("\n");
	}
}

void bfs(int x, int y,char c, int d){
	int cnt = 0;
	queue<point> Q;
	Q.push({x,y});
	while(!Q.empty()){
		point cur = Q.front();
		res[cur.x][cur.y] = d;
		cnt++;
		Q.pop();
		for (int i = 0; i < 4; i++){
			int tx = cur.x + dx[i];
			int ty = cur.y + dy[i];
			if (isin(tx,ty) && input[tx][ty] == c && res[tx][ty] == 0){
				Q.push({tx,ty});
			}
		}
	}	
	if (cnt >= 4){
		for (int i = 11; i >= 0; i--){
			for (int j = 0; j < 6; j++){
				if (res[i][j] == d){
					input[i][j] = '.';
					res[i][j] = 0;
				}
			}
		}
	}
	

}

void start(){
	int c = 0;
	for (int i = 11; i >= 0; i--){
		for (int j = 0; j < 6; j++){
			if (input[i][j] == 'R' && res[i][j] == 0){
				c++;
				bfs(i,j,'R',c);
			}
			if (input[i][j] == 'G' && res[i][j] == 0){
				c++;
				bfs(i,j,'G',c);
			}
			if (input[i][j] == 'B' && res[i][j] == 0){
				c++;
				bfs(i,j,'B',c);
			}
			if (input[i][j] == 'P' && res[i][j] == 0){
				c++;
				bfs(i,j,'P',c);
			}
			if (input[i][j] == 'Y' && res[i][j] == 0){
				c++;
				bfs(i,j,'Y',c);
			}
		}
	}
	print();
	gravity();
	printf("gravity done\n");
	print();
	for (int i = 11; i >= 0; i--){
		for (int j = 0; j < 6; j++){
			res[i][j] = 0;
		}
	}
}

int main(){
	for (int i = 0; i < 12; i++){
		scanf("%s",input[i]);
	}
	char tmp[12][6];
	
	while(!chk(tmp)){
		count++;
		for (int i = 0; i < 12; i++){
			for (int j = 0; j < 6; j++){
				tmp[i][j] = input[i][j];
			}
		}
		start();
	}
	
	printf("%d",count-1);
   	return 0;
}

