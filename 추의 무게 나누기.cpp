#include <stdio.h>

int main(){
	int N;
	printf("���ϴ� �׷��� �Է��ϼ���. : ");
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
				printf("���� ���� : %d %d %d\n",two_count,three_count,five_count);
			}
		}
	}
	printf("�� ���� : %d",count);
	return 0;
}

