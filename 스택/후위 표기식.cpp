#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;
char input[105];
char res[105];
int rcnt;
stack<char> st;

int main() {
    scanf("%s",input);
    int line = strlen(input);
    for (int i = 0; i< line; i++){
    	if (65 <= input[i] && input[i] <= 90){
    		res[rcnt] = input[i];
    		rcnt++;
		}	
		if(input[i] == '('){
			st.push(input[i]);	
		}
		if (input[i] == '*' || input[i] == '/'){
			while(!st.empty() && (st.top() == '*' || st.top() == '/')){		// �켱������ ���Ƽ� �����ڰ� *, / �̸� ��� 
				res[rcnt] = st.top();
				rcnt++;
				st.pop();
			}
			st.push(input[i]);
		}
		if (input[i] == '+' || input[i] == '-'){
			while(!st.empty() && (st.top() == '+' || st.top() == '-'	// �켱������ ���Ƽ� �����ڰ� �̹� ������ ��� 
											|| st.top() == '*' || st.top() == '/')){
				res[rcnt] = st.top();
				rcnt++;
				st.pop();
			}
			st.push(input[i]);
		}
		if (input[i] == ')'){
			while(!st.empty() && st.top() != '('){		// ��ȣ ���� ���� �� ���	
				res[rcnt] = st.top();
				rcnt++;
				st.pop();
			}
			if (st.top() == '('){
				st.pop();
			}
		}
	}	
	while(!st.empty()){
		res[rcnt] = st.top();
		rcnt++;
		st.pop();
	}
	for (int i = 0; i < rcnt; i++){
		printf("%c",res[i]);
	}
    return 0;
}
