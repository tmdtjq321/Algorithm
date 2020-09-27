#include <stdio.h>
#include <string.h>

int main()
{
	int N;
	int money[] = {50000, 10000, 5000, 1000, 500, 100, 50, 10};
	printf("금액을 입력하세요=? ");
	scanf("%d", &N);
	if (N % 10 >= 5)
	{
		N = ((N / 10) + 1) * 10;
	}
	else
		N -= N % 10;

	for (int i = 0; i < 8; i++)
	{
		printf("%d = %d\n", money[i], N / money[i]);
		N %= money[i];
	}

	return 0;
}
