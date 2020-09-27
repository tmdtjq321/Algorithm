#include <stdio.h>
#include<algorithm>
using namespace std;
int num[500005];
int res[500005] = {0};
bool isit = false;

bool search(int num[], int s, int e, int t){
	
	while(s<=e){
		int mid = (s+e)/ 2;
		if (num[mid] == t){
			return true;
		}
		else if (num[mid] < t){
			s = mid + 1;
		}
		else{
			e = mid - 1;
		}
	}
	return false;
}
int main(){
	int n, m;
  	int t;
  	scanf("%d", &n);
  	int s = 0;
	int e = n;
	for (int i = 0; i < n; i++){
		scanf("%d", &num[i]);
	}
	std::sort(num,num+n);
  	scanf("%d", &m);
  	for (int i =0; i < m; i++){
  		scanf("%d", &t);
		isit = search(num,s,e,t);
		if (isit){
			printf("1");
		}
		else{
			printf("0");
		}
		printf("\n");
		
    }
   	

   return 0;
}

