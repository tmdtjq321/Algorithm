#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct pt{
	int x,y;
}; 

int N, M, cnt;
bool can = false;
int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
char board[1502][1502];
bool visit[1502][1502];
vector<pt> swan;
queue<pt> ice;
queue<pt> Q;
queue<pt> NQ;

bool isin(int x, int y){
	return (x >= 0 && y >= 0 && x < N && y < M);
}

bool search(int z, int w){	// 백조의 이동 
	while(!Q.empty()){
		int nx = Q.front().x;
		int ny = Q.front().y;
		Q.pop();
		if (nx == z && ny == w){
			return true;
		}
		for (int i = 0; i < 4; i++){
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if (isin(tx,ty) && !visit[tx][ty]){
				visit[tx][ty] = true;
				if (board[tx][ty] == 'X'){
					NQ.push({tx,ty});
					continue;
				}
				Q.push({tx,ty});
			}
		}
	}
	return false;
}

int main(){
	scanf("%d%d",&N,&M);
	for (int i = 0; i < N; i++){
		scanf("%s",board[i]);
		for (int j = 0; j < M; j++){
			if (board[i][j] == 'L'){
				swan.push_back({i,j});
				ice.push({i,j});
				board[i][j] = '.';
			}
			else if (board[i][j] == '.'){
				ice.push({i,j});
			}
		}
	}
	Q.push({swan[0].x,swan[0].y});
	visit[swan[0].x][swan[0].y] = true;
	while(1){
		can = search(swan[1].x,swan[1].y);
		if (!can){
			cnt++;
			Q = NQ;
			int T = ice.size();
			while(T--){
				int nx = ice.front().x;
				int ny = ice.front().y;
				ice.pop();
				for (int i = 0; i < 4; i++){
					int tx = nx + dx[i];
					int ty = ny + dy[i];
					if (isin(tx,ty)){
						if (board[tx][ty] == 'X'){
							board[tx][ty] = '.';
							ice.push({tx,ty});
						}
					}
				}
			}
		}
		else{
			break;
		}
	}
	printf("%d\n",cnt);
	
	return 0;
}
