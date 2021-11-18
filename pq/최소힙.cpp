#include<stdio.h>
#include<queue>
using namespace std;
int N;
//priority_queue<int, vector<int>, greater<int> > mpq;
priority_queue<int> pq;

int main() {
	scanf("%d",&N);
	for (int i = 0; i < N; i++){
		int t;
		scanf("%d",&t);
		if (t != 0){
			pq.push(-t);
		}
		else{
			if (pq.empty()){
				printf("0\n");
			}
			else{
				printf("%d\n",-pq.top());
				pq.pop();
			}
		}
	}
			
	return 0;
}
