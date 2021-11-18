#include<stdio.h>
#include<algorithm>
#include<stack> 
#include<string.h>
using namespace std;
int N, cnt;
char input[1000005];
char output[1000005];
stack<char> st;
stack<char> buf;

// - 백스페이스,  <,> 커서 이동,  
int main(){
	scanf("%d",&N);
		
	while(N--){
		scanf("%s",input);
		int line = strlen(input);

		for (int i = 0; i < line; i++){ 
			if (input[i] == '<'){
				if (!st.empty()){
					buf.push(st.top());
					st.pop();
				}
			}
			else if (input[i] == '>'){
				if (!buf.empty()){
					st.push(buf.top());
					buf.pop();
				}
			}
			else if (input[i] == '-'){
				if (!st.empty()){
					st.pop();
				}
			}
			else{
				st.push(input[i]);
			}
		}
		while(!buf.empty()){
			st.push(buf.top());
			buf.pop();
		}
		cnt = st.size();
		int t = cnt;
		while(!st.empty()){
			cnt--;
			output[cnt] = st.top(); 
			st.pop();
		}

		for (int i = 0; i < t; i++){
			printf("%c",output[i]);
		}
	}
	
    return 0;
}

