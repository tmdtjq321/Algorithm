#include<stdio.h>
#include<algorithm>
#include<stack> 
#include<string.h>
using namespace std;
int N, P, cnt;

stack<int> v[8];

int main(){
	scanf("%d%d",&N,&P);
	for (int i = 0; i < N; i++){
		int l, m;
		scanf("%d%d",&l,&m);
				
		if (!v[l].empty()) {
			if (v[l].top() > m){
				while(!v[l].empty() && v[l].top() > m){
					v[l].pop();
					cnt++;
				}
				if (!v[l].empty() && v[l].top() == m){
					continue;
				}
				v[l].push(m);
				cnt++;
			}
			else if (v[l].top() == m){
				continue;
			}
			else{
				v[l].push(m);
				cnt++;
			}
			
		}
		else{
			v[l].push(m);
			cnt++;
		}
		
		
		printf("cnt %d\n",cnt);
	}
	
	
	printf("%d",cnt);
    return 0;
}

