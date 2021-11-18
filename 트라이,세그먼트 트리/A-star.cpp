#include <iostream>
#include <queue>
#include <functional>
#define INF 1987654321
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ii start = {1, 1};
ii goal = {5, 5};

int h(ii now) {
    return 2 * (abs(now.first - goal.first) + abs(now.second - goal.second));
}

int g[10][20];
bool input[10][20];

int main() {
    for (int i = 0; i < 10; ++i) for (int j = 0; j < 20; ++j) g[i][j] = 15;
    input[1][2] = true;
    input[2][2] = true;
    input[2][1] = true;
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push({h(start), start});	// ������������ �Ÿ�, ��ǥ 
    g[start.first][start.second] = 0;
    for (int i = 0; i < 10; i++){
    	for (int j = 0; j < 10; j++){
    		if (input[i][j]){
    			printf("x ");
			}
			else{
				printf("o ");
			}
		}
		printf("\n");
	}
	printf("\n");
	
    while (!pq.empty()) {
        iii poped = pq.top(); pq.pop();
        int f = poped.first;	// ���ݱ��� �ּ��� ���������� �Ÿ� 
        ii now = poped.second;	// ���� ��ǥ 
        if (now == goal) break; 
        int nowg = f - h(now);	// ���� ��ġ���� �̵��Ÿ� 
        if (nowg > g[now.first][now.second]) continue;	// ���� ��ǥ�� �����ϴ� ����� �̹� ������ ��뺸�� ū��� 
        nowg++;
        for (int k = 0; k < 4; ++k) {
            int nextx = now.first + loc[k][0];
            int nexty = now.second + loc[k][1];
            if (nextx < 0 || nextx >= 10 || nexty < 0 || nexty >= 20) continue;
            if (nowg < g[nextx][nexty] && !input[nextx][nexty]) {
            	printf("%d %d %d\n",nextx,nexty,nowg); 
                g[nextx][nexty] = nowg;
                pq.push({nowg + h({nextx, nexty}), {nextx, nexty}});
            }
        }
    }
    for (int i = 0; i < 10; i++){
    	for (int j = 0; j < 10; j++){
    		printf("%d ",g[i][j]);
		}
		printf("\n");
	}
	printf("\n");
    cout << g[goal.first][goal.second] << '\n';
}
