#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
struct pokemon{
	int index;
	char name[20];
};

char input[100005][20];
char p_input[100005][20];
int main(){
	int N, M;
	int s = 0;
	int e = N;
	scanf("%d%d",&N, &M);
	struct pokemon po[10001];
	for (int i = 0; i < N; i++){
		scanf("%s", po[i].name);
		po[i].index = i + 1;
	}
	for (int i = 0; i < M; i++){
		scanf("%s",p_input[i]);
	}
	
	for (int i = 0; i < M; i++){
		if (isdigit(p_input[i][0])){
			int t = 1;
			int index = 0;
			for (int j = strlen(p_input[i]) - 1; j >= 0; j--, t *= 10){
				index += (p_input[i][j] - '0') * t;
			}
			index--;
			printf("%s\n",po[index].name);
		}
		else{
			sort
//			int point = 0;
//			while(s<=e){
//				int mid = (s + e) / 2;
//				if (strcmp(input[mid], p_input[i]) == 0){
//					printf("%d\n", mid+1);
//					break;
//				}
//				else if (mid < point){
//					s = mid + 1;
//				}
//				else{
//					e = mid - 1;
//				}
//			}
		}
	}
   	return 0;
}
