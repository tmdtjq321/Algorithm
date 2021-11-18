#include<stdio.h>
#include<string.h>
#include<vector>
#define INF 987654321
using namespace std;
int N, M, G, D;
int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

struct pt{
	int sx,sy,ex,ey, w, v;
	pt(){}
	pt(int _sx, int _sy, int _ex, int _ey, int _w, int _v){
		sx = _sx;
		sy = _sy;
		ex = _ex;
		ey = _ey;
		w = _w;
		v = _v;
	}
};

pt graves[32][32];
vector<pt> edge;
int dist[32][32];

int main(){
	while(1){
		edge.clear();
		scanf("%d%d",&M,&N);
		if (N == 0 && M == 0){
			break;
		}
        for (int i = 0; i < N; i++){
        	for (int j = 0; j < M; j++){
        		graves[i][j] = pt(0,0,0,0,0,0);
			}
		}
		scanf("%d",&G);
		for (int i = 0; i < G; i++){
			int x, y;
			scanf("%d%d",&x,&y);
			graves[y][x].v = -1;
		}
		scanf("%d",&D);
		int x1, y1, x2, y2, t;
		for (int i = 0; i < D; i++){
			scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&t);
			graves[y1][x1] = pt(y1,x1,y2,x2,t,1);
		}
		
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				dist[i][j] = INF;
				if (graves[i][j].v == 0){
					if (i == N-1 && j == M-1){
						continue;
					}
					for (int k = 0; k < 4; k++){
						int tx = i + dx[k];
						int ty = j + dy[k];
						if (tx < 0 || ty <  0 || tx >= N || ty >= M || graves[tx][ty].v == -1){
							continue;
						}
						edge.push_back(pt(i,j,tx,ty,1,0));
					}
				}
				else if (graves[i][j].v == -1){
					continue;
				}
				else{
					edge.push_back(graves[i][j]);
				}
			}
		}
		
		dist[0][0] = 0;
		for (int i = 0; i < N*M; i++){
			bool cycle = false;
			for (int j = 0; j < edge.size(); j++){
				int nx = edge[j].sx, ny = edge[j].sy, ax = edge[j].ex, ay = edge[j].ey;
				int val = edge[j].w;
				if (dist[nx][ny] == INF){
					continue;
				}
				if (dist[ax][ay] > dist[nx][ny] + val){
					dist[ax][ay] = dist[nx][ny] + val;
					cycle = true;
				}	
			}
			if (i == N*M-1){
				if (cycle){
					printf("Never\n");
				}
				else if (dist[N-1][M-1] == INF){
					printf("Impossible\n");
				}
				else{
					printf("%d\n",dist[N-1][M-1]);
				}
			}
		}
	}
	return 0;
}
