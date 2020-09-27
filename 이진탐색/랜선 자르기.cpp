#include <stdio.h>
#include<algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
int num[10005];

int main(){
	int N, K;
	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; i++){
		scanf("%d",&num[i]);
	}
	std::sort(num,num+K);
	ll s = 0;
	ll e = pow(2,31) - 1;
	ll ans;
	while (s <= e){
		ll sum = 0;
		ll mid = (s + e) / 2;
		for (int i = 0; i < K; i++){
			if (num[i] >= mid){
				sum += num[i] / mid;
			}
		}
		if (sum >= N){
			ans = mid;
            s = mid + 1;
		}
		else if (sum < N){
			e = mid - 1;
		}
	}	
	
	printf("%lld",ans);
   	return 0;
}
