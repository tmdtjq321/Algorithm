#include <stdio.h>
#include <math.h>
using namespace std;
int N, cnt, rcnt, l, r, sum;
int num[4000005];
int res[290000];

int main() {
	scanf("%d",&N);
	for (int i = 2; i*i <= N; i++){
		if (num[i] == 0){
			for (int j = 2; j <= N / i; j++){
				if (j*i <= N){
					num[j*i] = 1;
				}
			}
		}
	}
	
	for (int i = 2; i <= N; i++){
		if (num[i] == 0){
			res[rcnt] = i;
			rcnt++;
		}
	}
	sum = res[l];
	while (true){
		if (r >= rcnt){
			break;
		}
		else if (sum > N){
			sum -= res[l];
			l++;
		}
		else if (sum < N){
			r++;
			sum += res[r];
		}
		else if (sum == N){
			cnt++;
			r++;
			sum += res[r];
		}
	}
	
	printf("%d",cnt);
	
	return 0;
}

//2 3 5 7 11 13 17 19 23 29 31 37 41

