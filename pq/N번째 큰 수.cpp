#include<stdio.h>
#include<queue>
using namespace std;
int input[1505][1505];
int N;
priority_queue<int, vector<int>, greater<int> > min_pq; // √÷º“ 

int main() {
	scanf("%d",&N); 
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%d",&input[i][j]);
			if (i == N-1){
				min_pq.push(input[i][j]);
			}
		}
	}
	
	for (int i = N-2; i >= 0; i--){
		for (int j = N-1; j >= 0; j--){
			if (min_pq.size() == N){
				if (min_pq.top() < input[i][j]){
					min_pq.pop();
					min_pq.push(input[i][j]);
				}
			}
		}
	}
	printf("%d\n",min_pq.top());
	return 0;
}
