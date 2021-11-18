#include <stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
pair<int,int> th[100005];
int knot[100005];
int N, mid;
int s = 1,e = 1000000000;

bool search(int x){
	for (int i = 0; i < N - 1; i++){
		if (knot[i+1] - knot[i] < x){	// 매듭사이의 거리가 x보다 가까울 떄 
			int sum = knot[i] + x;
			if (sum < th[i+1].first || sum > th[i+1].second){
				printf("sum %d %d\n",sum,th[i+1].first);
				for (int i = 0; i < N; i++){
					knot[i] = th[i].first;
				}
				return false;
			}
			else{
				knot[i+1] = sum;
			}
		}
		
	}
	for (int i = 0; i < N; i++){
		knot[i] = th[i].first;
	}
	return true;
}


int main(){ 
    scanf("%d",&N);
    for (int i = 0; i < N; i++){
    	int x, y;
    	scanf("%d%d",&x,&y);
    	th[i].first = x;
    	th[i].second = x + y;
    	knot[i] = x;
	}
	sort(th,th+N);
	sort(knot,knot+N);
	
	while(s <= e){
		mid = (s+e) / 2;
		printf("%d\n",mid);
		if (search(mid)){
			if (s == mid){
//				printf("%d",mid);
				break;
			}
			s = mid;
		}
		else{
			if (e == mid){
//				printf("%d",mid);
				break;
			}
			e = mid;
		}
	}

    return 0;
}
