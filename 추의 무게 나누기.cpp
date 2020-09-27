#include <stdio.h>

int main(){
	int N;
	printf("원하는 그램을 입력하세요. : ");
	scanf("%d", &N);
	int two_count=0, three_count=0, five_count=0;
	int count = 0;
	for (int i = 0; i < 11; i++){
		for (int j = 0; j < 11; j++){
			if ((N - (2 * i + 3 * j)) >= 0 && (N - (2 * i + 3 * j)) % 5 == 0 && (N - (2 * i + 3 * j)) / 5 < 11){
				count++;
				two_count = i;
				three_count = j;
				five_count = (N - (2 * i + 3 * j)) / 5;
				printf("추의 개수 : %d %d %d\n",two_count,three_count,five_count);
			}
		}
	}
	printf("총 개수 : %d",count);
	return 0;
}

