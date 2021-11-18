#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M, D;

bool isin(int x, int y){
	return x >= 0 && y >= 0 && x < N && y < N;
}

bool game[102][102];
bool apple[102][102];
vector<pair<int,char>> V;

int main(){
	scanf("%d",&N);
	scanf("%d",&M);
	for (int i = 0; i < M; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		apple[x-1][y-1] = true;
	}
	
	scanf("%d",&D);
	for (int i = 0; i < D; i++){
		int a;
		char b;
		scanf("%d %c",&a,&b);
		V.push_back({a,b});
	}
	int time = 0, cnt = 0;
	char st = 'R';
	deque<pair<int,int>> Q;
	Q.push_back({0,0});
	game[0][0] = true;
	
	while(1){
		time++;
		int tx = Q.front().first;
		int ty = Q.front().second;
		if (st == 'R'){
			ty += 1;
		}
		else if (st == 'L'){
			ty -= 1;
		}
		else if (st == 'D'){
			tx += 1;
		}
		else if (st == 'U'){
			tx -= 1;
		}
		
		if (!isin(tx,ty) || game[tx][ty]){
			break;
		}
		else{	
			if (apple[tx][ty]){
				game[tx][ty] = true;
				apple[tx][ty] = false;
				Q.push_front({tx,ty});
			}
			else {
				game[Q.back().first][Q.back().second] = false;
				game[tx][ty] = true;
				Q.push_front({tx,ty});
				Q.pop_back();
			}
		}		
		
		if (cnt < D && V[cnt].first == time){
			if (st == 'R'){
				if (V[cnt].second == 'D'){
					st = 'D';
				}
				else{
					st = 'U';
				}
			}
			else if (st == 'L'){
				if (V[cnt].second == 'D'){
					st = 'U';
				}
				else{
					st = 'D';
				}
				
			}
			else if (st == 'D'){
				if (V[cnt].second == 'D'){
					st = 'L';
				}
				else{
					st = 'R';
				}
				
			}
			else if (st == 'U'){
				if (V[cnt].second == 'D'){
					st = 'R';
				}
				else{
					st = 'L';
				}
				
			}
			cnt++;
		}
	}
	printf("%d\n",time);
	
	

	return 0;
}
