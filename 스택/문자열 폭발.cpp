#include<stdio.h>
#include<algorithm>
#include<stack> 
#include<string.h>
using namespace std;
int N, l, lb;
char input[1000005];
char boom[40];

stack<char> st;
stack<char> buf;

int main(){
	scanf("%s",input);
	scanf("%s",boom);
	l = strlen(input);
	lb = strlen(boom);

	for (int i = 0; i < l; i++){ 
		st.push(input[i]);
		if (st.top() == boom[lb-1]){	// 폭탄 문자열로 의심되면 
			int flag = 0;
			if (st.size() < lb){
				continue;
			}
			for (int i = 0; i < lb; i++){	// 잠시 buf스택에 넣고 
				if (st.top() != boom[lb-1-i]){
					flag = 1;
					break;
				}
				else{
					buf.push(st.top());
					st.pop();
				}
			}
			if (flag == 0){		// 폭탄이면 pop 
				while(!buf.empty()){
					buf.pop();
				}
			}
			else{	// 아니면 
				while (!buf.empty()){
					st.push(buf.top());
					buf.pop();
				}
			}
		}
	}
	
	if (st.empty()){
		printf("FRULA");
	}
	else{
		int len = st.size();
		int c = len;
		while(!st.empty()){
			input[len-1] = st.top();
			len--;
			st.pop();
		}
		for (int i = 0; i < c; i++){
			printf("%c",input[i]);
		}
	}
	
    return 0;
}


