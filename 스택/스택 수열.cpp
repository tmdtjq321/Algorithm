#include<stdio.h>
#include<stack> 
using namespace std;
int N, start = 1, g, cnt, ncnt;
int input[100005]; 
char res[200005];
stack<int> st;


int main(){
	scanf("%d",&N);
	for (int i = 0; i < N; i++){
		scanf("%d",&input[i]);
	}
	st.push(0); 
	while(!st.empty()){		
		if (st.top() > input[ncnt]){	// 출력할 때 top보다 작으면 실패 
			printf("NO");
			break;
		}
		else if (st.top() < input[ncnt]){
			for (int i = cnt + 1; i <= input[ncnt]; i++){
				st.push(i);
				res[start] = '+';
				start++;
				cnt++;
			}
			st.pop();
			res[start] = '-';
			start++;
		}
		else{
			st.pop();
			res[start] = '-';
			start++;			
		}
		ncnt++;
		if (ncnt == N){
			for (int i = 1; i <= 2* N; i++){
				printf("%c\n",res[i]);
			}
			break;
		}
	}
	
    return 0;
}
