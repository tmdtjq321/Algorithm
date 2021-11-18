#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int N, cnt;
int in[1002];
int buf[1002];

int main(){
	scanf("%d",&N);
	for (int i = 0; i < N; i++){
		scanf("%d",&in[i]);
	} 
	for (int i = 0; i < N; i++){
		int h;
		scanf("%d",&h);
		buf[i] = h - in[i];
	} 
	if (N == 1){
		printf("%d\n",abs(buf[0]));
	}
	else{
		int pre = buf[0];
		for (int i = 1; i < N; i++){
			if (buf[i] >= 0){
				if (pre < 0){
					cnt += abs(pre);
					pre = buf[i];
				}
				else{
					if (buf[i] > pre){
						pre = buf[i];
					}
					else{
						cnt += abs(pre) - abs(buf[i]);
						pre = buf[i];
					}
				}
			}
			else{
				if (pre > 0){
					cnt += abs(pre);
					pre = buf[i];
				}
				else{
					if (buf[i] < pre){
						pre = buf[i];
					}
					else{
						cnt += abs(pre) - abs(buf[i]);
						pre = buf[i];
					}
				}
			}	
		}
		cnt += abs(pre);
		printf("%d\n",cnt);
	}
    return 0;
}

