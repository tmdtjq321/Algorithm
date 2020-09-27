#include <stdio.h>

int main(){
	int A, B, V;
	scanf("%d %d %d", &A, &B, &V);
	int s = 1;
	int e = V;
	int speed = A - B;
	int arrive, m;
	while(s <= e){
		int mid = (s + e) / 2;
		arrive = mid * speed + B; 	// °Å¸®  
		if (arrive >= V){
			m = mid;
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}
	printf("%d", m);
   	return 0;
}


