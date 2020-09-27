#include <stdio.h>
#include<algorithm>
using namespace std;
int num[10005];

int main(){
	int N, M;
	int sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d",&num[i]);
		sum += num[i];
	}
	std::sort(num,num+N);
	scanf("%d",&M);
	
	if (sum <= M){
		printf("%d",num[N-1]);
	}
	else{
		int s = 0;
		int e = num[N-1];
		int cal_sum = 0;
		int ans = 0;
		while(s <= e){
			int mid = (s + e) / 2;
			cal_sum = 0;
			for (int i = 0; i < N; i++){
				if (num[i] <= mid){
					cal_sum += num[i];
				}
				else{
					cal_sum += mid;
				}
			}
			if (cal_sum <= M){
				if (ans < mid){
					ans = mid;
				}
				s = mid + 1;
			}
			else{
				e = mid - 1;
			}
		}
		printf("%d",ans); 
	}
	
	return 0;
}
