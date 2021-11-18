//#include <stdio.h>
//#include <algorithm>
//using namespace std;
//#define MN 105
//#define MV 10005
//struct Dy {
//    int x, fx;
//} p;
//int N, V, vi[MN], ci[MN], ki[MN], d[MV], fr, re;
//Dy dq[MV];
//int main() {
//    scanf("%d%d", &N, &V);
//    for (int i = 1; i <= N; i++) scanf("%d%d%d", &vi[i], &ci[i], &ki[i]);
//    for (int i = 1; i <= N; i++) {
//        for (int l = 0; l < vi[i]; l++) {
//            fr = 1, re = 0;
//            for (int j = l; j <= V; j += vi[i]) {	// j는 무게단위만큼씩 증가 
//                p.x = j;
//                p.fx = d[j] - j / vi[i] * ci[i];
//                while (fr <= re && dq[re].fx < p.fx) re--;
//                dq[++re] = p;
//                while (dq[fr].x < j - ki[i] * vi[i]) fr++;
//                d[j] = dq[fr].fx + j / vi[i] * ci[i];
//                printf("f %d %d\n",re,fr);
//                printf("%d %d %d %d\n",dq[re].x,dq[re].fx,j,d[j]);
//                printf("dp\n");
//                for (int o = 0; o <= V; o++){
//                	printf("%d ",d[o]);
//				}
//				printf("\n");
//				printf("dq\n");
//                for (int o = 0; o <= re; o++){
//                	printf("(%d %d) ",dq[o].x,dq[o].fx);
//				}
//				printf("\n");
//            }
//        }
//    }
//    printf("%d\n", d[V]);
//    return 0;
//}

#include <stdio.h>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
int N, M, limit, ans;
int board[52][52];
bool visit[52][52];
int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

inline int max(int a, int b){
	return a > b ? a : b;
}

bool isin(int x, int y){
	return x >= 0 && y >= 0 && x < N && y < M;
}

void bfs(int x, int y){
	queue<pair<int,int>> Q;
	Q.push({x,y});
	visit[x][y] = true;
	vector<pair<int,int>> V;
	V.push_back({x,y});
	int min_height = 10, height = board[x][y];
	bool chk = false;
	while(!Q.empty()){
		int cx = Q.front().first;
		int cy = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++){
			int tx = cx + dx[i];
			int ty = cy + dy[i];
			if (board[tx][ty] > height && board[tx][ty] < min_height){
				min_height = board[tx][ty];
			}
			if (!isin(tx,ty)){
				chk = true;
			}
			if (isin(tx,ty) && !visit[tx][ty] && board[tx][ty] == height){
				Q.push({tx,ty});
				V.push_back({tx,ty});
				visit[tx][ty] = true;	
			}
		}
	}
	
	if (!chk){
		for (int i = 0; i < V.size(); i++){
			int nx = V[i].first, ny = V[i].second;
			ans += min_height - board[nx][ny];
			board[nx][ny] = min_height;
		}
	}
	else{
		for (int i = 0; i < V.size(); i++){
			int nx = V[i].first, ny = V[i].second;
			board[nx][ny] = min_height;
		}
	}
}

int main(){
	scanf("%d%d",&N,&M);
	for (int i = 0; i < N; i++){
		char input[52];
		scanf("%s",input);
		for (int j = 0; j < M; j++){
			board[i][j] = input[j] - '0';
			limit = max(limit,board[i][j]);
		}
	}
	for (int k = 1; k <= limit; k++){
		memset(visit,false,sizeof(visit));
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				if (board[i][j] == k && !visit[i][j]){
					bfs(i,j);
				}
			}
		}
	}
	
	printf("%d\n",ans);
	return 0;
}




