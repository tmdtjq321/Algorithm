#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;
int N;
char input[52];

int main() {
    scanf("%d",&N);
    while(N--){
    	stack<char> s;
    	scanf("%s",input);
    	for (int i = 0; i < strlen(input); i++){
    		if (input[i] == '('){
    			s.push(i);
			}
			if (input[i] == ')'){
				if (s.empty()){
					printf("NO\n");
					while(!s.empty()){
						s.pop();
					}
					break;
				}
				else{
					s.pop();
				}
			}
			if (i == strlen(input) - 1 && s.empty()){
				printf("YES\n");
			}
			else if (i == strlen(input) - 1 && !s.empty()){
				printf("NO\n");
			}
		}
		while(!s.empty()){
			s.pop();
		}
	}
   	
    return 0;
}
