#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;
char input[100002];
int ans, scnt;
int cnt;
stack<int> S;

int main() {
    scanf("%s",input);
	int line = strlen(input);
	S.push(0);
	for (int i = 0; i < line; i++){
		if (input[i] == '('){
			S.push(S.top()+1);
		}
		else{
			if (input[i-1] == '('){		// 래이저 
				S.pop();
				ans += S.top(); 		// 잘린 막대수 
			}
			else{		// 막대  
				S.pop();
				cnt++;
			}
		}
	}
	
	printf("%d",ans+cnt);
    return 0;
}
