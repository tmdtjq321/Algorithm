#include<stdio.h>
#include<queue>
using namespace std;
int N;
struct num{
	int x,y;
	bool operator<(const num& A)const{
		if (x == A.x){
			return y>A.y;
		}
		else{
			return x>A.x;
		}
	}
};
priority_queue<num> min_pq; // √÷º“ 

int main() {
	scanf("%d",&N); 
	for (int i = 0; i < N; i++){
		int t;
		struct num Num;
		scanf("%d",&t);
		if (t == 0){
			if (min_pq.size() == 0){
				printf("0\n");
				continue;
			}
			int res = min_pq.top().x * min_pq.top().y;
			printf("%d\n",res);
			min_pq.pop();	
		}
		else{
			if (t < 0){
				Num.x = -t;
				Num.y = -1;
				min_pq.push(Num);
			}
			else{
				Num.x = t;
				Num.y = 1;
				min_pq.push(Num);
			}
		}
	}
	return 0;
}
