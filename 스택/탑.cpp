#include<stdio.h>
#include<algorithm>
#include<stack> 
using namespace std;
int N, cnt;
int input[500002];
int res[500002];
stack<pair<int,int>> st;

int main(){
	scanf("%d",&N);
	
	for (int i = 0; i < N; i++){
		scanf("%d",&input[i]);
	}
	
	for (int i = 0; i < N; i++){
		while (!st.empty() && st.top().first < input[i]){
			st.pop();
		}
		if (st.empty()){
			res[i] = 0;
		}
		else{
			res[i] = st.top().second;
		}
		st.push({input[i],i+1});
	}
	
	for (int i = 0; i < N; i++){
		printf("%d ",res[i]);
	}
    return 0;
}
