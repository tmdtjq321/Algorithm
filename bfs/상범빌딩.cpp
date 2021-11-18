#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
int L, R, C;
int dx[] = {1,-1,0,0,0,0}, dy[] = {0,0,1,-1,0,0}, dz[] = {0,0,0,0,1,-1};
int sx,sy,sz,ex,ey,ez;
int res;
char build[30][30][30];
int visit[30][30][30];

struct pt{
	int x,y,z;	
};

bool isin(int x, int y, int z){
	return x >= 0 && y >= 0 && z >= 0 && x < L && y < R && z < C;
}

void flush(){
	for (int i = 0; i < L; i++){
		for (int j = 0; j < R; j++){
			for (int k = 0; k < C; k++){
				build[i][j][k] = '\0';
				visit[i][j][k] = 0;
			}
		}
	}
}

void bfs(){
	queue<pt> Q;
	Q.push((pt){sx,sy,sz});
	while (!Q.empty()){
		pt cur = Q.front();
		int cx = cur.x;
		int cy = cur.y;
		int cz = cur.z;
		Q.pop();
		for (int i = 0; i < 6; i++){
			int tx = cx + dx[i];
			int ty = cy + dy[i];
			int tz = cz + dz[i];
			if (isin(tx,ty,tz) && visit[tx][ty][tz] == 0 && build[tx][ty][tz] != '#'){
				visit[tx][ty][tz] = visit[cx][cy][cz] + 1;
				Q.push((pt){tx,ty,tz});
				if (tx == ex && ty == ey && tz == ez){
					res = visit[tx][ty][tz];
					return;
				} 
			}
			
		}
	}
	
}

int main(){
	while(1){
		scanf("%d%d%d",&L,&R,&C);
		if (L == 0 && R == 0 && C == 0){
			break;
		}	
		
		for (int i = 0; i < L; i++){
			for (int j = 0; j < R; j++){
				scanf("%s",build[i][j]);
			}
		}
		
		for (int i = 0; i < L; i++){
			for (int j = 0; j < R; j++){
				for (int k = 0; k < C; k++){
					if (build[i][j][k] == 'S'){
						sx = i;
						sy = j;
						sz = k;
					}
					if (build[i][j][k] == 'E'){
						ex = i;
						ey = j;
						ez = k;
					}
				}
			}
		}
		
		bfs();
		
		if (res != 0){
			printf("Escaped in %d minute(s).\n",res);
		}
		else{
			printf("Trapped!\n");
		}
		flush();
		res = 0;
	}
	
    return 0;
}
