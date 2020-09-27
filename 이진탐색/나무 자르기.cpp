#include <stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int num[1000005];

int main(){
	int n, m;
  	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%d", &num[i]);
	}
	std::sort(num,num+n);
  	ll s = 0;
	ll e = 1000000000;
	ll sum = 0;
	while(s <= e){
		sum = 0;
		ll mid = (s + e) / 2;
		for (int i = 0; i < n; i++){
			if (num[i] > mid){
				sum += num[i] - mid;
			}
		}
		if (sum == m){
			printf("%lld", mid);
			break;
		}
		else if (sum > m){
			if (s == mid){
				printf("%lld", mid);
				break;
			}
			s = mid;
		}
		else{
			if (e == mid){
				printf("%lld", mid);
				break;
			}
			e = mid;
		}
	} 
   	return 0;
}

