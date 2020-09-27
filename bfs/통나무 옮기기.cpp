#include<stdio.h>
#include<queue>
using namespace std;
int N;
char input[53][53];
int visit[53][53][2];
int cnt_s = 0;
int cnt_e = 0;
int cnt = 0;
int sx, sy, ex, ey; 
int dx_r_l[] = {0,-1,1}, dy_r_l[] ={-1,-1,-1};	//세로(1) 
int dx_r_r[] = {0,-1,1}, dy_r_r[] ={1,1,1};
int dx_r_roll[] = {0,0,-1,-1,1,1}, dy_r_roll[] = {1,-1,1,-1,1,-1};
int dx_c_u[] = {-1,-1,-1}, dy_c_u[] ={0,1,-1};	//가로(0) 
int dx_c_d[] = {1,1,1}, dy_c_d[] ={0,1,-1};
int dx_c_roll[] = {1,-1,1,-1,1,-1}, dy_c_roll[] = {0,0,-1,-1,1,1};

struct point{
	int x,y;
	int type;
};

point o;		// 시작 중심점 type = 1이면 o.x +- 1 o.y는 같다. 
point o_e;		// 도착 중심점 type = 0이면 o.y +- 1 o.x는 같다. 
queue<point> Q;

bool isin(int x, int y){
	return x >= 0 && y >= 0 && x < N && y < N;
}

void bfs(int sx, int sy, int stype){
	Q.push({sx,sy,stype});
	visit[sx][sy][stype] = 1;
	while(!Q.empty()){
		int x = Q.front().x;
		int y = Q.front().y;
		int type = Q.front().type;
		Q.pop();
		if (type == 1){
			int flag_l = 0;
			int flag_r = 0;
			int flag_u = 0;
			int flag_d = 0;
			int flag_roll = 0;
			if (visit[x][y-1][1] == 0 && isin(x,y-1)){
				for (int i = 0; i < 3; i++){	// l
					int tx = x + dx_r_l[i];
					int ty = y + dy_r_l[i];
					if (!isin(tx,ty) || input[tx][ty] != '0'){
						flag_l = 1;
						break;	
					}
				}
				if (flag_l == 0){
					visit[x][y-1][1] = visit[x][y][1] + 1;							
					Q.push({x,y-1,type});
				}
			}
			if (visit[x][y+1][1] == 0 && isin(x,y+1)){
				for (int i = 0; i < 3; i++){	// R
					int tx = x + dx_r_r[i];
					int ty = y + dy_r_r[i];
					if (!isin(tx,ty) || input[tx][ty] != '0'){
						flag_r = 1;
						break;	
					}
				}
				if (flag_r == 0){
					visit[x][y+1][1] = visit[x][y][1] + 1;			
					Q.push({x,y+1,type});
				}
			}
			if (visit[x-1][y][1] == 0 && isin(x-1,y)){
				if (!isin(x-2,y) || input[x-2][y] != '0'){	// U
					flag_u = 1;
				}
				if (flag_u == 0){
					visit[x-1][y][1] = visit[x][y][1] + 1;
					Q.push({x-1,y,type});
				}
			}
			if (visit[x+1][y][1] == 0 && isin(x+1,y)){
				if (!isin(x + 2,y) || input[x+2][y] != '0'){	// D
					flag_d = 1;
				}
				if (flag_d == 0){
					visit[x+1][y][1] = visit[x][y][1] + 1;	
					Q.push({x+1,y,type});
				}
			}
			if (visit[x][y][0] == 0 && isin(x,y)){
				for (int i = 0; i < 6; i++){	// Rotate r에서 c로 세로에서 가로 
					int tx = x + dx_r_roll[i];
					int ty = y + dy_r_roll[i];
					if (!isin(tx,ty) || input[tx][ty] != '0'){
						flag_roll = 1;
						break;	
					}
				}
				if (flag_roll == 0){	
					visit[x][y][0] = visit[x][y][1] + 1;			
					type = 0;
					Q.push({x,y,type});
				}
			}
		}
		else if (type == 0){
			int flag_1 = 0;
			int flag_r = 0;
			int flag_u = 0;
			int flag_d = 0;
			int flag_roll = 0;
			if (visit[x][y-1][0] == 0 && isin(x,y-1)){
				if (!isin(x,y-2) || input[x][y-2] != '0'){	// L
					flag_1 = 1;
				}
				if (flag_1 == 0){
					visit[x][y-1][0] = visit[x][y][0] + 1;
					Q.push({x,y-1,type});
				}
			}
			if (visit[x][y+1][0] == 0 && isin(x,y+1)){
				if (!isin(x,y+2) || input[x][y+2] != '0'){	// R
					flag_r = 1;
				}
				if (flag_r == 0){
					visit[x][y+1][0] = visit[x][y][0] + 1;				
					Q.push({x,y+1,type});
				}
			}
			if (visit[x-1][y][0] == 0 && isin(x-1,y)){
				for (int i = 0; i < 3; i++){	// U
					int tx = x + dx_c_u[i];
					int ty = y + dy_c_u[i];
					if (!isin(tx,ty) || input[tx][ty] != '0'){
						flag_u = 1;
						break;	
					}
				}
				if (flag_u == 0){
					visit[x-1][y][0] = visit[x][y][0] + 1;	
					Q.push({x-1,y,type});
				}
			}
			if (visit[x+1][y][0] == 0 && isin(x+1,y)){
				for (int i = 0; i < 3; i++){	// D
					int tx = x + dx_c_d[i];
					int ty = y + dy_c_d[i];
					if (!isin(tx,ty) || input[tx][ty] != '0'){
						flag_d = 1;
						break;	
					}
				}
				if (flag_d == 0){
					visit[x+1][y][0] = visit[x][y][0] + 1;		
					Q.push({x+1,y,type});
				}
			}
			if (visit[x][y][1] == 0 && isin(x,y)){
				for (int i = 0; i < 6; i++){	// Rotate c에서 r로 가로에서 세로 
					int tx = x + dx_c_roll[i];
					int ty = y + dy_c_roll[i];
					if (!isin(tx,ty) || input[tx][ty] != '0'){
						flag_roll = 1;
						break;	
					}
				}
				if (flag_roll == 0){	
					visit[x][y][1] = visit[x][y][0] + 1;
					type = 1;
					Q.push({x,y,type});
				}
			}
		
		}
	}
}


