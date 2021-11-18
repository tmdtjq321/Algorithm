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
    		set[input[i][j] - 'a'] = 1;	// ����ϴ� ���� 
		}
	}
	for (int i = 0; i < 26; i++){
		sum += set[i];
	}
	
	for (int i = 0; i < N; i++){
		for (int j = i+1; j < N; j++){
			for (int k = 0; k < strlen(input[i]); k++){
				if (k >= strlen(input[j])){	// �ܾ� �� ���� ���� �� i �ܾ�� ������ ª�ƾ��� 
					flag = -1;
					break;
				}
				int fl = (int)(input[i][k] - 'a');
				int sl = (int)(input[j][k] - 'a');
				if (fl == sl){	// ���� ���ڸ� 
					continue;
				}
				if (edge[fl][sl] == 0){	  // ���� fl�� sl���� �տ� �ִ�. fl->sl 
					edge[fl][sl] = 1;
					par[sl]++;	// sl�� ����Ű�� ����� ���� 
					if (edge[sl][fl] == 1){	// ������̸� ���� 
						flag = -1;
					}
				}
				break;	// ������ �̷������ ���� �ܾ� ��			 
			}
		}
	}

	if (flag != -1) {	// ��Ʈ��带 ã��... 
		int root = 0, cnt = 0, count = 0;
		for (int m = 0; m < sum; m++){
			root = 0, cnt = 0;
			for (int i = 0; i < 26; i++){
				if (set[i] == 1 && par[i] == 0){
					root = i;
					cnt++;
				}
			}
			if (cnt > 1){	// ��Ʈ�� �������� 
				flag = 0;
				break;
			}
			if (cnt == 0){	// ����Ŭ�� �����ϸ� 
				flag = -1;
				break;
			}
			flag = 1;
			ans[count] = (char)(root + 'a');
			count++;
			set[root] = 0;
			for (int i = 0; i < 26; i++){
				if (edge[root][i] == 1){	// ��Ʈ ��忡�� ���� �������� ���� 
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
