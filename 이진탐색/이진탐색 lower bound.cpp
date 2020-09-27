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
   		cnt++;
   		mid = (s + e) / 2;
   		if (cnt > limit){
   			printf("%d", N + 1);
   			break;
		}
		else{
			if (find <= num[mid]){
				for (int i = mid - 1; i >= 0; i--){
					if (find > num[i]){
						flag = 1;
						printf("%d",i + 2);
						break;
					}
					flag = 0;
				}
				if (flag == 0){	// for문을 통과할 때  
					printf("1");
				}
	   			break;
			}
   			else{
   				s = mid;	
			}
		}
   		
   }
}

