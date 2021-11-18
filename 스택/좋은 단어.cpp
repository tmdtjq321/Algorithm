#include<stdio.h>
#include<algorithm>
#include<stack> 
#include<string.h>
using namespace std;
int N, cnt;
char input[100005];

int main(){
	scanf("%d",&N);
	while(N--){
		scanf("%s",input);
		int len = strlen(input);
		stack<char> st;
		
		for (int i = 0; i < len; i++){
			
			if (!st.empty() && st.top() == input[i]){
				st.pop();
			}
			else{
				st.push(input[i]);
			}
		}
		if (st.empty()){
			cnt++;
		}
		
	}
	printf("%d",cnt);
    return 0;
}