int main(){
	scanf("%d",&N);
	o.type = 0;
	o_e.type = 0;

	for (int i = 0; i < N; i++){
		scanf("%s",input[i]);
		for (int j = 0; j < N; j++){
			if (input[i][j] == '1'){
				visit[i][j][0] = -1;
				visit[i][j][1] = -1;
			}
			if (input[i][j] == 'B'){
				input[i][j] = '0';
				cnt_s++;
				if (cnt_s == 2){	// 중심점의 좌표 
					o.x = i;
					o.y = j;
				}
				sx = i;
				sy = j;
			}
			if (input[i][j] == 'E'){
				input[i][j] = '0';
				cnt_e++;
				if (cnt_e == 2){	// 도착 중심점의 좌표 
					o_e.x = i;
					o_e.y = j;
				}
				ex = i;
				ey = j;
				
			}
		}
	}
	if (sy == o.y){		// 통나무가 세로(1)인지 가로(0)인지 
		o.type = 1;
	}
	if (ey == o_e.y){		// 도착지점이  세로인지 가로인지 
		o_e.type = 1;
	}
	visit[o.x][o.y][o.type] = 1;
	bfs(o.x,o.y,o.type);
	if (visit[o_e.x][o_e.y][o_e.type] == 0){
		printf("%d",visit[o_e.x][o_e.y][o_e.type]);
	}
	else{
		printf("%d",visit[o_e.x][o_e.y][o_e.type]-1);
	}
		
   	return 0;
}
