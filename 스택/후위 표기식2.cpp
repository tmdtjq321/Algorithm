#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;
char input[105];
int num[27];
int visit[27];
int N, ecnt;
stack<double> ex;

int main() {
    scanf("%d",&N);
    scanf("%s",input);
    for (int i = 0; i < N; i++){
    	scanf("%d",&num[i]);
	}
	int line = strlen(input);
	for (int i = 0; i < line; i++){
		if (input[i] >= 65 && input[i] <= 90){
			if (visit[input[i]-'A'] == 0){
				visit[input[i]-'A'] = num[ecnt];
				ex.push((double)num[ecnt]);
				ecnt++;
			}
			else{
				ex.push((double)visit[input[i]-'A']);
			}
		}
		else{
			if (input[i] == '+'){
				double e1, e2;
				e2 = ex.top();
				ex.pop();
				e1 = ex.top();
				ex.pop();
				double sum = e1 + e2;
				ex.push(sum);
			}
			else if (input[i] == '-'){
				double e1, e2;
				e2 = ex.top();
				ex.pop();
				e1 = ex.top();
				ex.pop();
				double sum = e1 - e2;
				ex.push(sum);
			}
			else if (input[i] == '*'){
				double e1, e2;
				e2 = ex.top();
				ex.pop();
				e1 = ex.top();
				ex.pop();
				double sum = e1 * e2;
				ex.push(sum);
			}
			else if (input[i] == '/'){
				double e1, e2;
				e2 = ex.top();
				ex.pop();
				e1 = ex.top();
				ex.pop();
				double sum = e1 / e2;
				ex.push(sum);
			}
		}
	}
	printf("%.2f", ex.top());
    return 0;
}
