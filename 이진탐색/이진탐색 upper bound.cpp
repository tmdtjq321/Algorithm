#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
   int N;
   scanf("%d",&N);
   int* num;
   int s = 0;
   int e = N;
   int cnt = 0;
   int find, mid;
   num = (int *)malloc(sizeof(int)*N);
   for (int i = 0; i < N; i++){
   		scanf("%d",&num[i]);
   }
   scanf("%d", &find);
   int limit;
   while(1){
   		cnt++;
   		if (pow(2,cnt) >= N){
   			limit = cnt;
   			break;
	   }
   }
   cnt = 0;
   int flag = 0;
   while(1){
   		if (find > num[N-1]){
   			printf("%d",N+1);
			break;	
		}
		else if (find < num[0]){
			printf("-1");
			break;	
		}
   		cnt++;
   		mid = (s + e) / 2;
   		if (find > num[mid]){
   			if (mid == s){
   				printf("%d",num[mid + 1]);
   				break;
			}	
			s = mid;
		}
   		else if (find < num[mid]){
			if (mid == e){
   				printf("%d",num[mid + 1]);
   				break;
			}	
   			e = mid;
		}
		else{
			for(int i = mid; i < N; i++){
				if (find < num[i]){
					printf("%d",num[i]);
					flag = 1;
					break;
				}
			}
			break;
		}
   }
   return 0;
}

