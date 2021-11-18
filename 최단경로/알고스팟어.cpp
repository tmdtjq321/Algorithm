#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char input[102][12];
int set[27], edge[27][27], par[27];
char ans[27];
int N, flag = 0, sum = 0;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
    	scanf("%s",input[i]);
    	for (int j = 0; j < strlen(input[i]); j++){
    		set[input[i][j] - 'a'] = 1;	// 사용하는 문자 
		}
	}
	for (int i = 0; i < 26; i++){
		sum += set[i];
	}
	
	for (int i = 0; i < N; i++){
		for (int j = i+1; j < N; j++){
			for (int k = 0; k < strlen(input[i]); k++){
				if (k >= strlen(input[j])){	// 단어 두 개를 비교할 때 i 단어는 무조건 짧아야함 
					flag = -1;
					break;
				}
				int fl = (int)(input[i][k] - 'a');
				int sl = (int)(input[j][k] - 'a');
				if (fl == sl){	// 같은 문자면 
					continue;
				}
				if (edge[fl][sl] == 0){	  // 문자 fl은 sl보다 앞에 있다. fl->sl 
					edge[fl][sl] = 1;
					par[sl]++;	// sl을 가리키는 노드의 개수 
					if (edge[sl][fl] == 1){	// 양방향이면 오류 
						flag = -1;
					}
				}
				break;	// 간선이 이루어지면 다음 단어 비교			 
			}
		}
	}

	if (flag != -1) {	// 루트노드를 찾자... 
		int root = 0, cnt = 0, count = 0;
		for (int m = 0; m < sum; m++){
			root = 0, cnt = 0;
			for (int i = 0; i < 26; i++){
				if (set[i] == 1 && par[i] == 0){
					root = i;
					cnt++;
				}
			}
			if (cnt > 1){	// 루트가 여러개면 
				flag = 0;
				break;
			}
			if (cnt == 0){	// 사이클이 존재하면 
				flag = -1;
				break;
			}
			flag = 1;
			ans[count] = (char)(root + 'a');
			count++;
			set[root] = 0;
			for (int i = 0; i < 26; i++){
				if (edge[root][i] == 1){	// 루트 노드에서 나온 간선들을 제거 
					par[i]--;
				}
			}
		}
	}
	
	if (flag == -1){
		printf("!");
	}
	else if (flag == 0){
		printf("?");
	}
	else{
		for (int i = 0; i < strlen(ans); i++){
			printf("%c",ans[i]);
		}
	}
	
    return 0;
}
