#include<stdio.h>
#include<deque>
#include<string.h>
using namespace std;
int N, p, sum;
char input[100005];
char num[300005];

int main() {
	scanf("%d",&N);
	
	while(N--){
		scanf("%s",input);
		scanf("%d",&p);
		scanf("%s",num);
		deque<int> de;
		int len = strlen(num);
		int t = 1;
		if (p == 0){	// 빈 배열일 떄 
			int l = strlen(input);
			int f = 0;
			for (int i = 0; i < l; i++){
				if (input[i] == 'D'){
					f = 1;
					printf("error\n");
					break;
				}
			}
			if (f != 1){
				printf("[]\n");
			}
			continue;
		}
		for (int i = len-2; i >= 0; i--){
			if (num[i] >= 48 && num[i] <= 57){
				sum += t * (num[i] - '0');
				t *= 10;
			}
			else if (num[i] == ','){
				de.push_front(sum);
				t = 1;
				sum = 0;
			}
			else if (num[i] == '['){
				de.push_front(sum);
				t = 1;
				sum = 0;
			}
		}
		len = strlen(input);
		int dir = 0;	// 방향 
		int err = 0;	// 오류 
		int cnt = 0; 
		for (int i = 0; i < len; i++){
			if (input[i] == 'R'){
				if (dir == 0){
					dir = 1;
				}
				else{
					dir = 0;
				}
			}
			else if (input[i] == 'D'){
				if (dir == 0){
					if (de.empty()){
						err = 1;
						printf("error\n");
						break;
					}
					de.pop_front();
				}
				else{
					if (de.empty()){
						err = 1;
						printf("error\n");
						break;
					}
					de.pop_back();
				}
			}
		}
		len = de.size();
		cnt = 0; 
		if (err != 1){
			if (dir == 0){
				printf("[");
				while(!de.empty()){
					cnt++;
					if (cnt == len){
						printf("%d",de.front());
						de.pop_front();
					}
					else{
						printf("%d,",de.front());
						de.pop_front();
					}
				}
				printf("]\n");
			}
			else{
				printf("[");
				while(!de.empty()){
					cnt++;
					if (cnt == len){
						printf("%d",de.back());
						de.pop_back();
					}
					else{
						printf("%d,",de.back());
						de.pop_back();
					}
				}
				printf("]\n");
			}
		}
	}
	
	return 0;
}

