#include<stdio.h>
#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
int N, res, input;
bool visit[10002];

void bfs(){
	queue<pair<int,string>> Q;
	Q.push({input,""});
	while(!Q.empty()){
		int cur = Q.front().first;
		string result = Q.front().second;
		Q.pop();
		if (cur == res){
			cout << result << endl;
			return;
		}
		int s = (cur * 2) % 10000;
		if (!visit[s]){
			visit[s] = true;
			Q.push({s,result+'D'});
		}
		if (cur - 1 < 0){
			s = 9999;
		}
		else{
			s = cur - 1;
		}
		if (!visit[s]){
			visit[s] = true;
			Q.push({s,result+'S'});
		}
		int tmp = cur;
		int last = tmp / 1000;
		tmp = (tmp * 10 + last) % 10000;
		if (!visit[tmp]){
			visit[tmp] = true;
			Q.push({tmp,result+'L'});
		}
		tmp = cur;
		last = (tmp % 10) * 1000;
		tmp /= 10;
		tmp += last;
		if (!visit[tmp]){
			visit[tmp] = true;
			Q.push({tmp,result+'R'});
		}
	}
}

int main(){
	scanf("%d",&N);
	while(N--){
		memset(visit,false,sizeof(visit));
		scanf("%d%d",&input,&res);
		bfs();
	}

	return 0;
}
